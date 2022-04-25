#ifndef _BFS_HPP_
#define _BFS_HPP_

#include <iostream>

#include <queue>
#include <vector>
#include <list>

namespace bfs_ns
{
    class BFS
    {

        public:
            BFS(int nvertices);
            ~BFS();
            
            /**
             * @brief add v edge to graph w
             * 
             * @param v 
             * @param w 
             */
            void AddEdge(int v, int w);
            /**
             * @brief start traverse graph with start_node
             * 
             * @param start_node 
             */
            void StartBFS(int start_node);

        private:
            int nvertices_;
            // Pointer to an array containing adjacency
            std::list<int> *adj_;

    };


} // bfs_ns
#endif