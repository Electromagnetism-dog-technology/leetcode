#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//µ¥µ÷Õ»
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int len = T.size();
		stack<int>s;
		vector<int>res(len);
		for (int i = 0; i < len; i++)
		{
			while (!s.empty() && (T[i] > T[s.top()]))
			{
				int pre = s.top();
				res[pre] = i - pre;
				s.pop();
			}

			s.push(i);
				

		}

		return res;
	}
};

int main()
{
	vector<int>T = { 73, 74, 75, 71, 69, 72, 76, 73 };
	Solution newsolution;
	vector<int>result = newsolution.dailyTemperatures(T);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ",";
	}
	system("pause");
	return EXIT_SUCCESS;
}