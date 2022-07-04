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
     * @param jobType refers to the job type of the office
     */
    public Office(String jobType) {
        super();
        this.jobType = jobType;
    }

    /**
     * constructor with all properties
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     * @param jobType refers to the job type of the office
     */
    public Office(int position, int height, int length, String owner, String jobType) {
        super(position, height, length, owner);
        this.jobType = jobType;
    }

    public void setJobType(String jobType) {
        this.jobType = jobType;
    }
}
