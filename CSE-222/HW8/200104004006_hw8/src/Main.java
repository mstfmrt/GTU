public class Main {
    public static void main(String[] args) {

        MMGraph graphA = new MMGraph(false);






        System.out.println("====== newVertex Method time consumption test ======");
        Main.newVertexDriver(10000);
        Main.newVertexDriver(10000);
        Main.newVertexDriver(10000);
        Main.newVertexDriver(10000);
        Main.newVertexDriver(10000);
        Main.newVertexDriver(10000000);
        Main.newVertexDriver(10000000);
        Main.newVertexDriver(10000000);
        Main.newVertexDriver(10000000);
        Main.newVertexDriver(10000000);

        System.out.println("\n\n\n====== addVertex Method time consumption test ======");
        Main.addVertexDriver(100);
        Main.addVertexDriver(100);
        Main.addVertexDriver(100);
        Main.addVertexDriver(100);
        Main.addVertexDriver(100);
        Main.addVertexDriver(10000);
        Main.addVertexDriver(10000);
        Main.addVertexDriver(10000);
        Main.addVertexDriver(10000);
        Main.addVertexDriver(10000);



        System.out.println("\n\n\n====== addEdge Method time consumption test ======");
        Main.addEdgeDriver(100);
        Main.addEdgeDriver(100);
        Main.addEdgeDriver(100);
        Main.addEdgeDriver(100);
        Main.addEdgeDriver(100);
        Main.addEdgeDriver(10000);
        Main.addEdgeDriver(10000);
        Main.addEdgeDriver(10000);
        Main.addEdgeDriver(10000);
        Main.addEdgeDriver(10000);



        System.out.println("\n\n\n====== removeEdge Method time consumption test ======");
        Main.removeEdgeDriver(100);
        Main.removeEdgeDriver(100);
        Main.removeEdgeDriver(100);
        Main.removeEdgeDriver(100);
        Main.removeEdgeDriver(100);
        Main.removeEdgeDriver(10000);
        Main.removeEdgeDriver(10000);
        Main.removeEdgeDriver(10000);
        Main.removeEdgeDriver(10000);
        Main.removeEdgeDriver(10000);



        System.out.println("\n\n\n====== removeVertex Method time consumption test ======");
        Main.removeVertexDriver(100);
        Main.removeVertexDriver(100);
        Main.removeVertexDriver(100);
        Main.removeVertexDriver(100);
        Main.removeVertexDriver(100);
        Main.removeVertexDriver(10000);
        Main.removeVertexDriver(10000);
        Main.removeVertexDriver(10000);
        Main.removeVertexDriver(10000);
        Main.removeVertexDriver(10000);

        System.out.println("\n\n\n====== filterVertex Method time consumption test ======");
        Main.filterVerticiesDriver(100);
        Main.filterVerticiesDriver(100);
        Main.filterVerticiesDriver(100);
        Main.filterVerticiesDriver(100);
        Main.filterVerticiesDriver(100);
        Main.filterVerticiesDriver(10000);
        Main.filterVerticiesDriver(10000);
        Main.filterVerticiesDriver(10000);
        Main.filterVerticiesDriver(10000);
        Main.filterVerticiesDriver(10000);


        System.out.println("\n\n\n====== printing graph matrix ======");
        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);
        for (int i = 0; i < 5; i++){
            newGraph.addVertex(nVer);
        }
        newGraph.addEdge(0,1,4);
        newGraph.addEdge(2,4,1);
        printMatrix(newGraph.exportMatrix());

        System.out.println("\n\n\n====== exportMatrix Method time consumption test ======");
        exportMatrixDriver(100);
        exportMatrixDriver(100);
        exportMatrixDriver(100);
        exportMatrixDriver(100);
        exportMatrixDriver(100);
        exportMatrixDriver(10000);
        exportMatrixDriver(10000);
        exportMatrixDriver(10000);
        exportMatrixDriver(10000);
        exportMatrixDriver(10000);




    }

    static void newVertexDriver(int elementAmount){
        long startTime;
        long stopTime;
        MMGraph newGraph = new MMGraph(false);
        startTime = System.nanoTime();
        for (int i = 0; i <elementAmount; i++){
            newGraph.newVertex("ss",0);
        }
        stopTime = System.nanoTime();
        System.out.println(elementAmount + "  \t \t \t" + "elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }

    static void addVertexDriver(int elementAmount){
        long startTime;
        long stopTime;
        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);
        startTime = System.nanoTime();
        for (int i = 0; i <elementAmount; i++){
            newGraph.addVertex(nVer);
        }
        stopTime = System.nanoTime();
        System.out.println(elementAmount + " \t \t" + " elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }

    static void addEdgeDriver(int elementAmount){
        long startTime;
        long stopTime;
        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);

        for (int i = 0; i <elementAmount; i++){
            newGraph.addVertex(nVer);
        }
        startTime = System.nanoTime();
        for (int i = 0; i<elementAmount;i++){
            newGraph.addEdge(i,0,1.0);
        }
        stopTime = System.nanoTime();
        System.out.println(elementAmount + " \t \t" + " elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }


    static void removeEdgeDriver(int elementAmount){
        long startTime;
        long stopTime;
        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);

        for (int i = 0; i <elementAmount; i++){
            newGraph.addVertex(nVer);
        }

        for (int i = 0; i<elementAmount;i++){
            newGraph.addEdge(i,0,1.0);
        }

        startTime = System.nanoTime();
        for(int i = 0 ; i <elementAmount; i++){
            newGraph.removeEdge(i,0);
        }

        stopTime = System.nanoTime();
        System.out.println(elementAmount + " \t \t" + " elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }


    static void removeVertexDriver(int elementAmount){
        long startTime;
        long stopTime;
        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);

        for (int i = 0; i <elementAmount; i++){
            newGraph.addVertex(nVer);
        }


        startTime = System.nanoTime();
        for(int i = 0 ; i <elementAmount; i++){
            newGraph.removeVertex(0);
        }

        stopTime = System.nanoTime();
        System.out.println(elementAmount + " \t \t" + " elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }


    static void filterVerticiesDriver(int elementAmount){
        long startTime;
        long stopTime;

        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);
        nVer.setMap("gtu","cse");
        Vertex nVer2 = new Vertex("s",0);
        nVer2.setMap("itu","ee");

        for (int i = 0; i < elementAmount/2; i++){
            newGraph.addVertex(nVer);
        }
        for (int i = elementAmount/2; i < elementAmount; i++){
            newGraph.addVertex(nVer2);
        }

        startTime = System.nanoTime();
        MMGraph ngraph = newGraph.filterVerticies("gtu","cse");

        stopTime = System.nanoTime();
        System.out.println(elementAmount + " \t \t" + " elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }



    static void exportMatrixDriver(int elementAmount){
        long startTime;
        long stopTime;

        MMGraph newGraph = new MMGraph(false);
        Vertex nVer = new Vertex("s",0);
        for (int i = 0; i < elementAmount; i++){
            newGraph.addVertex(nVer);
        }

        startTime = System.nanoTime();
        double[][] graphMx = newGraph.exportMatrix();

        stopTime = System.nanoTime();

        System.out.println(elementAmount + " \t \t" + " elemnts   =>   " + (stopTime-startTime)/100000f + "ms"); //divided by 100.000 to find the value in miliseconds.
    }

    static void printMatrix(double[][] matrix){
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[0].length; j++){
                if (matrix[i][j] == -1)
                    System.out.print("[   ]");
                else
                    System.out.print("[" + matrix[i][j] + "]");
            }
            System.out.print("\n");
        }
    }
}
