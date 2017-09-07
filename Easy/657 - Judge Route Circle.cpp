/*


Judge Route Circle


Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
Example 1:
	Input: "UD"
	Output: true

Example 2:
	Input: "LL"
	Output: false

@author Zixuan
@date	2017/9/7
*/

#include <string>
using namespace std;

class Solution 
{
public:
	bool judgeCircle(string moves) 
	{
		auto horizontal = 0;
		auto vertical = 0;
		for (auto c : moves)
			if (c == 'U')
				++vertical;
			else if (c == 'D')
				--vertical;
			else if (c == 'L')
				++horizontal;
			else
				--horizontal;

			return 0 == horizontal && 0 == vertical;
	}
};