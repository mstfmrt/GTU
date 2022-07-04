// Extending the Graph interface.
public interface DynamicGraph extends Graph{



    /**
     * Create a new vertex with the given label and weight.
     *
     * @param label The label of the vertex.
     * @param weight The weight of the edge.
     * @return A new vertex with the given label and weight.
     */
    Vertex newVertex (String label, double weight);

    /**
     * Adds the given vertex to the graph.
     *
     * @param new_vertex The vertex to be added to the graph.
     */
    void addVertex (Vertex new_vertex);

    /**
     * Adds an edge between the given two vertices in the graph.
     *
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex that you want to add an edge to.
     * @param weight The weight of the edge.
     */
    void addEdge (int vertexID1, int vertexID2, double weight);

    /**
     * Removes  the  edge  between the given  two vertices.
     *
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex to which the edge is to be removed.
     */
    void removeEdge  (int  vertexID1,  int  vertexID2);

    /**
     * Removes the  vertex from  the  graph  with  respect  to  the given vertex id.
     *
     * @param vertexID The ID of the vertex to be removed.
     */
    void removeVertex  (int  vertexID);

    /**
     * Removes the  vertices that have  the  given  label  from  the graph.
     *
     * @param label The label of the vertex to remove.
     */
    void removeVertex  (String label);

    /**
     * Filters the  vertices  by  the  given  user-defined property and returns a subgraph of the graph.
     *t prints the graph.
     * @param key The key to filter on.
     * @param filter The filter to apply to the vertices.
     */
    DynamicGraph  filterVerticies(String  key,  String  filter);

    /**
     * Generates the adjacency matrix representation of the graph and returns the matrix.
     */
    double[][] exportMatrix();

    /**
     * Prints the  graph in  adjacency  list  format.
     *
     */
    void printGraph();

}
