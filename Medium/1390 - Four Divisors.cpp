/*


Four Divisors


Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

Example 1:
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Example 2:
Input: nums = [21,21]
Output: 64

Example 3:
Input: nums = [1,2,3,4,5]
Output: 0

Constraints:
1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5

@author Zixuan
@date	2026/1/4
*/

#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        map<int, int> valid;
        int sum = 0;

        for (auto num : nums)
        {
            if (valid.find(num) != valid.end())
                sum += valid[num];
            else
            {
                set<int> divisors;
                int result = static_cast<int>(sqrt(num));
                for (int i = 1; i <= result; ++i)
                {
                    if (num % i == 0)
                    {
                        divisors.insert(i);
                        divisors.insert(num / i);
                    }

                    if (divisors.size() >= 5)
                        continue;
                }

                if (divisors.size() == 4)
                {
                    int s = accumulate(divisors.begin(), divisors.end(), 0);
                    valid.insert(make_pair(num, s));
                    sum += s;
                }
            }
        }

        return sum;
    }
};
