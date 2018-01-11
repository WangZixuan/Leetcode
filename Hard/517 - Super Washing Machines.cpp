/*


Super Washing Machines


You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty. 
For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time . 
Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.
Example1 
    Input: [1,0,5]

    Output: 3

    Explanation: 
    1st move:    1     0 <-- 5    =>    1     1     4
    2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
    3rd move:    2     1 <-- 3    =>    2     2     2   
Example2 
    Input: [0,3,0]

    Output: 2

    Explanation: 
    1st move:    0 <-- 3     0    =>    1     2     0    
    2nd move:    1     2 --> 0    =>    1     1     1     
Example3 
    Input: [0,2,0]

    Output: -1

    Explanation: 
    It's impossible to make all the three washing machines have the same number of dresses. 

Note:
The range of n is [1, 10000].
The range of dresses number in a super washing machine is [0, 1e5].

@author Zixuan
@date   2018/1/11
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
    int findMinMoves(vector<int>& machines) 
    {
        auto sum = 0; 
        for(int i: machines) 
            sum+=i;
        if(sum%machinessize()!=0) 
            return -1;
        int avg = sum/machines.size(), cnt = 0, max = 0;
        for(int load: machines)
        {
            cnt += load-avg; //load-avg is "gain/lose"
            max = max(max(max, abs(cnt)), load-avg);
        }
        return max;

    }
};