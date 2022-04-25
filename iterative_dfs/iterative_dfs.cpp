#include <iostream>
#include <list>
#include <map>
#include <stack>

#include <chrono>

using namespace std::chrono;

class DFS
{
    public:
        DFS(int n_vertices)
        {
            n_vertices_ = n_vertices;
            for(int i=0 ; i < n_vertices_; ++i)
            {
                isVisited_[i] = false;
            }
        }

        ~DFS()
        {

        }

        void AddEdge(int v, int w)
        {
            adj_[v].push_back(w);
        }

        void StartDFS(int start_node)
        {
            // isVisited_[start_node] = true;
            dfs_stack_.push(start_node);

            for(int i=0 ; i < n_vertices_ ; ++i)
            {
                if(!isVisited_[i])
                {
                    dfs_stack_.push(i);
                    while(!dfs_stack_.empty())
                    {
                        // std::this_thread::sleep_for(std::chrono::seconds(1));
                        start_node = dfs_stack_.top();
                        dfs_stack_.pop();
                        std::cout << "Start node: " << start_node << "\n";

                        if(!isVisited_[start_node])
                        {
                            std::cout << "Visited: " << start_node << "\n";
                            isVisited_[start_node] = true;
                        }

                        for(auto it = adj_[start_node].begin();
                        it != adj_[start_node].end(); ++ it)
                        {
                            // std::cout << "isvisited " << *it << " " << 
                            // isVisited_[*it] << "\n";
                            if(!isVisited_[*it])
                            {
                                dfs_stack_.push(*it);
                                std::cout << "push " << *it << " into stack \n";
                            }
                        }
                    }
                }
            }
        }

    private:
        int n_vertices_;
        std::map<int, bool> isVisited_;
        // std::map <int, std::stack<int>> dfs_stack_map;
        std::stack<int> dfs_stack_;
        std::map <int, std::list<int>> adj_;
};


int main()
{
    auto start = high_resolution_clock::now();

    DFS dfs_graph(5);

    // dfs_graph.AddEdge(0, 1);
    // dfs_graph.AddEdge(0, 2);
    // dfs_graph.AddEdge(1, 2);
    // dfs_graph.AddEdge(2, 0);
    // dfs_graph.AddEdge(2, 3);
    // dfs_graph.AddEdge(3, 3);

    dfs_graph.AddEdge(1, 0);
    // dfs_graph.AddEdge(0, 2);
    dfs_graph.AddEdge(2, 1);
    dfs_graph.AddEdge(0, 3);
    dfs_graph.AddEdge(1, 4);
 
    std::cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    dfs_graph.StartDFS(0);

    auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);

    std::cout << "Time taken: " << duration.count() << "microseconds. \n";
    return 0;
}