/*


Implement Stack using Queues


Implement the following operations of a stack using queues.
? push(x) -- Push element x onto stack.
? pop() -- Removes the element on top of the stack.
? top() -- Get the top element.
? empty() -- Return whether the stack is empty.
Notes:
?You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
?Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
?You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

@author Zixuan
@date	2015/12/12
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack 
{
public:
	// Push element x onto stack.
	void push(int x) 
	{
		main_queue.push(x);
	}

	// Removes the element on top of the stack.
	void pop() 
	{
		clear_temp_queue();
		while (1 != main_queue.size())
		{
			temp_queue.push(main_queue.front());
			main_queue.pop();
		}
		main_queue = temp_queue;
	}

	// Get the top element.
	int top() 
	{
		clear_temp_queue();
		while(1 != main_queue.size())
		{
			temp_queue.push(main_queue.front());
			main_queue.pop();
		}
		auto temp = main_queue.front();
		temp_queue.push(temp);
		main_queue = temp_queue;
		return temp;
	}

	// Return whether the stack is empty.
	bool empty() 
	{
		return main_queue.empty();
	}
private:
	void clear_temp_queue()
	{
		queue<int> empty;
		swap(this->temp_queue, empty);
	}
private:
	queue<int> main_queue;
	queue<int> temp_queue;
};
