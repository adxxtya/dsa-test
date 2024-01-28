#include <iostream>

using namespace std;

// const int MAX_VERTICES = 100; // Maximum number of vertices in the graph

// class Graph {
// private:
//     int vertices;
//     int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

// public:
//     Graph(int v) : vertices(v) {
//         for (int i = 0; i < MAX_VERTICES; ++i) {
//             for (int j = 0; j < MAX_VERTICES; ++j) {
//                 adjacencyMatrix[i][j] = 0;
//             }
//         }
//     }

//     void addEdge(int from, int to) {
//         // Assuming it's an undirected graph, so we update both entries
//         adjacencyMatrix[from][to] = 1;
//         adjacencyMatrix[to][from] = 1;
//     }

//     void printGraph() {
//         for (int i = 0; i < vertices; ++i) {
//             for (int j = 0; j < vertices; ++j) {
//                 cout << adjacencyMatrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     int numVertices, numEdges;

//     cout << "Enter the number of vertices: ";
//     cin >> numVertices;

//     Graph graph(numVertices);

//     cout << "Enter the number of edges: ";
//     cin >> numEdges;

//     cout << "Enter the edges (vertex pairs):" << endl;
//     for (int i = 0; i < numEdges; ++i) {
//         int from, to;
//         cin >> from >> to;
//         graph.addEdge(from, to);
//     }

//     // Print the adjacency matrix
//     cout << "Adjacency Matrix:" << endl;
//     graph.printGraph();

//     return 0;
// }

const int MAX_VERTICES = 100;

class Graph {
    private:
        int vertices;
        int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    public:
        Graph(int v): vertices(v) {
            for (int i = 0; i < MAX_VERTICES; ++i)
            {
                for (int j = 0; j < MAX_VERTICES; ++j)
                {
                    adjacencyMatrix[i][j] = 0;
                }
            }
            
        }

        void addEdge(int from, int to) {
            adjacencyMatrix[from][to] = 1;
            adjacencyMatrix[to][from] = 1;
        }

        void printGraph() {
            for (int i = 0; i < vertices; ++i)
            {
                for (int j = 0; j < vertices; ++j)
                {
                    cout << adjacencyMatrix[i][j] << " ";
                }
                    cout << endl;
            }
            
        }
};

int main() {
    int totalVertices, totalEdges;

    cout << "Enter the total number of vertices: ";
    cin >> totalVertices;

    Graph graph(totalVertices);

    cout << "Enter the total number of edges: ";
    cin >> totalEdges;

    cout << "Enter the connections between the vertices:" << endl;
    for (int i = 0; i < totalEdges; i++)
    {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }


    cout << "Adjacency Matrix: " << endl;
    graph.printGraph();

    return 0;
}