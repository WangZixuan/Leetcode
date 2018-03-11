/*


All Paths From Source to Target



Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
Example:
	Input: [[1,2], [3], [3], []]
	Output: [[0,1,3],[0,2,3]]
	Explanation: The graph looks like this:
	0--->1
	|    |
	v    v
	2--->3
	There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:
	The number of nodes in the graph will be in the range [2, 15].
	You can print different paths in any order, but you should keep the order of nodes inside one path.

@author Zixuan
@date	2018/3/11
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
	{
		vector<vector<int>> paths;

		//Initialization
		for (auto i : graph[0])
		{
			vector<int> temp{ 0, i };
			paths.push_back(temp);
		}

		for (auto i = 1; i < static_cast<int>(graph.size()) - 1; ++i)
		{
			auto& nodes = graph[i];

			vector<int> selected;

			for (auto k = 0; k < paths.size();++k)
			{
				if (paths[k].back() == i)
					selected.push_back(k);
			}

			vector<vector<int>> temp_storage;

			for (auto k : selected)
			{
				auto p = paths[k];

				if (nodes.size() > 0)
				{

					for (auto j = 0; j < nodes.size(); ++j)
					{ 
						auto temp(p);
						temp.push_back(nodes[j]);
						temp_storage.push_back(temp);
					}

				}

			}

			//When you want to remove some elements in a vector,
			//Pay attention to its index.
			vector<vector<int>> temp_p;
			for (auto k = 0; k < paths.size(); ++k)
				if (find(selected.begin(), selected.end(), k) == selected.end())
					temp_p.push_back(paths[k]);

			paths = temp_p;
			paths.insert(paths.end(), temp_storage.begin(), temp_storage.end());

		}

		auto target = static_cast<int>(graph.size()) - 1;
		vector<vector<int>> result;
		for (auto& p : paths)
			if (p.back() == target)
				result.push_back(p);

		return result;
	}
};