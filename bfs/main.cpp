#include "bfs.hpp"

#include <chrono>

using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    bfs_ns::BFS bfs_graph(4);
    
    bfs_graph.AddEdge(0, 1);
    bfs_graph.AddEdge(0, 2);
    bfs_graph.AddEdge(1, 2);
    bfs_graph.AddEdge(2, 0);
    bfs_graph.AddEdge(2, 3);
    bfs_graph.AddEdge(3, 3);
 
    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    bfs_graph.StartBFS(2);

    auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);

    std::cout << "Time taken: " << duration.count() << "microseconds. \n";

    return 0;
}