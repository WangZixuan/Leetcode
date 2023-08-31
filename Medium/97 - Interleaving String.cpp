/*


Interleaving String


Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m
substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.


Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.


Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.


Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

@author Zixuan
@date	2023/8/31

*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
    // Reference: https://leetcode.com/problems/interleaving-string/solutions/3956393/99-78-2-approaches-dp-recursion/
    bool isInterleave(string s1, string s2, string s3)
    {
        const unsigned length1 = s1.length();
        const unsigned length2 = s2.length();

        if (length1 + length2 != s3.length())
            return false;

        // dp[i][j] to represent whether the substring s3[0:i+j] can be formed by interleaving s1[0:i] and s2[0:j].
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i < length1 + 1; ++i)
            dp[i][0] = dp[i - 1][0] & s1[i - 1] == s3[i - 1];

        for (int i = 1; i < length2 + 1; ++i)
            dp[0][i] = dp[0][i - 1] & s2[i - 1] == s3[i - 1];

        for (int i = 1; i < length1 + 1; ++i)
            for (int j = 1; j < length2 + 1; ++j)
                dp[i][j] = (dp[i - 1][j] & s1[i - 1] == s3[i + j - 1]) | (dp[i][j - 1] & s2[j - 1] == s3[i + j - 1]);

        return dp[length1][length2];
    }
};
