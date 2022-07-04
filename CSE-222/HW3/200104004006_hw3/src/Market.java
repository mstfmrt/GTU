public class Market extends Building{
    private int openTime;
    private int closeTime;

    /**
     * default constructor
     */
    public Market(){
        super();
    }

    /**
     * constructor for open and close time
     * @param openTime refers to the open time of the market
     * @param closeTime refers to the close time of the market
     */
    public Market(int openTime, int closeTime) {
        super();
        this.openTime = openTime;
        this.closeTime = closeTime;

    }

    /**
     * constructor for all properties
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     * @param openTime refers to the open time of the market
     * @param closeTime refers to the close time of the market
     */
    public Market(int position, int height, int length, String owner, int openTime, int closeTime) {
        super(position, height, length, owner);
        this.openTime = openTime;
        this.closeTime = closeTime;
    }

    public void setOpenTime(int openTime) {
        this.openTime = openTime;
    }

    public void setCloseTime(int closeTime) {
        this.closeTime = closeTime;
    }
}
