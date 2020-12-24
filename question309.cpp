#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1、动态规划
//用dp[i]表示第 i 天结束之后的累计最大收益
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
		{
			return 0;
		}
		vector<vector<int>>dp(n,vector<int>(3));
		dp[0][0] = -prices[0];
		for (int i = 1; i < n; i++)
		{
			//0表示拥有一支股票的状态
			dp[i][0] = max(dp[i - 1][0], dp[i-1][2]-prices[i]);
			//1表示未拥有股票，且处于冷冻期的情况
			dp[i][1] = dp[i - 1][0] + prices[i];
			//2表示未拥有股票，且未处于冷冻期的情况(未进行任何操作，接连两天都是冷冻）
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
		}
		
		return max(dp[n - 1][1], dp[n - 1][2]);
	}
};



int main()
{
	vector<int>prices = { 1,2,3,0,2 };
	Solution newsoluiton;
	int res = newsoluiton.maxProfit(prices);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}