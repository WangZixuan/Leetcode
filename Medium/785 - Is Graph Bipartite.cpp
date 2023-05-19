/*


Is Graph Bipartite?


There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

- There are no self-edges (graph[u] does not contain u).
- There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.


Example 1:

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.


Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.

@author Zixuan
@date	2023/5/19
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        // 0 for undefined, 1/-1 for each partition
        vector<int> color(graph.size(), 0);

        for (int i = 0; i < graph.size(); ++i)
        {
            if (color[i] != 0)
                continue;

            // This node is never touched
            color[i] = 1;

            queue<int> nodes;
            queue<int> node_colors;

            for (int j = 0; j < graph[i].size(); ++j)
            {
                color[graph[i][j]] = -1;
                nodes.push(graph[i][j]);
				node_colors.push(-1);
            }

            while (!nodes.empty())
            {
                int node = nodes.front();
                int node_color = node_colors.front();

				nodes.pop();
                node_colors.pop();

				if (node_color != color[node])
					return false;

                for (int j = 0; j < graph[node].size(); ++j)
                {
                    if (color[graph[node][j]] == node_color)
                        return false;
                    
                    if (color[graph[node][j]] == 0)
                    {
						color[graph[node][j]] = -node_color;
						nodes.push(graph[node][j]);
                        node_colors.push(-node_color);
                    }
                }
            }
        }

        return true;
    }
};
