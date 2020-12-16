#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//��̬�滮
//ת�Ʒ��̣�dp[i] = dp[i-1]+ dp[i-2]
class Solution {
public:
	int climbStairs(int n) {
		vector<int>dp(n + 1, 0);//����0~n��Ҫ���㣬����Ҫ����n+1���ռ�
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