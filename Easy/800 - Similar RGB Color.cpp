/*


Similar RGB Color


In the following, every capital letter represents some hexadecimal digit from 0 to f.
The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".
Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.
Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"
Example 1:
	Input: color = "#09f166"
	Output: "#11ee66"
	Explanation:
	The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
	This is the highest among any shorthand color.
Note:
	color is a string of length 7.
	color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
	Any answer which has the same (highest) similarity as the best answer will be accepted.
	All inputs and outputs should use lowercase letters, and the output is 7 characters
	
@author Zixuan
@date	2018/3/19
*/

#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	string similarRGB(string color) 
	{
		vector<int> vec{0, 17, 34, 51, 68, 85, 102, 119, 136, 153, 170, 187, 204, 221, 238, 255};

		string similar("#");
		for (auto i = 0; i < 3;++i)
		{
			auto part = color.substr(2 * i + 1, 2);

			//Remember this!
			//How do we input hex and output dec
			auto value = 0;
			stringstream ss;
			ss << hex << part;
			ss >> value;

			auto index = -1, diff = 255;
			for (auto k = 0; k < vec.size();++k)
				if (abs(vec[k] - value) < diff)
				{
					index = k;
					diff = abs(vec[k] - value);
				}

			char c = index < 10 ? index + '0' : index - 10 + 'a';

			similar += c;
			similar += c;
		}

		return similar;
	}
};

