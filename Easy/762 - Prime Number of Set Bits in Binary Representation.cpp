/*


Prime Number of Set Bits in Binary Representation 


Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation. 
(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.) 

Example 1:
Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)

Example 2:
Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)

Note:
L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.

@author Zixuan
@date	2018/1/14
*/
class Solution 
{
public:
	int countPrimeSetBits(int L, int R)
	{
		auto count = 0;
		for (auto i = L; i <= R; ++i)
			if (isBitStringContainPrimeNumberOfOnes(i))
				++count;
		return count;
	}

private:
	bool isBitStringContainPrimeNumberOfOnes(int x)
	{
		auto oneCount = 0;
		while (x) 
		{
			if (x & 1)
				++oneCount;
			x >>= 1;
		}

		return IsPrime(oneCount);
		
	}

	//Reference: https://stackoverflow.com/questions/4424374/determining-if-a-number-is-prime
	int power(int a, int n, int mod)
	{
		int power = a, result = 1;

		while (n)
		{
			if (n & 1)
				result = (result*power) % mod;
			power = (power*power) % mod;
			n >>= 1;
		}
		return result;
	}

	bool witness(int a, int n)
	{
		int t, u, i;
		int prev, curr;

		u = n / 2;
		t = 1;
		while (!(u & 1))
		{
			u /= 2;
			++t;
		}

		prev = power(a, u, n);
		for (i = 1; i <= t; ++i)
		{
			curr = (prev*prev) % n;
			if ((curr == 1) && (prev != 1) && (prev != n - 1))
				return true;
			prev = curr;
		}
		if (curr != 1)
			return true;
		return false;
	}

	inline bool IsPrime(int number)
	{
		if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))
			return (false);

		if (number<1373653)
		{
			for (int k = 1; 36 * k*k - 12 * k < number; ++k)
				if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
					return (false);

			return true;
		}

		if (number < 9080191)
		{
			if (witness(31, number)) return false;
			if (witness(73, number)) return false;
			return true;
		}


		if (witness(2, number)) return false;
		if (witness(7, number)) return false;
		if (witness(61, number)) return false;
		return true;

		/*WARNING: Algorithm deterministic only for numbers < 4,759,123,141 (unsigned int's max is 4294967296)
		if n < 1,373,653, it is enough to test a = 2 and 3.
		if n < 9,080,191, it is enough to test a = 31 and 73.
		if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.
		if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.
		if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13.
		if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.*/
	}
};
