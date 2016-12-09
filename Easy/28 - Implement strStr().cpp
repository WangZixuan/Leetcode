/*


Implement strStr().


Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

@author Zixuan
@date 	2015/8/10
*/

class Solution 
{
public:
    int strStr(string haystack, string needle) 
	{
		int haystackSize = haystack.size();
		int needleSize = needle.size();

		int index = 0;
		for (index = 0; index < haystackSize - needleSize + 1; ++index)
			if (0 == needle.compare(haystack.substr(index, needleSize)))
				return index;
		return -1;
    }
};
