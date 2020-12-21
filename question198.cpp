#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//自己写的动态规划
//要先排除n=0,1,2,3四种情况
//然后动态方程为：
//dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
//maxnum = max(maxnum, dp[i]);
class Solution1 {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return nums[0];
		}

		if (n == 2)
		{
			return max(nums[0], nums[1]);
		}
		if (n == 3)
		{
			return max(nums[1], nums[0] + nums[2]);
		}

		vector<int>dp(n);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		dp[2] = max(nums[1], nums[0] + nums[2]);
		int maxnum = max(nums[1], nums[0] + nums[2]);
		for (int i = 3; i < n; i++)
		{
			dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
			maxnum = max(maxnum, dp[i]);

		}
		return maxnum;
	}
};

//官方动态规划
//动态方程为：
//dp[i] = max(dp[i - 2]+ nums[i]，dp[i-1]);

class Solution2 {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return nums[0];
		}

		vector<int>dp(n);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++)
		{
			dp[i] = max(dp[i - 2] + nums[i],dp[i - 1]);

		}
		return dp[n-1];
	}
};

int main()
{
	vector<int>nums = {2,7,9,3,1};
	Solution2 newsolution;
	int res = newsolution.rob(nums);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}