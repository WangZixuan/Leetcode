/*


Maximum Binary Tree


Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.
	Example 1:
	Input: [3,2,1,6,0,5]
	Output: return the tree root node representing the following tree:

		  6
		/   \
	   3     5
		\    /
		 2  0
		  \
		   1

Note:
The size of the given array will be in the range [1,1000].

@author Zixuan
@date	2017/9/14
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
	{
		return constructPart(nums, 0, static_cast<int>(nums.size() - 1));
	}

private:
	TreeNode* constructPart(vector<int>& nums, int start, int end)
	{
		if (start == end)
		{
			auto t = new TreeNode(nums[start]);
			return t;
		}

		//Find the maximum element between start and end
		auto index = start;
		auto maximumElement = nums[start];
		for (auto i = index; i <= end; ++i)
			if (nums[i] > maximumElement)
			{
				index = i;
				maximumElement = nums[i];
			}

		auto t = new TreeNode(maximumElement);

		if (index > start)
			t->left = constructPart(nums, start, index - 1);
		if (index < end)
			t->right = constructPart(nums, index + 1, end);

		return t;
	}
};
