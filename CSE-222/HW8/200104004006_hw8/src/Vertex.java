import java.util.HashMap;

public class Vertex {

    int index;
    String label;
    double weight;
    HashMap<String, String> map;

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public String getLabel() {
        return label;
    }

    public void setLabel(String label) {
        this.label = label;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public HashMap<String, String> getMap() {
        return map;
    }

    public void setMap(String key, String value) {
        HashMap<String, String> nmap = new HashMap<String, String>();
        nmap.put(key,value);
        this.map = nmap;
    }

    public Vertex(String label, double weight) {
        this.label = label;
        this.weight = weight;
    }
}
