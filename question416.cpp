#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

//1����̬�滮
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();

		if (n < 2)
		{
			return false;
		}

		int sum = accumulate(nums.begin(), nums.end(), 0);
		//�����Ϊ�������򲻿��ܲ�ֳ���������Ӽ�
		if (sum % 2 == 1)
		{
			return false;
		}

		int maxNum = *max_element(nums.begin(), nums.end());
		int target = sum / 2;
		//�����������ں͵�һ�룬�򲻿��ܲ�ֳ���������Ӽ�
		if (maxNum > target) {
			return false;
		}

		vector<vector<int>>dp(n,vector<int>(target+1,0));
		for (int i = 0; i < n; i++)
		{
			dp[i][0] = true;
		}
		dp[0][nums[0]] = true;

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= target; j++)
			{
				if (j >= nums[i])
				{
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
				}

				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[n - 1][target];

		
	}
};


int main()
{
	vector<int> nums = { 1, 5, 11, 5 };
	Solution newsolution;
	bool res = newsolution.canPartition(nums);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}