public class Driver {
    public static void driver(){
        System.out.println("Driver code starts...");

        Street newStreet = new Street();




        newStreet.addBuilding('l', 5,4,3,"Emir",4,"yellow");      //house
        newStreet.addBuilding('l',12,2, 3,"Tuna","Law");                      //office
        newStreet.addBuilding('l', 18,2,4,"Ayse", 8,21);            //market
        newStreet.addBuilding('l',25,3);                                                            //playground
        newStreet.addBuilding('r', 5,4,3,"Yusuf",4,"red");  //house
        newStreet.addBuilding('r',0,2, 2,"Ahmet","Engineer");           //office
        newStreet.addBuilding('r', 20,2,3,"Mehmet", 8,21);     //market
        newStreet.addBuilding('r',12,3);                                                      //playground




        Main.printBuildinglist(newStreet);

        newStreet.removeBuilding('l',12);
        System.out.println("Tuna's Law Office at left side position 12 is deleted\n\n");


        Main.printBuildinglist(newStreet);

        System.out.println("After deleting the building lets check is land free?");
        if (newStreet.isFree('l',12,3))
            System.out.println("this land is free");

        System.out.println("Total remaining length " + (newStreet.getLength()*2 - Main.totalBuildingLength(newStreet)));
        System.out.println("Length of playgrounds are " + Main.numberofPlaygorund(newStreet) + ". Ratio of playgrounds in the street is " + ((float)Main.numberofPlaygorund(newStreet)/(float)(newStreet.getLength()*2)));
        System.out.println("Total length of all buildings are " + Main.totalBuildingLength(newStreet));


        System.out.println("End of the driver code.");

    }
}
