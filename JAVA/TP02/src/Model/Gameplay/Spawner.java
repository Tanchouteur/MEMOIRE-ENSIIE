package src.Model.Gameplay;

import src.Model.Army;
import src.Model.Monster.Pikatchu;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Spawner {
    private final Set<int[]> spawnPoints;

    public Spawner(int sizeOfSpawnPoint){// Random sapwn point on screen
        Random rand = new Random();
        this.spawnPoints = new HashSet<>();
        while(this.spawnPoints.size() < sizeOfSpawnPoint){
            int x = rand.nextInt(800); // Assuming screen width is 800
            int y = rand.nextInt(600); // Assuming screen height is 600
            this.spawnPoints.add(new int[]{x, y});
        }

    }

    public Set<int[]> getSpawnPoints() {
        return spawnPoints;
    }

    public int spawnPointCount(){
        return this.spawnPoints.size();
    }

    public void spawn(Army army){
        for(int[] point : this.spawnPoints){
            army.addMonster(new Pikatchu(point[0], point[1]));
        }
    }
}
