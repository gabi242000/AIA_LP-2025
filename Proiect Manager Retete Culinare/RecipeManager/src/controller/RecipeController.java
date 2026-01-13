package controller;

import javafx.application.Platform;
import javafx.collections.transformation.FilteredList;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import model.Recipe;
import service.RecipeService;

import java.io.File;

public class RecipeController {

    @FXML private TextField searchField;
    
    @FXML private ComboBox<String> categoryFilter;

    
    @FXML private ComboBox<String> themeBox;

    @FXML private ListView<Recipe> recipeList;
    @FXML private Label titleLabel;
    @FXML private Label metaLabel;
    @FXML private ListView<String> ingredientsList;
    @FXML private ListView<String> stepsList;

    // din bottom:
    @FXML private Label statusLabel;

    // din top 
    @FXML private Button editBtn;
    @FXML private Button deleteBtn;

    private final RecipeService service = new RecipeService();
    private FilteredList<Recipe> filtered;

    @FXML
    public void initialize() {
        // 1) Data + filtered list
        filtered = new FilteredList<>(service.getRecipes(), r -> true);
        recipeList.setItems(filtered);

        // 2) Card-style list cell
        recipeList.setCellFactory(lv -> new ListCell<>() {
            private final Label title = new Label();
            private final Label sub = new Label();
            private final VBox textBox = new VBox(2, title, sub);
            private final HBox root = new HBox(textBox);

            {
                title.getStyleClass().add("h2");
                sub.setId("metaLabel");
                root.setSpacing(10);
                HBox.setHgrow(textBox, Priority.ALWAYS);
            }

            @Override
            protected void updateItem(Recipe item, boolean empty) {
                super.updateItem(item, empty);
                if (empty || item == null) {
                    setText(null);
                    setGraphic(null);
                } else {
                    title.setText(item.getTitle());
                    sub.setText(item.getCategory() + " • " + item.getMinutes() + " min • " + item.getServings() + " porții");
                    setGraphic(root);
                }
            }
        });

        // 3) Selection -> details + buttons
        recipeList.getSelectionModel().selectedItemProperty().addListener((obs, oldR, newR) -> {
            showRecipe(newR);
            updateButtons();
        });

        // 4) Theme dropdown
        themeBox.getItems().setAll("Pastel Roz", "Pastel Verde", "Pastel Mov");
        themeBox.getSelectionModel().select("Pastel Roz");

        Platform.runLater(() -> applyTheme(themeBox.getValue()));
        themeBox.valueProperty().addListener((obs, old, val) -> applyTheme(val));

        // 5) Category filter dropdown 
        if (categoryFilter != null) {
            categoryFilter.getItems().setAll("Toate", "Mic dejun", "Prânz", "Cină", "Desert", "Gustare");
            categoryFilter.getSelectionModel().select("Toate");
            categoryFilter.valueProperty().addListener((obs, old, val) -> applyFilters());
        }

        // 6) Search -> apply filters
        searchField.textProperty().addListener((obs, old, text) -> applyFilters());

        // 7) Select first / show empty
        if (!filtered.isEmpty()) {
            recipeList.getSelectionModel().select(0);
        } else {
            showRecipe(null);
        }

        updateStatus();
        updateButtons();
    }

    private void applyFilters() {
        final String t = (searchField.getText() == null) ? "" : searchField.getText().toLowerCase().trim();
        final String cat = (categoryFilter == null || categoryFilter.getValue() == null) ? "Toate" : categoryFilter.getValue();

        filtered.setPredicate(r -> {
            if (r == null) return false;

            // 1) category filter
            boolean catOk = cat.equals("Toate") ||
                    (r.getCategory() != null && r.getCategory().equalsIgnoreCase(cat));
            if (!catOk) return false;

            // 2) text search
            if (t.isEmpty()) return true;

            boolean matchTitle = safe(r.getTitle()).contains(t);
            boolean matchCat = safe(r.getCategory()).contains(t);
            boolean matchIng = r.getIngredients().stream().anyMatch(s -> safe(s).contains(t));
            boolean matchSteps = r.getSteps().stream().anyMatch(s -> safe(s).contains(t));

            return matchTitle || matchCat || matchIng || matchSteps;
        });

        // selection + details
        if (!filtered.isEmpty() && recipeList.getSelectionModel().getSelectedItem() == null) {
            recipeList.getSelectionModel().select(0);
        }
        if (filtered.isEmpty()) {
            showRecipe(null);
        }

        updateStatus();
        updateButtons();
    }


    // ---------------- ACTIONS ----------------

    @FXML
    private void onAdd() {
        Recipe created = RecipeFormDialog.showDialog(null);
        if (created == null) return;

        service.addRecipe(created);
        recipeList.getSelectionModel().select(created);
        recipeList.scrollTo(created);

        updateStatus();
        updateButtons();
    }

    @FXML
    private void onEdit() {
        Recipe selected = recipeList.getSelectionModel().getSelectedItem();
        if (selected == null) {
            alertWarn("Nu ai selectat nicio rețetă.");
            return;
        }

        Recipe edited = RecipeFormDialog.showDialog(selected);
        if (edited == null) return;

        service.updateRecipe(selected, edited);
        recipeList.refresh();
        showRecipe(selected);

        updateStatus();
        updateButtons();
    }

