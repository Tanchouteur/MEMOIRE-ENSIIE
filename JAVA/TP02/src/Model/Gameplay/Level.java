package src.Model.Gameplay;

public class Level {
    private final int levelNumber;
    private final int totalMonsterCount;
    private int spawnedMonsterCount = 0;
    private int deadMonsterCount = 0;

    public Level(int levelNumber, int totalMonsterCount) {
        this.levelNumber = levelNumber;
        this.totalMonsterCount = totalMonsterCount;
    }

    public int getLevelNumber() {
        return levelNumber;
    }

    public int getTotalMonsterCount() {
        return totalMonsterCount;
    }

    public int getSpawnedMonsterCount() {
        return spawnedMonsterCount;
    }

    public int getDeadMonsterCount() {
        return deadMonsterCount;
    }
}
