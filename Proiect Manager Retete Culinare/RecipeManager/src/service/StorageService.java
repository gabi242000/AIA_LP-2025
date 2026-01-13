package service;

import model.Recipe;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

/**
 * StorageService (cross-platform + fallback profi)
 *
 * Salveaza intr-un folder “user data” per OS:
 *  - Windows: %APPDATA%/RecipeManager/
 *  - macOS:   ~/Library/Application Support/RecipeManager/
 *  - Linux:   $XDG_CONFIG_HOME/RecipeManager/  sau ~/.config/RecipeManager/
 *
 * Fallback final: ~/RecipeManager/
 *
 * Fișierul este text (UTF-8), format:
 * ===RECIPE=== ... ===END===
 */
public class StorageService {

    private static final String APP_DIR_NAME = "RecipeManager";
    private final Path filePath;

    public StorageService(String filename) {
        Path dir = resolveAppDataDir();
        try {
            Files.createDirectories(dir);
        } catch (Exception e) {
            // fallback final
            dir = Paths.get(System.getProperty("user.home"), APP_DIR_NAME);
            try { Files.createDirectories(dir); } catch (Exception ignored) {}
        }
        this.filePath = dir.resolve(filename);
    }

    public Path getFilePath() {
        return filePath;
    }

    // -------------------------
    // Public API
    // -------------------------

    public void save(List<Recipe> recipes) throws IOException {
        Files.createDirectories(filePath.getParent());

        try (BufferedWriter w = Files.newBufferedWriter(filePath, StandardCharsets.UTF_8,
                StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING)) {

            for (Recipe r : recipes) {
                w.write("===RECIPE===\n");
                w.write("id=" + safe(r.getId()) + "\n");
                w.write("title=" + safe(r.getTitle()) + "\n");
                w.write("category=" + safe(r.getCategory()) + "\n");
                w.write("minutes=" + r.getMinutes() + "\n");
                w.write("servings=" + r.getServings() + "\n");

                w.write("ingredients:\n");
                for (String ing : r.getIngredients()) w.write(safe(ing) + "\n");
                w.write("---\n");

                w.write("steps:\n");
                for (String s : r.getSteps()) w.write(safe(s) + "\n");

                w.write("===END===\n");
            }
        }
    }

    public List<Recipe> load() throws IOException {
        return loadFrom(filePath);
    }

    /** Import: încarcă rețete dintr-un fișier extern (Desktop/Downloads etc.). */
    public List<Recipe> loadFrom(Path path) throws IOException {
        if (path == null || !Files.exists(path)) return new ArrayList<>();

        List<String> lines = Files.readAllLines(path, StandardCharsets.UTF_8);
        List<Recipe> out = new ArrayList<>();

        String id = null, title = null, category = null;
        int minutes = 0, servings = 1;
        List<String> ingredients = new ArrayList<>();
        List<String> steps = new ArrayList<>();

        boolean inRecipe = false;
        boolean inIngredients = false;
        boolean inSteps = false;

        for (String raw : lines) {
            String line = raw == null ? "" : raw.trim();

            if (line.equals("===RECIPE===")) {
                inRecipe = true;
                id = null; title = null; category = null;
                minutes = 0; servings = 1;
                ingredients = new ArrayList<>();
                steps = new ArrayList<>();
                inIngredients = false;
                inSteps = false;
                continue;
            }

            if (!inRecipe) continue;

            if (line.equals("===END===")) {
                if (title != null && !title.isBlank() && category != null && !category.isBlank()) {
                    String rid = (id == null || id.isBlank()) ? UUID.randomUUID().toString() : id;
                    Recipe r = new Recipe(rid, title, category, minutes, servings);
                    r.getIngredients().addAll(ingredients);
                    r.getSteps().addAll(steps);
                    out.add(r);
                }
                inRecipe = false;
                inIngredients = false;
                inSteps = false;
                continue;
            }

            if (line.equals("ingredients:")) { inIngredients = true; inSteps = false; continue; }
            if (line.equals("steps:")) { inSteps = true; inIngredients = false; continue; }
            if (line.equals("---")) { inIngredients = false; continue; }

            if (inIngredients) { if (!line.isEmpty()) ingredients.add(line); continue; }
            if (inSteps) { if (!line.isEmpty()) steps.add(line); continue; }

            int idx = line.indexOf('=');
            if (idx > 0) {
                String k = line.substring(0, idx).trim();
                String v = line.substring(idx + 1).trim();

                switch (k) {
                    case "id" -> id = v;
                    case "title" -> title = v;
                    case "category" -> category = v;
                    case "minutes" -> minutes = parseIntSafe(v, 0);
                    case "servings" -> servings = parseIntSafe(v, 1);
                }
            }
        }

        return out;
    }

    // -------------------------
    // Helpers
    // -------------------------

    private static Path resolveAppDataDir() {
        String os = System.getProperty("os.name", "").toLowerCase();
        String home = System.getProperty("user.home");

        // Windows: %APPDATA%
        if (os.contains("win")) {
            String appData = System.getenv("APPDATA"); // Roaming
            if (appData != null && !appData.isBlank()) {
                return Paths.get(appData, APP_DIR_NAME);
            }
            // fallback Windows
            return Paths.get(home, "AppData", "Roaming", APP_DIR_NAME);
        }

        // macOS: ~/Library/Application Support
        if (os.contains("mac")) {
            return Paths.get(home, "Library", "Application Support", APP_DIR_NAME);
        }

        // Linux/Unix: XDG_CONFIG_HOME sau ~/.config
        String xdg = System.getenv("XDG_CONFIG_HOME");
        if (xdg != null && !xdg.isBlank()) {
            return Paths.get(xdg, APP_DIR_NAME);
        }
        return Paths.get(home, ".config", APP_DIR_NAME);
    }

    private static int parseIntSafe(String s, int def) {
        try { return Integer.parseInt(s.trim()); } catch (Exception e) { return def; }
    }

    private static String safe(String s) {
        return s == null ? "" : s.replace("\r", " ").trim();
    }
}
