package service;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import model.Recipe;

import java.io.IOException;
import java.util.List;

public class RecipeService {
    private final ObservableList<Recipe> recipes = FXCollections.observableArrayList();
    private final StorageService storage = new StorageService("recipe-manager.recipes");

    public RecipeService() {
        // incearcă sa incarce din fisier
        try {
            List<Recipe> loaded = storage.load();
            if (!loaded.isEmpty()) {
                recipes.addAll(loaded);
                return;
            }
        } catch (IOException ignored) {}

        // fallback: demo (retetele preinstalate)
        Recipe r1 = new Recipe("Clătite pufoase", "Desert", 20, 2);
        r1.getIngredients().addAll("2 ouă", "250 ml lapte", "150 g făină", "1 lingură zahăr");
        r1.getSteps().addAll("Amesteci ingredientele.", "Coci clătitele pe tigaie încinsă.");

        Recipe r2 = new Recipe("Salată verde cu brânză", "Cină", 10, 1);
        r2.getIngredients().addAll("salată", "brânză feta", "ulei de măsline", "lămâie");
        r2.getSteps().addAll("Speli salata.", "Amesteci tot și asezonezi.");

        recipes.addAll(r1, r2);
        try {
            saveToDisk();
        } catch (IOException ignored) {}

    }

    public ObservableList<Recipe> getRecipes() {
        return recipes;
    }

    public void addRecipe(Recipe r) {
        recipes.add(r);
    }

    public void deleteRecipe(Recipe r) {
        recipes.remove(r);
    }

    public void updateRecipe(Recipe target, Recipe edited) {
        if (target == null || edited == null) return;

        target.setTitle(edited.getTitle());
        target.setCategory(edited.getCategory());
        target.setMinutes(edited.getMinutes());
        target.setServings(edited.getServings());

        target.getIngredients().setAll(edited.getIngredients());
        target.getSteps().setAll(edited.getSteps());
    }


    public void saveToDisk() throws IOException {
        storage.save(recipes);
    }

    public void importFromDisk(java.nio.file.Path path, boolean merge) throws IOException {
        List<Recipe> imported = storage.loadFrom(path);
        if (!merge) recipes.clear();
        recipes.addAll(imported);
    }

    public java.nio.file.Path getDefaultFilePath() {
        return storage.getFilePath();
    }
}

