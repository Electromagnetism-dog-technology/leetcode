#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

//1、解答错误
class Solution {
public:
	bool isValid(string s) {
		map<char, int>reference;

		reference['{'] = 0;
		reference['['] = 1;
		reference['('] = 2;
		reference[')'] = 3;
		reference[']'] = 4;
		reference['}'] = 5;

		bool result = true;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (reference[s[i]] != 5 - reference[s[len - i-1]])
			{
				result= false;
				break;
			}
		}

		return result;
	}
};

//2、利用栈
class Solution2 {
public:
	bool isValid(string s) {
		//哈希表存储
		unordered_map<char, int> m{ {'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6} };

		//设定栈
		stack<char> st;


		bool result = true;
		int len = s.length();
		//for (int i = 0; i < len; i++)
		//{
		//	//如果为开括号，将其入栈
		//	if (0 <= reference[s[i]] && reference[s[i]] <= 2)
		//	{
		//		st.push(s[i]);
		//	}

		//	//如果栈非空,且栈顶元素与接下来的字符(闭括号)相对应,出栈
		//	else if (!st.empty() && reference[st.top()] == reference[s[i]] - 5)
		//	{
		//		st.pop();
		//	}

		//	//否则俩个条件都不满足,意味着一开始就是个闭括号,或者闭括号多了,没有对应开括号在栈里面
		//	else
		//	{
		//		result = false;
		//		break;
		//	}
		//}

		for (char c : s)
		{
			//如果为开括号,将其入栈
			if (1 <= m[c] && m[c] <= 3)st.push(c);

			//如果栈非空,且栈顶元素与接下来的字符(闭括号)相对应,出栈
			else if (!st.empty() && m[st.top()] == m[c] - 3)st.pop();
			//否则俩个条件都不满足,意味着一开始就是个闭括号,或者闭括号多了,没有对应开括号在栈里面
			else
			{
				result = false;
				break;//这里别忘了啊
			}
		}
		//如果for遍历完后,栈非空,意味着开括号多了,则非法
		if (!st.empty()) 
			result = false;

		return result;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}