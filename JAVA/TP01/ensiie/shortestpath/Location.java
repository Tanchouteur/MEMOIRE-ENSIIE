package ensiie.shortestpath;

import java.util.ArrayList;
import java.util.Collections;

public class Location {
    private final String _name;
    private final double _latitude, _longitude;
    private final ArrayList<Location> neighbors;
    private double distance;
    private Location from;

    public Location(String name, double latitude, double longitude) {
        _name = name;
        _latitude = Main.convertToRadians(latitude);
        _longitude = Main.convertToRadians(longitude);
        neighbors = new ArrayList<>();
        distance = Double.POSITIVE_INFINITY;
    }

    //Methode pour trouver le plus court chemin de la ville courante a la ville finale
    void findShortestPathTo(Location city){
        for (Location neighbor : neighbors) {
            double newDistance = getDistanceToCity(neighbor) + neighbor.getDistance();
            if (newDistance < distance) {
                distance = newDistance;
                from = neighbor;
            }
        }
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

    public double getDistance() {
        return distance;
    }

    public void setDistance(double distance) {
        this.distance = distance;
    }

    public ArrayList<Location> getNeighbors() {
        return neighbors;
    }

    public void addNeighbor(Location neighbor) {
        neighbors.add(neighbor);
    }

    public void setNeighbors(Location... neighbors) {
        Collections.addAll(this.neighbors, neighbors);
    }

    @Override
    public String toString() {
        return _name + " (" + _latitude + ", " + _longitude + ")";
    }
}
