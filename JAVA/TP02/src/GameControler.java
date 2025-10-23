package src;

import src.Model.Gameplay.Board;
import src.View.Window;

public class GameControler implements Runnable {
    private Window window;
    private Board board;
    private boolean running;
    private final int FPS = 60; // images par seconde

    public GameControler() {
        this.board = new Board();
        this.window = new Window(this.board);
    }

    public void start() {
        running = true;
        Thread gameThread = new Thread(this);
        gameThread.start();
    }

    @Override
    public void run() {
        // Durée d'une frame en nanosecondes
        double timePerFrame = 1_000_000_000.0 / FPS;
        long lastTime = System.nanoTime();
        double delta = 0;

        while (running) {
            long currentTime = System.nanoTime();
            delta += (currentTime - lastTime) / timePerFrame;
            lastTime = currentTime;

            if (delta >= 1) {
                update(); // logique du jeu
                render(); // affichage
                delta--;
            }
        }
    }

    private void update() {
        // TODO: logique du jeu (déplacements, collisions, etc.)
        board.update();
    }

    private void render() {
        // TODO: affichage
        window.repaint();
    }

    public void stop() {
        running = false;
    }
}
