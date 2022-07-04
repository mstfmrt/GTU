import java.util.Scanner;


public class MainLD {
    public static void main(String[] args) {
        char side;
        int position, length, height, numberofRooms, openTime, closeTime;
        String owner, color, jobType;
        boolean isContinue = true;

        DriverLD.driver();
        System.out.println("Main program starting....");
        StreetLD newStreet = new StreetLD();





        while(isContinue){
            System.out.println("\n\n\n\n\n\n-----City Planning Software-----");
            System.out.println("1-Editing Mode");
            System.out.println("2-Viewing Mode");
            System.out.println("3-Exit");
            Scanner scan  = new Scanner(System.in);
            char input = scan.nextLine().charAt(0);
            switch (input){
                case '1':
                    System.out.println("\n\n\n\n\n-----Editing Mode-----");
                    System.out.println("1-Add Building");
                    System.out.println("2-Remove Building");
                    System.out.println("3-Return Main Menu");
                    input = scan.nextLine().charAt(0);
                    switch (input){
                        case '1':
                            System.out.println("\n\n\n\n\n-----Add Building-----");
                            System.out.println("1-House");
                            System.out.println("2-Office");
                            System.out.println("3-Market");
                            System.out.println("4-Playground");
                            input = scan.nextLine().charAt(0);
                            switch (input){
                                case '1':
                                    System.out.println("Please enter the properties to add 'house'");
                                    System.out.print("side(l-r): ");
                                    side = scan.nextLine().charAt(0);
                                    System.out.print("position: ");
                                    position = scan.nextInt();
                                    System.out.print("height: ");
                                    height = scan.nextInt();
                                    System.out.print("length: ");
                                    length = scan.nextInt();
                                    scan.nextLine();
                                    System.out.print("owner: ");
                                    owner = scan.nextLine();
                                    System.out.print("numberofRooms: ");
                                    numberofRooms = scan.nextInt();
                                    scan.nextLine();
                                    System.out.print("color: ");
                                    color = scan.nextLine();

                                    if(height <= 0 ) {
                                        System.out.println("Height can not be less than zero!!!");
                                        break;
                                    }
                                    if(length <= 0 ) {
                                        System.out.println("Length can not be less than zero!!!");
                                        break;
                                    }
                                    if(length> newStreet.getLength()){
                                        System.out.println("Building's length can not be larger than street's length!!!");
                                    }

                                    newStreet.addBuilding(side,position,height,length,owner,numberofRooms,color);
                                    break;
                                case '2':
                                    System.out.println("Please enter the properties to add 'office'");
                                    System.out.print("side(l-r): ");
                                    side = scan.nextLine().charAt(0);
                                    System.out.print("position: ");
                                    position = scan.nextInt();
                                    System.out.print("height: ");
                                    height = scan.nextInt();
                                    System.out.print("length: ");
                                    length = scan.nextInt();
                                    scan.nextLine();
                                    System.out.print("owner: ");
                                    owner = scan.nextLine();
                                    scan.nextLine();
                                    System.out.print("jobType: ");
                                    jobType = scan.nextLine();

                                    if(height <= 0 ) {
                                        System.out.println("Height can not be less than zero!!!");
                                        break;
                                    }
                                    if(length <= 0 ) {
                                        System.out.println("Length can not be less than zero!!!");
                                        break;
                                    }
                                    if(length> newStreet.getLength()){
                                        System.out.println("Building's length can not be larger than street's length!!!");
                                    }

                                    newStreet.addBuilding(side,position,height,length,owner,jobType);
                                    break;
                                case '3':
                                    System.out.println("Please enter the properties to add 'market'");
                                    System.out.print("side(l-r): ");
                                    side = scan.nextLine().charAt(0);
                                    System.out.print("position: ");
                                    position = scan.nextInt();
                                    System.out.print("height: ");
                                    height = scan.nextInt();
                                    System.out.print("length: ");
                                    length = scan.nextInt();
                                    scan.nextLine();
                                    System.out.print("owner: ");
                                    owner = scan.nextLine();
                                    System.out.print("open time: ");
                                    openTime = scan.nextInt();
                                    System.out.print("close time: ");
                                    closeTime = scan.nextInt();

                                    if(height <= 0 ) {
                                        System.out.println("Height can not be less than zero!!!");
                                        break;
                                    }
                                    if(length <= 0 ) {
                                        System.out.println("Length can not be less than zero!!!");
                                        break;
                                    }
                                    if(length> newStreet.getLength()){
                                        System.out.println("Building's length can not be larger than street's length!!!");
                                        break;
                                    }

                                    newStreet.addBuilding(side,position,height,length,owner,openTime, closeTime);
                                    break;
                                case '4':
                                    System.out.println("Please enter the properties to add 'playground'");
                                    System.out.print("side(l-r): ");
                                    side = scan.nextLine().charAt(0);
                                    System.out.print("position: ");
                                    position = scan.nextInt();
                                    System.out.print("length: ");
                                    length = scan.nextInt();
                                    newStreet.addBuilding(side,position,length);
                            }

                            break;
                        case '2':
                            System.out.println("\n\n\n\n\n-----Remove Building-----");
                            System.out.print("Select the side(l-r): ");
                            side = scan.nextLine().charAt(0);
                            System.out.print("Select the position: ");
                            position = scan.nextInt();
                            newStreet.removeBuilding(side,position);
                            break;
                        case '3':
                            break;
                        default:
                            System.out.println("!!Please enter a correct input!!");
                    }

                    break;

                case '2':
                    System.out.println("\n\n\n\n\n-----Viewing Mode-----");
                    System.out.println("1-Total remaining length of lands");
                    System.out.println("2-List of buildings");
                    System.out.println("3-Number and ratio of length of playgrounds");
                    System.out.println("4-Total length of all buildings");
                    System.out.println("5-Skyline silhouette");
                    System.out.println("6-Return Main Menu");
                    input = scan.nextLine().charAt(0);
                    switch (input){
                        case '1':
                            System.out.println("Total remaining length " + (newStreet.getLength()*2 - newStreet.totalBuildingLength()));
                            break;
                        case '2':
                            newStreet.printBuildinglist();
                            break;
                        case '3':
                            System.out.println("Number of playgrounds are " + newStreet.numberofPlaygorund() + ". Ratio of playgrounds in the street is " + ((float)newStreet.numberofPlaygorund()/(float)(newStreet.getLength()*2)));
                            break;
                        case '4':
                            System.out.println("Total length of all buildings are " + newStreet.totalBuildingLength());
                            break;
                        case '5':
                            break;
                        case '6':
                            break;
                        default:
                            System.out.println("!!Please enter a correct input!!");
                    }

                    break;
                case '3':
                    isContinue = false;
                    break;
                default:
                    System.out.println("!!Please enter a correct input!!");
            }
        }
    }


}



