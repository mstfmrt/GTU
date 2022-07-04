public class House extends Building{
    private int numberofRooms;
    private String color;

    /**
     * default constructor for house
     */
    public House() {
        super();
    }

    /**
     * constructor for number of rooms
     * @param numberofRooms
     */
    public House(int numberofRooms) {
        super();
        this.numberofRooms = numberofRooms;
    }

    /**
     * constructor for color info
     * @param color
     */
    public House(String color) {
        super();
        this.color = color;
    }

    /**
     * constructor for number of room and color info
     * @param numberofRooms
     * @param color
     */
    public House(int numberofRooms, String color) {
        super();
        this.numberofRooms = numberofRooms;
        this.color = color;
    }

    /**
     * constructor with all information
     * @param position
     * @param height
     * @param length
     * @param owner
     * @param numberofRooms
     * @param color
     */
    public House(int position, int height, int length, String owner, int numberofRooms, String color) {
        super(position, height, length, owner);
        this.numberofRooms = numberofRooms;
        this.color = color;
    }

    public void setNumberofRooms(int numberofRooms) {
        this.numberofRooms = numberofRooms;
    }

    public void setColor(String color) {
        this.color = color;
    }
}
