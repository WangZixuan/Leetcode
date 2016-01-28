/*


Implement Queue using Stacks


Implement the following operations of a queue using stacks.
? push(x) -- Push element x to the back of queue.
? pop() -- Removes the element from in front of queue.
? peek() -- Get the front element.
? empty() -- Return whether the queue is empty

@author Zixuan
@date	2016/1/28
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue 
{
public:
	// Push element x to the back of queue.
	void push(int x) 
	{
		main_stack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) 
	{	
		stack<int> temp_stack;
		while (!main_stack.empty())
		{
			auto temp = main_stack.top();
			main_stack.pop();
			temp_stack.push(temp);
		}

		temp_stack.pop();

		while (!temp_stack.empty())
		{
			auto temp = temp_stack.top();
			temp_stack.pop();
			main_stack.push(temp);
		}
		
	}

	// Get the front element.
	int peek(void) 
	{
		stack<int> temp_stack;
		while (!main_stack.empty())
		{
			auto temp = main_stack.top();
			main_stack.pop();
			temp_stack.push(temp);
		}

		auto result = temp_stack.top();

		while (!temp_stack.empty())
		{
			auto temp = temp_stack.top();
			temp_stack.pop();
			main_stack.push(temp);
		}
		return result;
	}

	// Return whether the queue is empty.
	bool empty(void) 
	{
		return main_stack.empty();
	}
private:

	//Used to store data.
	stack<int> main_stack;

};