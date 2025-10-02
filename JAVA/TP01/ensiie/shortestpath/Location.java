package ensiie.shortestpath;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class Location {
    private final String _name;
    private final double _latitude, _longitude;
    private ArrayList<Location> neighbors;

    public Location(String name, double latitude, double longitude) {
        _name = name;
        _latitude = Main.convertToRadians(latitude);
        _longitude = Main.convertToRadians(longitude);
        neighbors = new ArrayList<Location>();
    }

    double getDistanceToCity(Location city){
        return 6378 * (Math.PI / 2 - Math.asin(Math.sin(city.getLatitude()) * Math.sin(this.getLatitude()) + Math.cos(city.getLongitude() - this.getLongitude()) * Math.cos (city.getLatitude()) * Math . cos (this.getLatitude())));
    }

    public String getName() {
        return _name;
    }
    public double getLatitude() {
        return _latitude;
    }
    public double getLongitude() {
        return _longitude;
    }

    public ArrayList<Location> getNeighbors() {
        return neighbors;
    }

    public void addNeighbor(Location neighbor) {
        neighbors.add(neighbor);
    }

    public void setNeighbors(ArrayList<Location> neighbors) {
        this.neighbors = neighbors;
    }

    @Override
    public String toString() {
        return _name + " (" + _latitude + ", " + _longitude + ")";
    }
}
