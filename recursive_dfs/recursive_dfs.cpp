#include <iostream>
#include <map>
#include <list>

#include <chrono>

using namespace std::chrono;

class DFS_Recursion
{
    public:
        void AddEdge(int v, int w)
        {
            adj_[v].push_back(w);
        }

        void StartDFS(int start_node)
        {
            isVisited_[start_node] = true;
            std::cout << "Visited node: " << start_node << "\n";

            for(auto it = adj_[start_node].begin(); it != adj_[start_node].end(); ++it)
            {
                if(!isVisited_[*it])
                {
                    StartDFS(*it);
                }
            }
        }

    private:
        int nvertices_;
        std::map<int, bool> isVisited_;
        std::map<int, std::list<int>> adj_;

};


int main()
{
    auto start = high_resolution_clock::now();

    DFS_Recursion DFS_graph;

    DFS_graph.AddEdge(0, 1);
    DFS_graph.AddEdge(0, 2);
    DFS_graph.AddEdge(1, 2);
    DFS_graph.AddEdge(2, 0);
    DFS_graph.AddEdge(2, 3);
    DFS_graph.AddEdge(3, 3);

    std::cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    DFS_graph.StartDFS(2);

    auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);

    std::cout << "Time taken: " << duration.count() << " microseconds. \n";
    
    return 0;
}
    