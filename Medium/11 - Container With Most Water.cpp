/*


Container With Most Water 


Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 

@author Zixuan
@date	2015/9/8
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	//See http://www.cnblogs.com/tenosdoit/p/3812880.html
	int maxArea(vector<int>& height) 
	{
		unsigned int storage = 0;
		unsigned int left = 0, right = height.size() - 1;
		while (left < right)
		{
			storage = max(storage, (right - left) * min(height[left], height[right]));
			if (height[left] < height[right])
				left++;
			else 
				right--;
		}
		return storage;
		
	}
};