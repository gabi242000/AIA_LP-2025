package model;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.util.UUID;

public class Recipe {
    private final String id;

    private String title;
    private String category;
    private int minutes;
    private int servings;

    private final ObservableList<String> ingredients = FXCollections.observableArrayList();
    private final ObservableList<String> steps = FXCollections.observableArrayList();

    // pentru “add” normal
    public Recipe(String title, String category, int minutes, int servings) {
        this(UUID.randomUUID().toString(), title, category, minutes, servings);
    }

    // pentru “load” din fișier (cu id existent)
    public Recipe(String id, String title, String category, int minutes, int servings) {
        this.id = (id == null || id.isBlank()) ? UUID.randomUUID().toString() : id;
        this.title = title;
        this.category = category;
        this.minutes = minutes;
        this.servings = servings;
    }

    public String getId() { return id; }

    public String getTitle() { return title; }
    public void setTitle(String title) { this.title = title; }

    public String getCategory() { return category; }
    public void setCategory(String category) { this.category = category; }

    public int getMinutes() { return minutes; }
    public void setMinutes(int minutes) { this.minutes = minutes; }

    public int getServings() { return servings; }
    public void setServings(int servings) { this.servings = servings; }

    public ObservableList<String> getIngredients() { return ingredients; }
    public ObservableList<String> getSteps() { return steps; }

    @Override
    public String toString() {
        return title + " (" + category + ")";
    }
}

