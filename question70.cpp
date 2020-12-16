#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//动态规划
//转移方程：dp[i] = dp[i-1]+ dp[i-2]
class Solution {
public:
	int climbStairs(int n) {
		vector<int>dp(n + 1, 0);//由于0~n都要计算，所以要分配n+1个空间
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
};

int main()
{
	Solution newsolution;
	int res = newsolution.climbStairs(3);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}