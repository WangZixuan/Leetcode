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
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

@author Zixuan
@date	2023/8/24

*/

#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution1 
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

struct PriorityQueueItem
{
    int num;
    int count;

    PriorityQueueItem(int num, int count) : num(num), count(count) { };
};

struct ComparePriorityQueueItem
{
    bool operator()(PriorityQueueItem const& p1, PriorityQueueItem const& p2)
    {
        // pay attention to the ">"
        return p1.count > p2.count;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        priority_queue<PriorityQueueItem, vector<PriorityQueueItem>, ComparePriorityQueueItem> queues;

        size_t i = 0;
        while (i < nums.size())
        {
            int count = 1;
            int current_num = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == current_num)
            {
                current_num = nums[i];
                ++i;
                ++count;
            }

            if (queues.size() < k)
            {
                queues.push(PriorityQueueItem(current_num, count));
            }
            else if (queues.top().count < count)
            {
                // Pop the least count number
                queues.pop();
                queues.push(PriorityQueueItem(current_num, count));
            }

            ++i;
        }

        vector<int> result(k);

        for (int index = 0; index < k; ++index)
        {
            result[index] = queues.top().num;
            queues.pop();
        }

        return result;
    }
};
