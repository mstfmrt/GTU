public class Q1 {


    /**
     * @param bigStr the string to search
     * @param searchStr the string to search for
     * @param occur the number of occurence to find
     * @param ssi the search starting index for where to start searching
     * @return The index of the wanted occurrence of the search string in the big string.
     */
    public static int queryString(String bigStr, String searchStr, int occur, int ssi){
        int i;
        if (occur < 1||ssi>=bigStr.length()||ssi<0)
            return -1;
        else{
            for ( i = 0; i<searchStr.length(); i++)
                if (bigStr.charAt(ssi+i) != searchStr.charAt(i))
                    return queryString(bigStr,searchStr,occur,++ssi);
            if (occur==1)
                return ssi;
            else
                return queryString(bigStr,searchStr,--occur,++ssi);
        }

    }

    public static void main(String[] args) {
        String bigString = "if it looks good it flys good";
        String searchString = "it";
        int occurence = 2;
        System.out.println("index of query string " + queryString(bigString,searchString,2,0));
    }
}
