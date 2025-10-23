package src.Model;

import src.Model.Monster.Monster;

import java.util.LinkedList;

public class Army {
    private final LinkedList<Monster> monsters;

    public Army() {
        this.monsters = new LinkedList<Monster>();
    }

    public void addMonster(Monster monster) {
        this.monsters.add(monster);
    }

    public void removeMonster(Monster monster) {
        this.monsters.remove(monster);
    }

    public LinkedList<Monster> getMonsters() {
        return monsters;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Army{\n");
        if (monsters.isEmpty()) {
            sb.append("  (no monsters)\n");
            sb.append("}");
            return sb.toString();
        }

        int idxWidth = String.valueOf(monsters.size()).length();
        int typeWidth = "Type".length();
        int descWidth = "Description".length();

        for (Monster m : monsters) {
            String type = m.getClass().getSimpleName();
            String desc = m.toString();
            if (type.length() > typeWidth) typeWidth = type.length();
            if (desc.length() > descWidth) descWidth = desc.length();
        }

        String fmt = "  %-" + idxWidth + "s | %-" + typeWidth + "s | %-" + descWidth + "s%n";
        String sep = "  " + "-".repeat(idxWidth) + "-+-" + "-".repeat(typeWidth) + "-+-" + "-".repeat(descWidth) + "\n";

        sb.append(String.format(fmt, "#", "Type", "Description"));
        sb.append(sep);

        int i = 1;
        for (Monster m : monsters) {
            sb.append(String.format(fmt, i++, m.getClass().getSimpleName(), m.toString()));
        }

        sb.append("}");
        return sb.toString();
    }

    public void move() {

    }
}
