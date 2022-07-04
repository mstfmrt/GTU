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
     * @param openTime
     * @param closeTime
     */
    public Market(int openTime, int closeTime) {
        super();
        this.openTime = openTime;
        this.closeTime = closeTime;

    }

    /**
     * constructor for all properties
     * @param position
     * @param height
     * @param length
     * @param owner
     * @param openTime
     * @param closeTime
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
