
  #include <iostream>
  #include <vector>
  #include <algorithm>

  class Graph {
  private:
      std::vector<std::pair<int, std::pair<int, int>>> edges; 
      int numVertices;
      int numEdges;

  public:
      Graph(int vertices) : numVertices(vertices), numEdges(0) {}

      void AddEdge(int vertex1, int vertex2, int weight) {
          edges.push_back({weight, {vertex1, vertex2}});
          numEdges++;
      }

      void KruskalMinimumSpanningTree() {
          std::sort(edges.begin(), edges.end());          
          std::vector<std::pair<int, std::pair<int, int>>> minimumSpanningTree;
          std::vector<int> parent(numVertices);

          for (int i = 0; i < numVertices; ++i) {
              parent[i] = i;
          }

          for (const auto& edge : edges) {
              int root1 = FindRoot(parent, edge.second.first);
              int root2 = FindRoot(parent, edge.second.second);

              if (root1 != root2) {
                  minimumSpanningTree.push_back(edge);
                  Union(parent, root1, root2);
              }
          }

          DisplayMinimumSpanningTree(minimumSpanningTree);
      }

      int FindRoot(std::vector<int>& parent, int vertex) {
          while (parent[vertex] != vertex) {
              vertex = parent[vertex];
          }
          return vertex;
      }

      void Union(std::vector<int>& parent, int root1, int root2) {
          parent[root1] = root2;
      }

      void DisplayMinimumSpanningTree(const std::vector<std::pair<int, std::pair<int, int>>>& minimumSpanningTree) {
          std::cout << "Minimum Spanning Tree Edges:\n";
          for (const auto& edge : minimumSpanningTree) {
              std::cout << edge.second.first << " - " << edge.second.second << " (Weight: " << edge.first << ")\n";
          }
      }
  };

  int main() {
      int vertices, edges, vertex1, vertex2, weight;

      std::cout << "Enter the number of vertices in the graph: ";
      std::cin >> vertices;

      Graph graph(vertices);

      std::cout << "Enter the number of edges in the graph: ";
      std::cin >> edges;

      std::cout << "Enter the edges and their weights (vertex1 vertex2 weight):\n";
      for (int i = 0; i < edges; ++i) {
          std::cin >> vertex1 >> vertex2 >> weight;
          graph.AddEdge(vertex1, vertex2, weight);
      }

      graph.KruskalMinimumSpanningTree();

      return 0;
  }
