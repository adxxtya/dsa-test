
    #include <iostream>
    #include <list>
    #include <vector>

    class GraphAdjList {
    private:
        std::vector<std::list<int>> adjacencyList;
        int numVertices;
        int numEdges;

    public:
        GraphAdjList(int vertices) : numVertices(vertices), numEdges(0) {
            adjacencyList.resize(vertices);
        }

        void AddEdge(int start, int end) {
            adjacencyList[start].push_back(end);
            adjacencyList[end].push_back(start); // Assuming an undirected graph
            numEdges++;
        }

        void Display() {
            for (int i = 0; i < numVertices; ++i) {
                std::cout << "Vertex " << i << ": ";
                for (int neighbor : adjacencyList[i]) {
                    std::cout << neighbor << " ";
                }
                std::cout << std::endl;
            }
        }
    };

    int main() {
        int vertices, edges;
        std::cout << "Enter the number of vertices in the graph: ";
        std::cin >> vertices;

        std::cout << "Enter the number of edges in the graph: ";
        std::cin >> edges;

        GraphAdjList graph(vertices);

        std::cout << "Enter the edges (start and end vertices):\n";
        for (int i = 0; i < edges; ++i) {
            int start, end;
            std::cin >> start >> end;
            graph.AddEdge(start, end);
        }

        std::cout << "Graph representation using Adjacency List:\n";
        graph.Display();

        return 0;
    }
