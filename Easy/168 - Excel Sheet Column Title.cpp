/*


Excel Sheet Column Title 


Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
@author Zixuan
@date	2015/8/26
*/

#include <string>
using namespace std;
class Solution 
{
public:
    string convertToTitle(int n) 
	{
		//See http://blog.csdn.net/u012162613/article/details/42059591
		//This problem really pissed me off...

		//Z		- 26,
		//ZZ	- 26+26*26
		//ZZZ	- 26+26*26+26*26*26
		//......

		string str;

		while (n)
		{
            int r = n % 26;
            n = n / 26;
            if (0 == r)
			{  
                str += 'Z';
                --n;//Amazing...
            }
			else
                str += (r - 1 + 'A');
		}
		
		reverse(str.begin(), str.end());
	
		return str;
    }
};
