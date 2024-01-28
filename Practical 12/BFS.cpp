
  #include <iostream>
  #include <vector>
  #include <queue>

  class GraphTraversal {
  private:
      std::vector<bool> visited;
      std::vector<std::vector<int>> graph; 
      int numVertices;
      int numEdges;

  public:
      GraphTraversal(int vertices) : numVertices(vertices), numEdges(0) {
          visited.resize(numVertices, false);
          graph.resize(numVertices);
      }

      void AddEdge(int vertex1, int vertex2) {
          graph[vertex1].push_back(vertex2);
          graph[vertex2].push_back(vertex1); 
          numEdges++;
      }

      void BFS(int startVertex) {
          visited.assign(numVertices, false); 
          std::queue<int> bfsQueue;

          visited[startVertex] = true;
          bfsQueue.push(startVertex);

          while (!bfsQueue.empty()) {
              int currentVertex = bfsQueue.front();
              bfsQueue.pop();

              std::cout << currentVertex << " ";

              for (int neighbor : graph[currentVertex]) {
                  if (!visited[neighbor]) {
                      visited[neighbor] = true;
                      bfsQueue.push(neighbor);
                  }
              }
          }
      }
  };

  int main() {
      int vertices, edges, vertex1, vertex2;

      std::cout << "Enter the number of vertices in the graph: ";
      std::cin >> vertices;

      GraphTraversal graphTraversal(vertices);

      std::cout << "Enter the number of edges in the graph: ";
      std::cin >> edges;

      std::cout << "Enter the edges (vertex1 vertex2):\n";
      for (int i = 0; i < edges; ++i) {
          std::cin >> vertex1 >> vertex2;
          graphTraversal.AddEdge(vertex1, vertex2);
      }

      std::cout << "BFS Traversal starting from vertex 0: ";
      graphTraversal.BFS(0);
      std::cout << std::endl;

      return 0;
  }
