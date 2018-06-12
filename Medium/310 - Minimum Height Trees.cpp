/*


Minimum Height Trees


For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.
Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
Example 1 :
	Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

	 0
	 |
	 1
	/ \
   2   3

	Output: [1]
Example 2 :
	Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

   0  1  2
	\ | /
	  3
	  |
	  4
	  |
	  5

	Output: [3, 4]
Note:
	According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
	The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

@author Zixuan
@date	2018/6/12
*/

#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	//Delete leaves each loop until the end.
	//https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
	{
		if (1 == n)
		{
			vector<int> result{ 0 };
			return result;
		}
		if (2 == n)
		{
			vector<int> result{ 0, 1 };

			return result;
		}

		vector<set<int>> neighbours(n);
		for (auto& edge : edges)
		{
			neighbours[edge.first].insert(edge.second);
			neighbours[edge.second].insert(edge.first);
		}

		vector<int> leaves;
		for (unsigned i = 0; i < neighbours.size(); ++i)
			if (neighbours[i].size() == 1)
				leaves.push_back(i);

		while (n>2)
		{
			n -= leaves.size();
			vector<int> newLeaves;
			for (auto leaf:leaves)
			{
				auto hisNeighbour = *(neighbours[leaf].begin());
				neighbours[hisNeighbour].erase(neighbours[hisNeighbour].find(leaf));
				if (neighbours[hisNeighbour].size() == 1)
					newLeaves.push_back(hisNeighbour);
			}

			leaves = newLeaves;
		}

		return leaves;
	}

	//Works for a graph, but may cause too much time for a tree-structure graph.
	vector<int> findMinHeightTrees_(int n, vector<pair<int, int>>& edges)
	{
		//Floyd-Warshall Algorithm
		
		vector<vector<int>> graph(n, vector<int>(n, n+1));
		//edges to matrix
		for (auto edge:edges)
		{
			graph[edge.first][edge.second] = 1;
			graph[edge.second][edge.first] = 1;
		}
		for (auto i = 0; i < n; ++i)
			graph[i][i] = 0;

		for (auto k = 0; k < n; ++k)
			for (auto i = 0; i < n; ++i)
				for (auto j = 0; j < n; ++j)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

		vector<int> minValue(n);
		for (unsigned i = 0; i < graph.size();++i)
			minValue[i]=*max_element(graph[i].begin(), graph[i].end());
		
		auto minPath = *min_element(minValue.begin(), minValue.end());

		vector<int> minHead;
		for (unsigned i = 0; i < minValue.size(); ++i)
			if (minValue[i] == minPath)
				minHead.push_back(i);

		return minHead;

	}
};
