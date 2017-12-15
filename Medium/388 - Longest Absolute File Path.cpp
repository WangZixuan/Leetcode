/*


Longest Absolute File Path


Suppose we abstract our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
	dir
		subdir1
		subdir2
			file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
	dir
		subdir1
			file1.ext
			subsubdir1
		subdir2
			subsubdir2
			file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..

Time complexity required: O(n) where n is the size of the input string.
Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.

@author Zixuan
@data	2017/12/15
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
	int lengthLongestPath(string input)
	{
		auto maxLength = 0;

		vector<int> levelsLength;

		//Scan the input
		for (unsigned i = 0; i < input.length();++i)
		{
			//Get the number of '\t' to get the current level.
			auto currentLevel = 1;
			while (i < input.length() && input[i] == '\t')
			{
				++currentLevel;
				++i;
			}

			auto startIndex = i;
			while (i < input.length() && input[i] != '\n' && input[i] != '\t')
				++i;

			//If it is a file or a folder
			auto thisLevelLength = i - startIndex;
			auto thisLevelName = input.substr(startIndex, thisLevelLength);

			if (thisLevelName.find('.') != string::npos)//File
			{
				//Attention: name can contain spaces.
				auto length = 0;
				for (unsigned j = 0; j < currentLevel - 1;++j)
					length += levelsLength[j] + 1;
				length += thisLevelLength;
				maxLength = max(maxLength, length);
			}
			else//Folder
				if (levelsLength.size() < currentLevel)
					levelsLength.push_back(thisLevelLength);
				else
					levelsLength[currentLevel - 1] = thisLevelLength;
		}

		return maxLength;
	}
};
