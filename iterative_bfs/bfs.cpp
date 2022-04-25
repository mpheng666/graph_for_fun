#include "bfs.hpp"

namespace bfs_ns
{
    BFS::BFS(int nvertices)
    {
        nvertices_ = nvertices;
        adj_ = new std::list<int>[nvertices_];
    }

    BFS::~BFS()
    {

    }

    void BFS::AddEdge(int v, int w)
    {
        adj_[v].push_back(w); 
        // std::cout << "Number of v, " << v << " size: " << adj_[v].size() << "\n";
    }

    void BFS::StartBFS(int start_node)
    {
        // mark all vertices visited as false
        bool *visited = new bool[nvertices_];
        for(int i; i < nvertices_; ++i)
        {
            visited[i] = false;
        }

        // std::cout << "size of adj_: " << adj_[start_node].size() << "\n";

        std::queue<int> bfs_queue;

        visited[start_node] = true;
        bfs_queue.push(start_node);

        while(!bfs_queue.empty())
        {
            start_node = bfs_queue.front();
            std::cout << "visited " << start_node << "\n";
            bfs_queue.pop();

            for(auto it = adj_[start_node].begin(); it != adj_[start_node].end(); ++it)
            {
                if(!visited[*it])
                {
                    std::cout << "going to visit " << *it << "\n";
                    visited[*it] = true;
                    bfs_queue.push(*it);
                }
                else
                {
                    std::cout << "visited so pass " << *it << "\n";
                }
            }
        }
        std::cout << "\n";
    }
}