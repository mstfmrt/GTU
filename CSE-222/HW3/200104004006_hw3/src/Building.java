public class Building {
    private int position;
    private int height;
    private int length;
    private String owner;

    /**
     * default constructor
     */
    public Building() {
        this.position = 0;
        this.height = 0;
        this.length = 0;
        this.owner = "";
    }

    /**
     * constructor with all properties
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of the building
     */
    public Building(int position, int height, int length, String owner) {
        this.position = position;
        this.height = height;
        this.length = length;
        this.owner = owner;
    }

    /**
     * building constructor for position and length
     * @param position refers to the position at the street
     * @param length refers to the length of the building
     */
    public Building(int position, int length){
        this.position = position;
        this.height = 1;
        this.length = length;
        this.owner = "government";
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public int getPosition() {
        return position;
    }

    public int getHeight() {
        return height;
    }

    public int getLength() {
        return length;
    }

    public String getOwner() {
        return owner;
    }
}
