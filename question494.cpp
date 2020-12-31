#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1、暴力解法（DFS）（超出时间限制）
class Solution1 {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		return dfs(nums, S, 0);
	}

	int dfs(vector<int>& nums, int S, int left)
	{
		int n = nums.size();
		if (S == 0 && left == n)
			return 1;
		if (left >= n)
			return 0;
		int res = 0;
		res += dfs(nums, S - nums[left], left + 1);
		res += dfs(nums, S + nums[left], left + 1);
		return res;
	}
};

//2、动态规划
//正数集的和的两倍 == 等于目标和 + 序列总和
//所以问题就转换成了，找到一个正数集P，其和的两倍等于目标和 + 序列总和
class Solution2 {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		long sum = 0;
		for (const int &it : nums) sum += it;
		if ((S + sum) % 2 == 1 || S > sum) return 0;
		S = (S + sum) / 2;
		int *dp = new int[S + 1];
		memset(dp, 0, (S + 1) * sizeof(int));
		dp[0] = 1;
		for (const int &it : nums) {
			for (int j = S; j >= it; j--)
				dp[j] += dp[j - it];
		}
		int ans = dp[S];
		delete[] dp;
		return ans;
	}
};



int main()
{
	vector<int> nums = {1,1,1,1,1};
	int S = 3;
	Solution1 newsolution;
	int res = newsolution.findTargetSumWays(nums, S);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}