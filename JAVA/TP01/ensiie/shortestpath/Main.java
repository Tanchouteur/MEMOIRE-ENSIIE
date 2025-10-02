package ensiie.shortestpath;

public class Main {
    public static void main(String[] args) {
        Location evry = new Location("Evry", 48.629828, 2.441781999999989);
        Location paris = new Location("Paris",48.85661400000001, 2.352221900000017);
        Location lemans = new Location ("Le Mans", 48.00611000000001, 0.1995560000000296);
        Location orleans = new Location ("Orleans", 47.902964, 1.9092510000000402);
        Location angers = new Location ("Angers", 47.478419, -0.5631660000000238);
        Location tours = new Location ("Tours", 47.39414399999999, 0.6848400000000083);
        Location bourges = new Location ("Bourges", 47.081012, 2.398781999999983d);
        Location poitiers = new Location ("Poitiers", 46.58022400000001, 0.34037499999999454);
        Location limoges = new Location ("Limoges", 45.83361900000001, 1.2611050000000432);
        Location angouleme = new Location ("Angouleme", 45.648377, 0.15623690000006718);
        Location bordeaux = new Location ("Bordeaux", 44.837789,-0.5791799999999512);
        Location agen = new Location ("Agen", 44.203142, 0.6163629999999785);
        Location toulouse = new Location ("Toulouse", 43.604652, 1.4442090000000007);
        Location bayonne = new Location ("Bayonne", 43.492949, -1.4748409999999694);
        Location pau = new Location ("Pau", 43.2951, -0.3707970000000387);
        Location sansebestian = new Location ("San Sebastian", 43.318334,-1.9812312999999904);
        Location pampelune = new Location ("Pampelune", 42.812526,-1.645774500000016);
        Location bilbao = new Location ("Bilbao", 43.2630126, -2.9349852000000283);

    }

    public static double convertToRadians(double degrees) {
        return degrees * Math.PI / 180.0;
    }


}
