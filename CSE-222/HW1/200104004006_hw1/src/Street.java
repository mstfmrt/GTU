/**
 * Street is a basic street with to sides can filled with buildings
 */
public class Street {

    private int rsize;
    private int lsize;
    private int rcapacity;
    private int lcapacity;
    private Building lSide[];
    private Building rSide[];
    private int length;


    public int getRsize() {
        return rsize;
    }

    public int getLsize() {
        return lsize;
    }

    public Building[] getlSide() {
        return lSide;
    }

    public Building[] getrSide() {
        return rSide;
    }

    public Street() {
        lSide = new Building[32];
        rSide = new Building[32];
        length = 32;
        rsize = lsize = 0;
        rcapacity = lcapacity = 8;

    }

    public int getLength() {
        return length;
    }

    /**
     * method for adding Playgrounds
     * @param side
     * @param position
     * @param length
     */
    public void addBuilding(char side, int position, int length){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide[rsize] = new Playground(position,length);
                    rsize++;
                    break;
                case 'l':
                    lSide[lsize] = new Playground(position,length);
                    lsize++;
                    break;
            }
        }

    }

    /**
     * method for adding base building
     * @param side
     * @param position
     * @param height
     * @param length
     * @param owner
     */
    public void addBuilding(char side, int position, int height, int length, String owner){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide[rsize] = new Building(position,height,length,owner);
                    rsize++;
                    break;
                case 'l':
                    lSide[lsize] = new Building(position,height,length,owner);
                    lsize++;
                    break;
                default:
                    System.out.println("!!Please enter a correct input!!");
            }
        }

    }

    /**
     * method for adding house type building
     * @param side
     * @param position
     * @param height
     * @param length
     * @param owner
     * @param numberofRooms
     * @param color
     */
    public void addBuilding(char side, int position, int height, int length, String owner, int numberofRooms, String color){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide[rsize] = new House(position,height,length,owner,numberofRooms,color);
                    rsize++;
                    break;
                case 'l':
                    lSide[lsize] = new House(position,height,length,owner,numberofRooms,color);
                    lsize++;
                    break;
                default:
                    System.out.println("!!Please enter a correct input!!");
            }
        }

    }

    /**
     * method for adding office type building
     * @param side
     * @param position
     * @param height
     * @param length
     * @param owner
     * @param jobType
     */
    public void addBuilding(char side, int position, int height, int length, String owner, String jobType){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide[rsize] = new Office(position,height,length,owner,jobType);
                    rsize++;
                    break;
                case 'l':
                    lSide[lsize] = new Office(position,height,length,owner,jobType);
                    lsize++;
                    break;
            }
        }
    }

    /**
     * method for adding market type building
     * @param side
     * @param position
     * @param height
     * @param length
     * @param owner
     * @param openTime
     * @param closeTime
     */
    public void addBuilding(char side, int position, int height, int length, String owner, int openTime, int closeTime){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide[rsize] = new Market(position,height,length,owner,openTime,closeTime);
                    rsize++;
                    break;
                case 'l':
                    lSide[lsize] = new Market(position,height,length,owner,openTime,closeTime);
                    lsize++;
                    break;
            }
        }

    }

    /**
     * method for removing building at the given position
     * @param side
     * @param position
     */
    public void removeBuilding(char side, int position){
        int removeIndex = 0;
        switch (side){
            case 'r':
                for (int i = 0; i < rsize; i++){
                    if (rSide[i].getPosition()==position)
                        removeIndex = i;
                    break;
                }
                for(int i = removeIndex; i < rsize; i++){
                    rSide[i] = rSide[i+1];
                }
                rsize--;
                break;

            case 'l':
                for (int i = 0; i < lsize; i++){
                    if (lSide[i].getPosition()==position){
                        removeIndex = i;
                        break;
                    }


                }
                for(int i = removeIndex; i < lsize; i++){
                    lSide[i] = lSide[i+1];
                }
                lsize--;
                break;
        }

    }

    /**
     * checks if the land is free for parameters
     * @param side
     * @param position
     * @param length
     * @return
     */
    public boolean isFree(char side, int position, int length){
        if(position < 0 || position >= this.length)
            return false;
        switch (side){
            case 'r':
                for (int i = 0; i < rsize; ++i){
                    if ((position <= rSide[i].getPosition() && (position + length) >= (rSide[i].getPosition() + rSide[i].getLength()))||
                            (position >= rSide[i].getPosition() && (position + length) <= (rSide[i].getPosition() + rSide[i].getLength()))||
                            (position < (rSide[i].getPosition() + rSide[i].getLength()) && (position + length) >= (rSide[i].getPosition() + rSide[i].getLength()))||
                            (position <= rSide[i].getPosition()  && (position + length) > rSide[i].getPosition())
                    ) {
                        return false;
                    }
                }
                break;
            case 'l':
                for (int i = 0; i < lsize; ++i){
                    if ((position <= lSide[i].getPosition() && (position + length) >= (lSide[i].getPosition() + lSide[i].getLength()))||
                            (position >= lSide[i].getPosition() && (position + length) <= (lSide[i].getPosition() + lSide[i].getLength()))||
                            (position < (lSide[i].getPosition() + lSide[i].getLength()) && (position + length) >= (lSide[i].getPosition() + lSide[i].getLength()))||
                            (position <= lSide[i].getPosition()  && (position + length) > lSide[i].getPosition())
                    ) {
                        return false;
                    }
                }
                break;
        }
        return true;
    }
}
