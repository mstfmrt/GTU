package Doy;

import java.util.ArrayList;
import java.util.Arrays;



public class DayofYearSet {
    public static class DayofYear{
        public DayofYear(int d, int m){
            if (m<1 || m>12){
                System.out.println("Object constructed with out day and month because of invalid date");
            }
            else if (d<1 || d>dayofMonth[m-1])
            {
                System.out.println("Object constructed with out day and month because of invalid date");
            }
            else{
                day = d;
                month = m;
            }
        }
        public int getDay(){return day;}
        public int getMonth(){return month;}
        public String toString(){
            return this.day + "/" + this.month;
        }
        public boolean equals(DayofYear other){
            if(this.getDay() == other.getDay() && this.getMonth() == other.getMonth())
                return true;
            else
                return false;
        }
        int day;
        int month;
    }
    public DayofYearSet(){
        set = new DayofYear[0];
    }
    public DayofYearSet(ArrayList<DayofYear> newSet){
        set = new DayofYear[0];

        for(DayofYear d: newSet)
            add(d);
    }
    static int[] dayofMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DayofYear[] set;

    void copySet(DayofYear[] from, DayofYear[] here){
        for (int i = 0; i < from.length; ++i) {
            here[i] = new DayofYear(from[i].getDay(), from[i].getMonth());
        }
    }
    public void add(DayofYear date){
        int i;
        int n = this.set.length;
        for (i = 0; i < this.set.length; ++i) {//if the same date already in the set
            if (this.set[i].getDay()==date.getDay() && this.set[i].getMonth() == date.getMonth()){
                return;
            }
        }
        DayofYear[] newSet;
        newSet = new DayofYear[n+1];
        for (i=0; i<n; i++){
            newSet[i] = set[i];
        }
        newSet[n] = date;
        this.set =  newSet;

    }
    public void remove(int index){
        if (set == null || index < 0
                || index >= set.length) {

            return;
        }
        DayofYear[] newSet = new DayofYear[set.length - 1];
        for (int i = 0, k = 0 ;i < set.length ; i++){
            if(i == index)
                continue;
            newSet[k++] = set[i];
        }
        this.set = newSet;
        return;
    }
    int size(){ return set.length;}
    public boolean equals(DayofYearSet other){
        boolean isEqual;
        isEqual = false;
        if (this.set.length != other.set.length)
            return false;
        for (int i = 0; i < this.set.length; ++i) {
            isEqual = false;
            for (int j = 0; j < other.set.length; ++j) {
                if (this.set[i].equals(other.set[j])) {
                    isEqual= true;
                }
            }
            if (isEqual) {
                continue;
            }
            return false;
        }
        return true;
    }
    public DayofYearSet union(DayofYearSet other){
        DayofYearSet result = new DayofYearSet();


        for (int i = 0; i < this.set.length; ++i){
            result.add(this.set[i]);
        }
        for (int i = 0; i < other.set.length; ++i){
            result.add(other.set[i]);
        }
        return result;
    }
    public DayofYearSet difference(DayofYearSet other){
        DayofYearSet result = new DayofYearSet();
        for (int i = 0; i < this.set.length; ++i) {
            for (int j = 0; j < other.set.length; ++j) {
                if (!this.set[i].equals(other.set[j]))
                    result.add(this.set[i]);
            }
        }
        return result;
    }
    DayofYearSet intersection(DayofYearSet other){
        DayofYearSet result = new DayofYearSet();

        for (int i = 0; i < this.set.length; ++i){
            for (int j = 0; j < other.set.length; ++j){
                if (this.set[i].equals(other.set[j]))
                    result.add(this.set[i]);
            }
        }
        return result;
    }
    public DayofYearSet complement(){
        DayofYearSet result = new DayofYearSet();

        for (int m = 1; m <= 12; ++m) {
            for (int d = 1; d <= dayofMonth[m-1] ; ++d) {
                for (int i = 0; i < this.set.length; ++i) {
                    if (this.set[i].getDay()!=d || this.set[i].getMonth()!=m)
                        result.add(new DayofYear(d,m));
                }
            }
        }
        return result;
    }


    public String toString() {
        return "There is " + set.length + " date(s) in this set.\n" +
                "dates in the set=" + Arrays.toString(set);
    }
}
