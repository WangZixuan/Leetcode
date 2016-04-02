/*


Peeking Iterator


Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- 
it essentially peek() at the element that will be returned by the next call to next().


Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

Hint:
1.Think of "looking ahead". You want to cache the next element.
2.Is one variable sufficient? Why or why not?
3.Test your design with call order of peek() before next() vs next() before peek().
4.For a clean implementation, check out Google's guava library source code
<https://github.com/google/guava/blob/703ef758b8621cfbab16814f01ddcc5324bdea33/guava-gwt/src-super/com/google/common/collect/super/com/google/common/collect/Iterators.java#L1125>.

@author Zixuan
@date	2016/4/2
*/

#include <vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator 
{
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		saved_value = 0;
		is_saved = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() 
	{
		if (!is_saved)
		{
			saved_value = Iterator::next();
			is_saved = true;
		}
		return saved_value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
	{
		if (is_saved)
		{
			is_saved =!is_saved;
			return saved_value;
		}
		
		return Iterator::next();
	}

	bool hasNext() const 
	{
		return is_saved || Iterator::hasNext();
	}

private:
	int saved_value;
	bool is_saved;
};