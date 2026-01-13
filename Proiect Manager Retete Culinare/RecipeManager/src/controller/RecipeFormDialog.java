package controller;

import javafx.geometry.Insets;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import model.Recipe;

import java.util.Arrays;
import java.util.stream.Collectors;

public class RecipeFormDialog {

    public static Recipe showDialog(Recipe existing) {
        Dialog<Recipe> dialog = new Dialog<>();
        dialog.setTitle(existing == null ? "Adaugă rețetă" : "Editează rețetă");
        dialog.getDialogPane().getButtonTypes().addAll(ButtonType.OK, ButtonType.CANCEL);

        TextField title = new TextField(existing == null ? "" : existing.getTitle());
        TextField category = new TextField(existing == null ? "" : existing.getCategory());
        TextField minutes = new TextField(existing == null ? "10" : String.valueOf(existing.getMinutes()));
        TextField servings = new TextField(existing == null ? "1" : String.valueOf(existing.getServings()));

        TextArea ingredients = new TextArea(existing == null ? "" : String.join("\n", existing.getIngredients()));
        ingredients.setPromptText("1 linie = 1 ingredient");

        TextArea steps = new TextArea(existing == null ? "" : String.join("\n", existing.getSteps()));
        steps.setPromptText("1 linie = 1 pas");

        ingredients.setPrefRowCount(8);
        steps.setPrefRowCount(10);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(12));

        grid.addRow(0, new Label("Titlu"), title);
        grid.addRow(1, new Label("Categorie"), category);
        grid.addRow(2, new Label("Timp (min)"), minutes);
        grid.addRow(3, new Label("Porții"), servings);
        grid.add(new Label("Ingrediente"), 0, 4);
        grid.add(ingredients, 1, 4);
        grid.add(new Label("Pași"), 0, 5);
        grid.add(steps, 1, 5);

        dialog.getDialogPane().setContent(grid);

        // validare simpla
        Button okBtn = (Button) dialog.getDialogPane().lookupButton(ButtonType.OK);
        okBtn.disableProperty().bind(title.textProperty().isEmpty().or(category.textProperty().isEmpty()));

        dialog.setResultConverter(btn -> {
            if (btn != ButtonType.OK) return null;

            int m = parseInt(minutes.getText());
            int s = parseInt(servings.getText());

            Recipe r = new Recipe(
                    title.getText().trim(),
                    category.getText().trim(),
                    Math.max(0, m),
                    Math.max(1, s)
            );

            r.getIngredients().setAll(splitLines(ingredients.getText()));
            r.getSteps().setAll(splitLines(steps.getText()));
            return r;
        });

        return dialog.showAndWait().orElse(null);
    }

    private static int parseInt(String t) {
        try { return Integer.parseInt(t.trim()); } catch (Exception e) { return 0; }
    }

    private static java.util.List<String> splitLines(String text) {
        if (text == null || text.trim().isEmpty()) return java.util.List.of();
        return Arrays.stream(text.split("\\R"))
                .map(String::trim)
                .filter(s -> !s.isEmpty())
                .collect(Collectors.toList());
    }
}
