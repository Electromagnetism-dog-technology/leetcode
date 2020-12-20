#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//��̬�滮
//����ֱ����dp[i]=max(dp[i-1]*nums[i],nums[i]);
//��Ϊ������Ӱ��˻�������Ҫ��minF[i]���洢������������ֵ��
class Solution {
public:
	int maxProduct(vector<int>& nums) {
	
		int maxnum = nums[0];
		int n = nums.size();
		vector <int> maxdp(n), mindp(n);
		maxdp[0] = mindp[0]= nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			maxdp[i] = max(maxdp[i - 1] * nums[i], max(nums[i], mindp[i - 1] * nums[i]));
			mindp[i] = min(mindp[i - 1] * nums[i], min(nums[i], maxdp[i - 1] * nums[i]));
			maxnum = max(maxnum, maxdp[i]);
		}

		return maxnum;
	}
};

int main()
{
	vector<int>nums = { -2,3,-4 };
	Solution newsolution;
	int res = newsolution.maxProduct(nums);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}