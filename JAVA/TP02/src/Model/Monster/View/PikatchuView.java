package src.Model.Monster.View;

import src.Model.Monster.Pikatchu;

public class PikatchuView extends MonsterView{

    private Pikatchu pikatchu;
    public PikatchuView(Pikatchu pikatchu) {
        this.pikatchu = pikatchu;
    }

    @Override
    protected void paintComponent(java.awt.Graphics g) {
        // Dessiner le Pikatchu a la position du pikatchu
        int x = (int) pikatchu.getPosition()[0];
        int y = (int) pikatchu.getPosition()[1];
        g.setColor(java.awt.Color.YELLOW);
        g.fillOval(x, y, 50, 50); // Dessiner un cercle
        g.setColor(java.awt.Color.BLACK);
        g.drawOval(x, y, 50, 50); // Contour du cercle
        g.drawString("Pikatchu", x + 10, y + 25); // Nom du Pikatchu

    }
}
