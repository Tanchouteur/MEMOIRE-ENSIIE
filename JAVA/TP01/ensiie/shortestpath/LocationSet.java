package ensiie.shortestpath;

public class LocationSet {
    private Location[] locations;
    private int size;
    private int capacity;

    public LocationSet() {
        this.capacity = 0;
        locations = null;
        size = 0;
    }

    public void addLocation(Location location) {
        if (size < capacity) {
            locations[size] = location;
            size++;
        } else {
            capacity += 2;
            Location[] newLocations = new Location[capacity];
            if (locations != null) {
                System.arraycopy(locations, 0, newLocations, 0, size);
            }
            locations = newLocations;
            locations[size] = location;
            size++;
        }
    }

    public Location removeMin(){
        if (size == 0) {
            return null;
        }
        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (locations[i].getDistance() < locations[minIndex].getDistance()) {
                minIndex = i;
            }
        }
        Location minLocation = locations[minIndex];
        locations[minIndex] = locations[size - 1];
        locations[size - 1] = null;
        size--;
        return minLocation;
    }

    public Location get(int index) {
        if (index >= 0 && index < size) {
            return locations[index];
        } else {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
    }

    public int size() {
        return size;
    }

    public int capacity() {
        return capacity;
    }
}
