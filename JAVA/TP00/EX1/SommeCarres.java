public class SommeCarres{
			public int sommeCarres(int n){
				int s = 0;
				for(int i = 1; i <= n; i++){
					s += i * i;
				}
				return s;
			}

			public static void main( String [] args){

                SommeCarres s = new SommeCarres();
				System.out.println("Somme des carres de 1 a 3 : " +  s.sommeCarres(3));
				System.out.println("Somme des carres de 1 a 3 : " +  s.sommeCarres(10));
				System.out.println("Somme des carres de 1 a 3 : " +  s.sommeCarres(5));
			}
		}
