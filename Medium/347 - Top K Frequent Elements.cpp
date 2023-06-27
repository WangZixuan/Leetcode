/*


Top K Frequent Elements


Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

@author Zixuan
@date	2023/6/27

*/

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> numCount;
        for (auto num : nums)
        {
            numCount[num]++;
        }

        // pair<num, itsCount>
        vector<pair<int, int>> pairs(k);

        map<int, int>::iterator it = numCount.begin();

        while (it != numCount.end())
        {
            if (it->second > pairs[0].second)
            {
                pairs[0].first = it->first;
                pairs[0].second = it->second;

                // sort
                sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
            }

            ++it;
        }

		vector<int> result(k);
        for (int i = 0; i < k; ++i)
        {
			result[i] = pairs[i].first;
        }

        return result;
    }
};
