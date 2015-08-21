/*


Min Stack


Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

@author Zixuan
@date	2015/8/21
*/


#include <stack>
using namespace std;

class MinStack 
{
public:
    void push(int x) 
	{
		s.push(x);

		if (1 == s.size() || x < minValueS.top())
			minValueS.push(x);
		else
			minValueS.push(minValueS.top());
    }

    void pop() 
	{
		s.pop();
		minValueS.pop();
    }

    int top() 
	{
		return s.top();
    }

    int getMin() 
	{
		if (!s.empty())
			return minValueS.top();
    }

private:
	//Here I implement std::stack to avoid reinventing the wheel.
	//See https://en.wikipedia.org/wiki/Reinventing_the_wheel
	stack<int> s;

	//Amazing design!
	//See http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
	stack<int> minValueS;
};
