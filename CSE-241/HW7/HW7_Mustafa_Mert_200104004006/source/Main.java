package Doy;

import Doy.DayofYearSet;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        var d1 = new DayofYearSet.DayofYear(1,1);
        var d2 = new DayofYearSet.DayofYear(23,4);
        var d3 = new DayofYearSet.DayofYear(1,5);
        var d4 = new DayofYearSet.DayofYear(30,8);
        var d5 = new DayofYearSet.DayofYear(29,10);
        var d6 = new DayofYearSet.DayofYear(15,7);

        ArrayList<DayofYearSet.DayofYear> arrList = new ArrayList<DayofYearSet.DayofYear>();
        arrList.add(d1);
        arrList.add(d2);
        DayofYearSet s1 = new DayofYearSet(arrList);
        System.out.println("\n\n---DayofYearSet 1---");
        System.out.println(s1);

        DayofYearSet s2 = new DayofYearSet();
        s2.add(d2);
        s2.add(d3);
        System.out.println("\n\n---DayofYearSet 2---");
        System.out.println(s2);

        s2.remove(1);
        System.out.println("removed element in index 1 from set2");
        System.out.println(s2);

        DayofYearSet s3 = s1.difference(s2);
        System.out.println("\n\n---Set3 = set1 - set2---");
        System.out.println(s3);


        DayofYearSet s4 = s1.union(s2);
        System.out.println("\n\n---Set4 = set1 + set2---");
        System.out.println(s4);

        DayofYearSet s5 = new DayofYearSet();
        s5.add(d4);
        s5.add(d5);
        s5.add(d6);
        System.out.println("\n\n---DayofYearSet 5---");
        System.out.println(s5);

        if(s1.union(s2).complement().equals(s1.complement().union(s2.complement()))){
            System.out.println("\n\nDe Morgan rule is true for s1 - s2");
        }
        if(s1.union(s3).complement().equals(s1.complement().union(s3.complement()))){
            System.out.println("De Morgan rule is true for s1 - s3");
        }
        if(s4.union(s3).complement().equals(s4.complement().union(s3.complement()))){
            System.out.println("De Morgan rule is true for s4 - s3");
        }
        if(s5.union(s4).complement().equals(s5.complement().union(s4.complement()))){
            System.out.println("De Morgan rule is true for s5 - s4");
        }
        if(s2.union(s5).complement().equals(s2.complement().union(s5.complement()))){
            System.out.println("De Morgan rule is true for s2 - s5");
        }




    }
}
