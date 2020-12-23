#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1、动态规划
class Solution1 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n,1);
		int maxnum = 1;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
				
			}

			maxnum = max(maxnum, dp[i]);
		}

		return maxnum;
	}
};

//2、二分法
class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums)
	{
		int n = nums.size();
		if (n == 0)return 0;
		if (n == 1)return 1;

		vector<int> dp;
		dp.push_back(nums[0]);
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] > dp[dp.size() - 1])
				dp.push_back(nums[i]);
			else
			{
				auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
				*it = nums[i];
			}
		}
		return dp.size();
	}

};

int main()
{
	vector<int>nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	Solution2 newsolution;
	int res = newsolution.lengthOfLIS(nums);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}