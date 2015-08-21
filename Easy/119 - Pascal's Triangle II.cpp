/*


Pascal's Triangle II


Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
 Return [1,3,3,1]. 

Note:
 Could you optimize your algorithm to use only O(k) extra space? 

@author Zixuan
@date	2015/8/21
*/

class Solution
 {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> retVector;
		if (-1 >= rowIndex)
			return retVector;

		retVector.push_back(1);
		if (0 == rowIndex)
			return retVector;

		retVector.push_back(1);
		if (1 == rowIndex)
			return retVector;

		int currentRow = 1;

		while (currentRow < rowIndex)
		{
			vector<int> temp;

			//Begin.
			temp.push_back(1);

			for (unsigned int i = 0; i < retVector.size() - 1; ++i)
					temp.push_back(retVector[i] + retVector[i + 1]);

			//End.
			temp.push_back(1);
			++currentRow;
			
			retVector.clear();
			retVector = temp;
		}
		return retVector;
    }
};