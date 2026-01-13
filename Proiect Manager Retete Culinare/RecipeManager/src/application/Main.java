package application;

import controller.RecipeController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import javafx.scene.image.Image;


public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/application/recipemanagerFx.fxml"));
            BorderPane root = loader.load();

            Scene scene = new Scene(root, 900, 600);

            scene.getStylesheets().add(getClass().getResource("/application/base.css").toExternalForm());
            scene.getStylesheets().add(getClass().getResource("/application/theme-pink.css").toExternalForm());

            // controller pentru autosave
            RecipeController controller = loader.getController();

            primaryStage.setTitle("Recipe Manager");
            primaryStage.setScene(scene);

            primaryStage.setOnCloseRequest(ev -> {
                try {
                    controller.autoSaveOnExit(); 
                } catch (Exception ignored) {}
            });
            
            primaryStage.getIcons().add(
            	    new Image(getClass().getResourceAsStream("/application/icons/app.png"))
            	);


            primaryStage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
