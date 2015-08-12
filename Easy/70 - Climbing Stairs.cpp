/*

Climbing Stairs 


You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

@author Zixuan
@date	2015/8/12
*/

class Solution 
{
public:
    int climbStairs(int n)
	{
		//In a recursive way.
		//Says it exceeds the time.
        /*
        if (1 == n || 0 == n)
			return 1;
		else
			return climbStairs(n - 1) + climbStairs(n - 2);
		*/
		
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		for (int i = 2; i <= n; ++i)
			v.push_back(v[i - 2] + v[i - 1]);
		return v[n];
    }
};