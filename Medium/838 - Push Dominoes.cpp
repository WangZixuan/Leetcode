/*


Push Dominoes


There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.
 

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.


Example 2:

Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 

Constraints:

n == dominoes.length
1 <= n <= 10^5
dominoes[i] is either 'L', 'R', or '.'.

@author Zixuan
@date   2022/2/22
*/

#include <string>
using namespace std;

class Solution
{
public:
    // https://leetcode.com/problems/push-dominoes/discuss/132332/C++JavaPython-Two-Pointers
    string pushDominoes(string dominoes)
    {
        // Mock L in the beginning and R in the end
        const string newDominoes = "L" + dominoes + "R";
        string result = "";

        // Interate to get the range
        for (int start = 0, end = 1; end < newDominoes.length(); ++end) 
        {
            if (newDominoes[end] == '.') 
                continue;

            result += newDominoes[start];

            int middleLength = end - start - 1;
            if (newDominoes[start] == newDominoes[end])
                result += string(middleLength, newDominoes[start]);
            else if (newDominoes[start] == 'L') // && newDominoes[end]=='R'
            {
                result += string(middleLength, '.');
            }
            else // newDominoes[start] == 'R' && newDominoes[end]=='L'
            {
                if (middleLength % 2 == 0)
                    result += string(middleLength / 2, 'R') + string(middleLength / 2, 'L');
                else
                    result += string(middleLength / 2, 'R') + "." + string(middleLength / 2, 'L');
            }

            // Reset start, note the newDominoes[end] will be calculated in next iteration
            start = end;
        }

        return result.substr(1); // Remove the front
    }
};
