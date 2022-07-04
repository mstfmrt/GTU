import java.util.ArrayList;



/**
 * Street is a basic street with to sides can filled with buildings
 */
public class StreetAL {

    private ArrayList<Building> lSide;
    private ArrayList<Building> rSide;



    private int length;


    public int getRsize() {
        return rSide.size();
    }

    public int getLsize() {
        return lSide.size();
    }

    public ArrayList<Building> getlSide() {
        return lSide;
    }

    public ArrayList<Building> getrSide() {
        return rSide;
    }

    public int getLength() {
        return length;
    }

    public StreetAL() {
        lSide = new ArrayList<Building>();
        rSide = new ArrayList<Building>();
        length = 100;
    }

    public StreetAL(int lengthOfStreet) {
        lSide = new ArrayList<Building>();
        rSide = new ArrayList<Building>();
        length = lengthOfStreet;
    }


    /**
     * method for adding Playgrounds
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     * @param length refers to the length of the building
     */
    public void addBuilding(char side, int position, int length){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide.add(new Playground(position, length));
                    break;
                case 'l':
                    lSide.add(new Playground(position, length));
                    break;
            }
        }

    }

    /**
     * method for adding base building
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     */
    public void addBuilding(char side, int position, int height, int length, String owner){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide.add( new Building(position,height,length,owner));
                    break;
                case 'l':
                    lSide.add( new Building(position,height,length,owner));
                    break;
                default:
                    System.out.println("!!Please enter a correct input!!");
            }
        }

    }

    /**
     * method for adding house type building
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     * @param numberofRooms refers to the room number of house
     * @param color refers to the color of the house
     */
    public void addBuilding(char side, int position, int height, int length, String owner, int numberofRooms, String color){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide.add( new House(position,height,length,owner,numberofRooms,color));
                    break;
                case 'l':
                    lSide.add( new House(position,height,length,owner,numberofRooms,color));
                    break;
                default:
                    System.out.println("!!Please enter a correct input!!");
            }
        }

    }

    /**
     * method for adding office type building
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     * @param jobType refers to the job type of the office
     */
    public void addBuilding(char side, int position, int height, int length, String owner, String jobType){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide.add( new Office(position,height,length,owner,jobType));
                    break;
                case 'l':
                    lSide.add( new Office(position,height,length,owner,jobType));
                    break;
            }
        }
    }

    /**
     * method for adding market type building
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     * @param height refers to the height of the building
     * @param length refers to the length of the building
     * @param owner refers to the owner of to the building
     * @param openTime refers to the open time of the market
     * @param closeTime refers to the close time of the market
     */
    public void addBuilding(char side, int position, int height, int length, String owner, int openTime, int closeTime){
        if(isFree(side,position,length)){
            switch (side){
                case 'r':
                    rSide.add( new Market(position,height,length,owner,openTime,closeTime));
                    break;
                case 'l':
                    lSide.add( new Market(position,height,length,owner,openTime,closeTime));
                    break;
            }
        }

    }

    /**
     * method for removing building at the given position
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     */
    public void removeBuilding(char side, int position){
        int removeIndex = 0;
        switch (side){
            case 'r':
                for (int i = 0; i < getRsize(); i++){
                    if(rSide.get(i).getPosition() == position)
                        removeIndex = i;

                }
                rSide.remove(removeIndex);
                break;

            case 'l':
                for (int i = 0; i < getLsize(); i++){
                    if(lSide.get(i).getPosition() == position)
                        removeIndex = i;
                }
                lSide.remove(removeIndex);
                break;
        }

    }

    /**
     * checks if the land is free for parameters
     * @param side refers to the side of the street
     * @param position refers to the position at the street
     * @param length refers to the length of the building
     * @return if the area is free or not
     */
    public boolean isFree(char side, int position, int length){
        if(position < 0 || position >= this.length)
            return false;
        switch (side){
            case 'r':
                for (int i = 0; i < getRsize(); ++i){
                    if ((position <= rSide.get(i).getPosition() && (position + length) >= (rSide.get(i).getPosition() + rSide.get(i).getLength()))||
                            (position >= rSide.get(i).getPosition() && (position + length) <= (rSide.get(i).getPosition() + rSide.get(i).getLength()))||
                            (position < (rSide.get(i).getPosition() + rSide.get(i).getLength()) && (position + length) >= (rSide.get(i).getPosition() + rSide.get(i).getLength()))||
                            (position <= rSide.get(i).getPosition()  && (position + length) > rSide.get(i).getPosition())
                    ) {
                        return false;
                    }
                }
                break;
            case 'l':
                for (int i = 0; i < getLsize(); ++i){
                    if ((position <= lSide.get(i).getPosition() && (position + length) >= (lSide.get(i).getPosition() + lSide.get(i).getLength()))||
                            (position >= lSide.get(i).getPosition() && (position + length) <= (lSide.get(i).getPosition() + lSide.get(i).getLength()))||
                            (position < (lSide.get(i).getPosition() + lSide.get(i).getLength()) && (position + length) >= (lSide.get(i).getPosition() + lSide.get(i).getLength()))||
                            (position <= lSide.get(i).getPosition()  && (position + length) > lSide.get(i).getPosition())
                    ) {
                        return false;
                    }
                }
                break;
        }
        return true;
    }



    /**
     * calculates the number of playgrounds
     * @return number of playgrounds
     */
    public int numberofPlaygorund(){
        int total = 0;
        for (int i=0; i < getRsize();++i)
            if (getrSide().get(i).getClass().getName().equals("Playground"))
                total += getrSide().get(i).getLength();
        for (int i=0; i < getLsize();++i)
            if (getlSide().get(i).getClass().getName().equals("Playground"))
                total += getlSide().get(i).getLength();
        return total;
    }

    /**
     * prints the buildings list
     */
    public void printBuildinglist(){
        System.out.println("----Left Side----");
        for (int i = 0; i< getLsize(); ++i)
            System.out.println(getlSide().get(i).getClass().getName());

        System.out.println("----Right Side----");
        for (int i = 0; i< getRsize(); ++i)
            System.out.println(getrSide().get(i).getClass().getName());

    }

    /**
     * calculates the total length of the buildings
     * @return total building length
     */
    public int totalBuildingLength(){
        int totalLength=0;
        for (int i=0; i < getRsize();++i)
            totalLength += getrSide().get(i).getLength();
        for (int i=0; i < getLsize();++i)
            totalLength += getlSide().get(i).getLength();
        return totalLength;
    }


}
