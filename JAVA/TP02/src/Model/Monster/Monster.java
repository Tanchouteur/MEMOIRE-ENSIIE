package src.Model.Monster;

public abstract class Monster {
    private final String name;
    private int health;
    private double[] position;
    private int speed;

    public Monster(String name, int health, double x, double y) {
        this.name = name;
        this.health = health;
        this.position = new double[]{x, y};
        this.speed = 1;
    }

    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public void takeDamage(int damage) {
        this.health -= damage;
        if (this.health < 0) {
            this.health = 0;
        }
    }

    public double[] getPosition() {
        return position;
    }

    public int getSpeed() {
        return speed;
    }

    public void move(double deltaX, double deltaY) {
        this.position[0] += deltaX;
        this.position[1] += deltaY;
    }

    @Override
    public String toString() {
        return  "Monster{" + "  name='" + name + "',health=" + health + " }";
    }
}
