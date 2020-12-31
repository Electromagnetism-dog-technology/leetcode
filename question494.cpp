#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1�������ⷨ��DFS��������ʱ�����ƣ�
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

//2����̬�滮
//�������ĺ͵����� == ����Ŀ��� + �����ܺ�
//���������ת�����ˣ��ҵ�һ��������P����͵���������Ŀ��� + �����ܺ�
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