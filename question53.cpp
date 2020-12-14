#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//动态规划
//状态方程：dp[i] = max(dp[i - 1] + nums[i], nums[i]);
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		vector<int>dp(len, 0);
		dp[0] = nums[0];
		int maxnum = nums[0];
		for (int i = 1; i < len; i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			maxnum = max(maxnum, dp[i]);
		}
		return maxnum;
	}
};

int main()
{
	vector<int> grid = { 1 };
	Solution newsolution;
	int res = newsolution.maxSubArray(grid);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}