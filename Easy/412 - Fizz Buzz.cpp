/*


Fizz Buzz Add to List


Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output "Fizz" instead of the number and for the multiples of five output "Buzz". For numbers which are multiples of both three and five output "FizzBuzz".
Example:
	n = 15,

	Return:
	[
	"1",
	"2",
	"Fizz",
	"4",
	"Buzz",
	"Fizz",
	"7",
	"8",
	"Fizz",
	"Buzz",
	"11",
	"Fizz",
	"13",
	"14",
	"FizzBuzz"
	]

@author Zixuan
@date	2016/11/27
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n)
	{
		vector<string> result;
		for (auto i = 1; i <= n; ++i)
			if (0 == i % 15)
				result.push_back("FizzBuzz");
			else if (0 == i % 5)
				result.push_back("Buzz");
			else if (0 == i % 3)
				result.push_back("Fizz");
			else
				result.push_back(to_string(i));
		return result;
	}
};