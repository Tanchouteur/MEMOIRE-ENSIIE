// public class Sommes1SurI {
// 		 public int sommes1SurI(int n, double d){
// 			double s = 0.0;
// 			if(n <= 0)
// 				return -1;
// 			for(int i = 1; i <= n; i++)
// 				s += 1/(double)i;
// 			if(s < d)
// 				return 1;
// 			else
// 				return 0;
// 		}
//
//
// 		public static void main( String [] args){
// 			Sommes1SurI s = new Sommes1SurI();
// 			System.out.println(30 + " " + 23.45 + " " + s.sommes1SurI(30, 23.45));
// 			System.out.println(-2 + " " +1000.0 + " " + s.sommes1SurI(-2, 1000.0));
// 			System.out.println(16 + " " + 2 +" " + s.sommes1SurI(16, 2));
// 			}
// 	}



	public class Sommes1SurI {
		public int sommes1SurI(int n, double d){
			double s = 0.0;
			if(n <= 0)
				return -1;
			for(int i = 1; i <= n; i++)
				s += 1/(double)i;
			if(s < d)
				return 1;
			else
				return 0;
		}

		public void compareSommes1SurI(int n, double d){
			System.out.println( n + " " + d + " " + sommes1SurI(n, d));
		}

		public static void main ( String [] args){
			Sommes1SurI s = new Sommes1SurI();
			s.compareSommes1SurI(30, 23.45);
			s.compareSommes1SurI(-2, 1000.0);
			s.compareSommes1SurI(16, 2);
		}
	}
