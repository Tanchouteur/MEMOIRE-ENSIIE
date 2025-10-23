package src.Model;

public class Character {
    private final String name;
    private int health;
    private final double[] position;

    public Character(String name, int health, double x, double y) {
        this.name = name;
        this.health = health;
        this.position = new double[]{x, y};
    }

    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public double[] getPosition() {
        return position;
    }

    public void move(double deltaX, double deltaY) {
        this.position[0] += deltaX;
        this.position[1] += deltaY;
    }

    public void takeDamage(int damage) {
        this.health -= damage;
        if (this.health < 0) {
            this.health = 0;
        }
    }


}
