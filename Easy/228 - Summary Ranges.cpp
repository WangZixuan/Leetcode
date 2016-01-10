/*


Summary Ranges


Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
	vector<string> summaryRanges(vector<int>& nums) 
	{
		if (0 == nums.size())
			return result;
		
		get_head_to_string(nums);
		return result;
	}

private:
	void get_head_to_string(vector<int> nums)
	{
		if (1 == nums.size())
		{
			auto str = to_string(nums[0]);
			result.push_back(str);
			return;
		}

		if (nums.size() == nums[nums.size() - 1] - nums[0] + 1)
		{
			auto start_str = to_string(nums[0]);
			auto end_str = to_string(nums[nums.size() - 1]);
			auto str = start_str + "->" + end_str;
			result.push_back(str);
			return;
		}

		//Now we guarantee the vector is not just one sequence.
		//Now we deal with head.
		auto head = nums[0];
		auto index = 1;
		for (index = 1; index < nums.size(); ++index)
		{
			if (nums[index] - head != index)
				break;
		}

		if (1 == index)
		{
			auto s = to_string(head);
			result.push_back(s);
		}
		else
		{
			auto end_str = to_string(nums[index - 1]);
			auto str = to_string(head) + "->" + end_str;
			result.push_back(str);
		}

		vector<int>::const_iterator first = nums.begin() + index;
		vector<int>::const_iterator last = nums.begin() + nums.size();
		vector<int> sub_nums(first, last);

		//Recursion.
		get_head_to_string(sub_nums);
	}

	vector<string> result;
};
