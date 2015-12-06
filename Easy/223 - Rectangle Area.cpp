/*


Rectangle Area
My Submissions


Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

                     (C,D)
		--------------
		|            | 
		|            |
		|        ----|---------- (G,H)
		|        |   |         |
		--------------         |
	 (A,B)       |             |
	             |             |
				 ---------------
               (E,F)

Assume that the total area is never beyond the maximum possible value of int.


@author Zixuan
@date	2015/12/6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
	{
		//Compute each area.
		int area1 = (int)(abs(A - C)*abs(B - D));
		int area2 = (int)(abs(E - G)*abs(F - H));
		bool horizontalSplit = false;
		bool verticalSplit = false;

		if (min(A, C) >= max(E, G) || max(A, C) <= min(E, G))
			horizontalSplit = true;
		if (min(B, D) >= max(F, H) || max(B, D) <= min(F, H))
			verticalSplit = true;

		if (horizontalSplit || verticalSplit)
			return area1 + area2;

		vector<int> Xes{ A, C, E, G };
		vector<int> Yes{ B, D, F, H };
		sort(Xes.begin(), Xes.end());
		sort(Yes.begin(), Yes.end());

		return area1 + area2 - ((int)(abs(Xes[1] - Xes[2])*abs(Yes[1] - Yes[2])));
	}
};