#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<int>nums;
		stack<string>strs;
		int number = 0;
		string result = "";

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				number = number * 10 + s[i] - '0';
			}

			else if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z'))
			{
				result = result + s[i];
			}

			else if (s[i] == '[')
			{
				nums.push(number);
				strs.push(result);
				number = 0;
				result = "";
			}

			else
			{
				int times = nums.top();
				nums.pop();
				for (int j = 0; j < times; j++)
				{
					strs.top() += result;
				}
				result = strs.top();
				strs.pop();
				
			}
		}

		return result;
	}
};

int main()
{
	string s = "3[a2[c]]";
	Solution newsolution;
	string result = newsolution.decodeString(s);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "";
	}
	system("pause");
	return EXIT_SUCCESS;
}