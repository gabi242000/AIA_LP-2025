package com.example.demo.client;
import com.example.demo.Message;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class Utilities {
    public static final Color TransparentColor = new Color(0, 0, 0, 0);
    public static final Color PrimaryColor = Color.decode("#19331c");
    public static final Color SecondaryColor = Color.decode("#484444");
    public static final Color Text_Color = Color.WHITE;
    public static final Color Label_Color = Color.BLACK;

    public static EmptyBorder addPadding(int top, int left, int bottom, int right) {
        return new EmptyBorder(top, left, bottom, right);
    }
}
