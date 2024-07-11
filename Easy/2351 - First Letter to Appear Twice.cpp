/*


First Letter to Appear Twice


Given a string s consisting of lowercase English letters, return the first letter to appear twice.

Note:

A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
s will contain at least one letter that appears twice.
 

Example 1:

Input: s = "abccbaacz"
Output: "c"
Explanation:
The letter 'a' appears on the indexes 0, 5 and 6.
The letter 'b' appears on the indexes 1 and 4.
The letter 'c' appears on the indexes 2, 3 and 7.
The letter 'z' appears on the index 8.
The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.

Example 2:

Input: s = "abcdd"
Output: "d"
Explanation:
The only letter that appears twice is 'd' so we return 'd'.
 

Constraints:

2 <= s.length <= 100
s consists of lowercase English letters.
s has at least one repeated letter.

@author Zixuan
@date	2024/07/11
*/

class Solution 
{
public:
    char repeatedCharacter(string s) 
    {
        vector<int> count(26, -10000);

        for (int i = 0; i< s.length(); i++)
        {
            if (count[s[i] - 'a'] == -10000)
                count[s[i] - 'a'] = i;
            else if (count[s[i] - 'a'] >= 0)
                count[s[i] - 'a'] = -i;
            else
                continue;
        }

        char result = *s.begin();
        int currentMax = -10000;

        for (char c : s)
            if (count[c - 'a'] < 0 && count[c - 'a'] != -10000)
            {
                if (currentMax < count[c - 'a'])
                {
                    currentMax = count[c - 'a'];
                    result = c;
                }
            }

		return result;
    }
};