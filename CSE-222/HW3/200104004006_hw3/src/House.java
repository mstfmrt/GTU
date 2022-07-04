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
     * @param numberofRooms refers to the room number of the house
     */
    public House(int numberofRooms) {
        super();
        this.numberofRooms = numberofRooms;
    }

    /**
     * constructor for color info
     * @param color refers to the color of the house
     */
    public House(String color) {
        super();
        this.color = color;
    }

    /**
     * constructor for number of room and color info
     * @param numberofRooms refers to the room number of the house
     * @param color refers to the color of the house
     */
    public House(int numberofRooms, String color) {
        super();
        this.numberofRooms = numberofRooms;
        this.color = color;
    }

    /**
     * constructor with all information
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     * @param numberofRooms refers to the room number of the house
     * @param color refers to the color of the house
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
