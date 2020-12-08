#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int maxnum = 0, len = s.length();
		vector<int>dp(len, 0);

		for (int i = 0; i < len; i++)
		{
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				}
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				}
				maxnum = max(maxnum, dp[i]);
			}
		}

		return maxnum;
	}
};

int main()
{
	string s = "(()";
	Solution newsolution;
	int res = newsolution.longestValidParentheses(s);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}