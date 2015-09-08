/*


Reverse Bits


Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it? 

@author Zixuan
@date	2015/9/8
*/

#include <iostream>

class Solution
{
public:
	//See http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
	uint32_t reverseBits(uint32_t n) 
	{
		const unsigned int NUMOFBITS = sizeof(n) * 8;//32.
		unsigned int reverseNum = 0;
		
		for (unsigned int i = 0; i < NUMOFBITS; ++i)
			if ((n & (1 << i)))
				reverseNum |= 1 << ((NUMOFBITS - 1) - i);
		return reverseNum;
	}
};