import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class MMGraph implements DynamicGraph{



    // Data Fields
    /** The number of vertices */
    private int numV;

    /** Flag to indicate whether this is a directed graph */
    private boolean directed;

    private ArrayList<Vertex> verticies;
    private ArrayList<LinkedList<Edge>> edges;

    // Constructor
    /** Construct a graph with the specified number of vertices
     and the directed flag. If the directed flag is true,
     this is a directed graph.
     @param directed The directed flag
     */
    public MMGraph(boolean directed) {
        this.numV = 0;
        this.directed = directed;
        edges = new ArrayList<>();
        verticies = new ArrayList<>();
    }



    // Accessor Methods
    /** Return the number of vertices.
     @return The number of vertices
     */
    public int getNumV() {
        return numV;
    }

    /** Return whether this is a directed graph.
     @return true if this is a directed graph
     */
    public boolean isDirected() {
        return directed;
    }

    Vertex getVertex(int index){
        return verticies.get(index);
    }

    // Other Methods

    /**
     * Generates a new vertex by given parameters.
     *
     * @param label  The label of the vertex.
     * @param weight The weight of the vertex.
     * @return A new vertex with the given label and weight.
     */
    @Override
    public Vertex newVertex(String label, double weight) {
        return  new Vertex(label, weight);
    }

    /**
     * Adds the given vertex to the graph.
     *
     * @param new_vertex The vertex to be added to the graph.
     */
    @Override
    public void addVertex(Vertex new_vertex) {
        new_vertex.index = numV++;
        verticies.add(new_vertex);
        edges.add(new LinkedList<>());
    }

    /**
     * Adds an edge between the given two vertices in the graph.
     *
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex that you want to add an edge to.
     * @param weight    The weight of the edge.
     */
    @Override
    public void addEdge(int vertexID1, int vertexID2, double weight) {

        edges.get(vertexID1).add(new Edge(vertexID1,vertexID2,weight));
        if(!this.directed){
            edges.get(vertexID2).add(new Edge(vertexID2,vertexID1,weight));
        }
    }

    /**
     * Removes  the  edge  between the given  two vertices.
     *
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex to which the edge is to be removed.
     */
    @Override
    public void removeEdge(int vertexID1, int vertexID2) {

        Edge target = new Edge(vertexID1, vertexID2, Double.POSITIVE_INFINITY);
        for (Edge edge : edges.get(vertexID1)) {
            if (edge.equals(target))
                edges.remove(edge);
        }
        if (!this.directed){
            Edge target2 = new Edge(vertexID2, vertexID1, Double.POSITIVE_INFINITY);
            for (Edge edge : edges.get(vertexID2)) {
                if (edge.equals(target))
                    edges.remove(edge);
            }
        }
    }

    /**
     * Removes the  vertex from  the  graph  with  respect  to  the given vertex id.
     *
     * @param vertexID The ID of the vertex to be removed.
     */
    @Override
    public void removeVertex(int vertexID) {
        verticies.remove(vertexID);
        edges.remove(vertexID);
        numV--;
        for (int i = 0 ; i<numV; i++){
            for (Edge edge : edges.get(i)){
                if (edge.getSource() == vertexID || edge.getDest() == vertexID)
                    edges.get(i).remove(edge);
                else{
                    if (edge.getSource() > vertexID)
                        edge.setSource(edge.getSource()-1);
                    if (edge.getDest() > vertexID)
                        edge.setDest(edge.getDest()-1);
                }
            }
        }
        for (int i = 0; i<numV ; i++){
            verticies.get(i).index = i;
        }
    }

    /**
     * Removes the  vertices that have  the  given  label  from  the graph.
     *
     * @param label The label of the vertex to remove.
     */
    @Override
    public void removeVertex(String label) {
        for(int i= numV-1; i >= 0; i--){
            if(verticies.get(i).label.equals(label))
                removeVertex(i);
        }
    }

    /**
     * Filters the  vertices  by  the  given  user-defined property and returns a subgraph of the graph.
     * t prints the graph.
     *
     * @param key    The key to filter on.
     * @param filter The filter to apply to the vertices.
     */
    @Override
    public MMGraph filterVerticies(String key, String filter) {
        MMGraph newGraph = new MMGraph(false);
        newGraph = this;

        for (int i = numV-1 ; i >=0; i--) {
            if (!verticies.get(i).map.containsKey(key) && !verticies.get(i).map.containsValue(filter))
                newGraph.removeVertex(i);
        }

        return newGraph;
    }


    /**
     * Generates the adjacency matrix representation of the graph and returns the matrix.
     */
    @Override
    public double[][] exportMatrix() {
        double nmatrix[][] = new double[numV][numV];
        for (int i=0; i<numV ; i++)
            for (int j=0; j<numV; j++)
                nmatrix[i][j] = -1;

        for (int source = 0; source < numV; source++)
            for(Edge edge: edges.get(source)){
                int dest = edge.getDest();
                nmatrix[source][dest] = edge.getWeight();
            }
        return nmatrix;
    }

    /**
     * Prints the  graph in  adjacency  list  format.
     */
    @Override
    public void printGraph() {

    }


    /**
     * Insert a new edge into the graph.
     *
     * @param edge The new edge
     */
    @Override
    public void insert(Edge edge) {
        edges.get(edge.getSource()).add(edge);
        if (!isDirected()) {
            edges.get(edge.getDest()).add(new Edge(edge.getDest(),
                    edge.getSource(),
                    edge.getWeight()));
        }
    }

    /**
     * Determine whether an edge exists.
     *
     * @param source The source vertex
     * @param dest   The destination vertex
     * @return true if there is an edge from source to dest
     */
    @Override
    public boolean isEdge(int source, int dest) {
        return edges.get(source).contains(new Edge(source, dest));
    }

    /**
     * Get the edge between two vertices.
     *
     * @param source The source vertex
     * @param dest   The destination vertex
     * @return The Edge between these two vertices
     * or an Edge with a weight of
     * Double.POSITIVE_INFINITY if there is no edge
     */
    @Override
    public Edge getEdge(int source, int dest) {
        Edge target =
                new Edge(source, dest, Double.POSITIVE_INFINITY);
        for (Edge edge : edges.get(source)) {
            if (edge.equals(target))
                return edge; // Desired edge found, return it.
        }
        // Assert: All edges for source checked.
        return target; // Desired edge not found.
    }

    /**
     * Return an iterator to the edges connected
     * to a given vertex.
     *
     * @param source The source vertex
     * @return An Iterator<Edge> to the vertices
     * connected to source
     */
    @Override
    public Iterator<Edge> edgeIterator(int source) {
        return edges.get(source).iterator();
    }
}
