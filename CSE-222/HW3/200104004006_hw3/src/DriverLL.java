public class DriverLL {
    public static void driver(){
        System.out.println("Driver code starts...");
        long startTime = System.nanoTime();

        StreetLL newStreet = new StreetLL();




        newStreet.addBuilding('l', 5,4,3,"Emir",4,"yellow");      //house
        newStreet.addBuilding('l',12,2, 3,"Tuna","Law");                      //office
        newStreet.addBuilding('l', 18,2,4,"Ayse", 8,21);            //market
        newStreet.addBuilding('l',25,3);                                                            //playground
        newStreet.addBuilding('r', 5,4,3,"Yusuf",4,"red");  //house
        newStreet.addBuilding('r',0,2, 2,"Ahmet","Engineer");           //office
        newStreet.addBuilding('r', 20,2,3,"Mehmet", 8,21);     //market
        newStreet.addBuilding('r',12,3);                                                      //playground




        newStreet.printBuildinglist();

        newStreet.removeBuilding('l',12);
        System.out.println("Tuna's Law Office at left side position 12 is deleted\n\n");


        newStreet.printBuildinglist();

        System.out.println("After deleting the building lets check is land free?");
        if (newStreet.isFree('l',12,3))
            System.out.println("this land is free");

        System.out.println("Total remaining length " + (newStreet.getLength()*2 - newStreet.totalBuildingLength()));
        System.out.println("Length of playgrounds are " + newStreet.numberofPlaygorund() + ". Ratio of playgrounds in the street is " + ((float) newStreet.numberofPlaygorund()/(float)(newStreet.getLength()*2)));
        System.out.println("Total length of all buildings are " + newStreet.totalBuildingLength());


        System.out.println("End of the driver code.");


        long stopTime = System.nanoTime();
        System.out.println("Consumed Time in miliseconds: "+(stopTime-startTime)/100000f); //divided by 100.000 to find the value in miliseconds.

    }
}
