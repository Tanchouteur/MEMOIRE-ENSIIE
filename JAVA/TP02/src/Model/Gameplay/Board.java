package src.Model.Gameplay;

import src.Model.Army;

public class Board {
    private final Army army;
    private final Level level;
    private final Spawner spawner;

    public Board() {
        this.army = new Army();
        this.level = new Level(1, 10);
        this.spawner = new Spawner(5);
    }

    public Army getArmy() {
        return army;
    }

    public Level getLevel() {
        return level;
    }

    public Spawner getSpawner() {
        return spawner;
    }

    public void update() {
        army.move();
    }
}