    @FXML
    private void onDelete() {
        Recipe selected = recipeList.getSelectionModel().getSelectedItem();
        if (selected == null) {
            alertWarn("Nu ai selectat nicio rețetă.");
            return;
        }

        Alert a = new Alert(Alert.AlertType.CONFIRMATION);
        a.setTitle("Confirmare");
        a.setHeaderText("Ștergi rețeta?");
        a.setContentText(selected.getTitle());

        if (a.showAndWait().orElse(ButtonType.CANCEL) == ButtonType.OK) {
            service.deleteRecipe(selected);

            if (!filtered.isEmpty()) recipeList.getSelectionModel().select(0);
            else showRecipe(null);

            updateStatus();
            updateButtons();
        }
    }

    @FXML
    private void onSave() {
        try {
            service.saveToDisk();
            alertInfo("Salvat!", "Fișier: " + service.getDefaultFilePath());
        } catch (Exception e) {
            alertWarn("Eroare la salvare: " + e.getMessage());
        }
    }

    @FXML
    private void onImport() {
        try {
            javafx.stage.FileChooser fc = new javafx.stage.FileChooser();
            fc.setTitle("Import rețete");
            fc.getExtensionFilters().addAll(
                    new javafx.stage.FileChooser.ExtensionFilter("Recipe files", "*.recipes", "*.txt"),
                    new javafx.stage.FileChooser.ExtensionFilter("All files", "*.*")
            );

            File f = fc.showOpenDialog(themeBox.getScene().getWindow());
            if (f == null) return;

            Alert mode = new Alert(Alert.AlertType.CONFIRMATION);
            mode.setTitle("Import");
            mode.setHeaderText("Cum importăm?");
            mode.setContentText("OK = adaugă peste rețetele existente (merge)\nCancel = înlocuiește lista complet");

            boolean merge = mode.showAndWait().orElse(ButtonType.CANCEL) == ButtonType.OK;

            service.importFromDisk(f.toPath(), merge);
            applyFilters(); // re-aplică filtrul curent după import

            if (!filtered.isEmpty()) recipeList.getSelectionModel().select(0);
            else showRecipe(null);

            updateStatus();
            updateButtons();
            alertInfo("Import făcut!", "Importat din: " + f.getAbsolutePath());
        } catch (Exception e) {
            alertWarn("Eroare la import: " + e.getMessage());
        }
    }

    // Autosave la închidere (chemat din Main)
    public void autoSaveOnExit() {
        try { service.saveToDisk(); } catch (Exception ignored) {}
    }

    // ---------------- HELPERS ----------------

    private void showRecipe(Recipe r) {
        if (r == null) {
            titleLabel.setText("Selectează o rețetă");
            metaLabel.setText("");

            // IMPORTANT: nu da clear() pe lista curentă, că poate fi lista unei rețete!
            ingredientsList.setItems(javafx.collections.FXCollections.observableArrayList());
            stepsList.setItems(javafx.collections.FXCollections.observableArrayList());
            return;
        }

        titleLabel.setText(r.getTitle());
        metaLabel.setText(r.getCategory() + " • " + r.getMinutes() + " min • " + r.getServings() + " porții");

        ingredientsList.setItems(r.getIngredients());
        stepsList.setItems(r.getSteps());
    }


    private void applyTheme(String selected) {
        Scene scene = (themeBox == null) ? null : themeBox.getScene();
        if (scene == null) return;

        String css = "/application/theme-pink.css";
        if ("Pastel Verde".equals(selected)) css = "/application/theme-green.css";
        if ("Pastel Mov".equals(selected)) css = "/application/theme-purple.css";

        // scoate vechea temă
        scene.getStylesheets().removeIf(s -> s.contains("theme-"));

        // evită duplicate
        String url = getClass().getResource(css).toExternalForm();
        if (!scene.getStylesheets().contains(url)) {
            scene.getStylesheets().add(url);
        }
    }

    private void updateStatus() {
        if (statusLabel != null) {
            statusLabel.setText((filtered == null ? 0 : filtered.size()) + " rețete");
        }
    }

    private void updateButtons() {
        Recipe selected = recipeList == null ? null : recipeList.getSelectionModel().getSelectedItem();
        boolean hasSelection = selected != null;

        if (editBtn != null) editBtn.setDisable(!hasSelection);
        if (deleteBtn != null) deleteBtn.setDisable(!hasSelection);
    }

    private static String safe(String s) {
        return s == null ? "" : s.toLowerCase();
    }

    private void alertWarn(String msg) {
        Alert a = new Alert(Alert.AlertType.WARNING);
        a.setTitle("Atenție");
        a.setHeaderText(null);
        a.setContentText(msg);
        a.showAndWait();
    }

    private void alertInfo(String title, String msg) {
        Alert a = new Alert(Alert.AlertType.INFORMATION);
        a.setTitle(title);
        a.setHeaderText(null);
        a.setContentText(msg);
        a.showAndWait();
    }
}
