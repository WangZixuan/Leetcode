/*


Keys and Rooms


There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room.
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
Initially, all the rooms start locked (except for room 0).
You can walk back and forth between rooms freely.
Return true if and only if you can enter every room.

Example 1:
	Input: [[1],[2],[3],[]]
	Output: true
	Explanation:
	We start in room 0, and pick up key 1.
	We then go to room 1, and pick up key 2.
	We then go to room 2, and pick up key 3.
	We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:
	Input: [[1,3],[3,0,1],[2],[0]]
	Output: false
	Explanation: We can't enter the room with number 2.
	Note:
	1 <= rooms.length <= 1000
	0 <= rooms[i].length <= 1000
	The number of keys in all rooms combined is at most 3000.

@author Zixuan
@date	2018/6/11
*/

#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms)
	{
		//BFS
		queue<int> q_keys;
		set<int> visitedRooms;

		for (auto k : rooms[0])
			q_keys.push(k);
		visitedRooms.insert(0);

		while (!q_keys.empty())
		{
			auto room = q_keys.front();

			if (visitedRooms.find(room) == visitedRooms.end())
			{
				for (auto k : rooms[room])
					q_keys.push(k);
			}

			visitedRooms.insert(room);

			q_keys.pop();
		}

		return visitedRooms.size() == rooms.size();
	}
};