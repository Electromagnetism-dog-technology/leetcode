#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

//1.辅助数组法（超时）
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		s.push(x);
	}

	void pop() {
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		vector<int>vec;
		stack<int>s1 = s;
		while (!s1.empty())
		{
			int p = s1.top();
			vec.push_back(p);
			s1.pop();
		}
		
		sort(vec.begin(), vec.end());

		return vec[0];
	}

private:
	stack<int>s;

};

//2.辅助栈法
class MinStack2 {
public:
	/** initialize your data structure here. */
	MinStack2() {

	}

	void push(int x) {
		s.push(x);

		if (help.empty() || x <= help.top())
			help.push(x);
		if (x > help.top())
			help.push(help.top());
	}

	void pop() {
		s.pop();
		help.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return help.top();
	}

private:
	stack<int>s,help;

};

int main()
{
	MinStack2 *minStack = new MinStack2();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	cout << minStack->getMin() << endl;
	minStack->pop();
	cout << minStack->top() << endl;
	cout << minStack->getMin() << endl;

	return EXIT_SUCCESS;
}