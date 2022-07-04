public class Office extends Building{
    private String jobType;

    /**
     *default constructor
     */
    public Office() {
        super();
    }

    /**
     * constructor for jobtype
     * @param jobType
     */
    public Office(String jobType) {
        super();
        this.jobType = jobType;
    }

    /**
     * constructor with all properties
     * @param position
     * @param height
     * @param length
     * @param owner
     * @param jobType
     */
    public Office(int position, int height, int length, String owner, String jobType) {
        super(position, height, length, owner);
        this.jobType = jobType;
    }

    public void setJobType(String jobType) {
        this.jobType = jobType;
    }
}
