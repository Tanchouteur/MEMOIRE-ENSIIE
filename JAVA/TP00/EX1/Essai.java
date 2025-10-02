public class Essai
{
	public int milieu;
	public int largeur;

	Essai() {
	}

	Essai(int i) {
		milieu = i;
	}

	Essai(int a, int b)
	{
		this(a); // appel au constructeur Essai(int) et effectuera : milieu = a
		largeur=b;
	}


	public static void main (String[] args)
	{
		Essai e1 = new Essai();
		Essai e2 = new Essai(2);
		Essai e3 = new Essai(2,4);

		System.out.println(e1.milieu + " , " + e1.largeur);
		System.out.println(e2.milieu + " , " + e2.largeur);
		System.out.println(e3.milieu + " , " + e3.largeur);
	}
}
