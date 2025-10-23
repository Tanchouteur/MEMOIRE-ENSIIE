package src.View;

import src.Model.Gameplay.Board;

import javax.swing.*;

public class Window extends JFrame {
    private Board board;

    public Window(String title, int width, int height) {
        this.setTitle(title);
        this.setSize(width, height);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setResizable(false);
        this.setVisible(true);
    }

    public Window(Board board) {
        this("Game Window", 800, 600);
        // Additional initialization with the board can be done here

        this.board = board;

        this.setRootPane(new GamePanel(this.board));
    }
}
