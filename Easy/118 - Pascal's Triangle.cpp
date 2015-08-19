/*


Pascal's Triangle 


Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

@author Zixuan
@date	2015/8/19
*/

#include <vector>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
	{
		vector<vector<int>> retVV;
		if (0 >= numRows)
			return retVV;

		vector<int> v;
		v.push_back(1);
		retVV.push_back(v);
		if (1 == numRows)
			return retVV;

		v.push_back(1);
		retVV.push_back(v);
		if (2 == numRows)
			return retVV;

		int currentRow = 2;

		while (currentRow < numRows)
		{
			v.clear();

			//Begin.
			v.push_back(1);

			for (unsigned int i = 0; i < retVV[currentRow - 1].size() - 1; ++i)
				v.push_back(retVV[currentRow - 1][i] + retVV[currentRow - 1][i + 1]);

			//End.
			v.push_back(1);
			retVV.push_back(v);
			++currentRow;
		}
		return retVV;
    }
};
