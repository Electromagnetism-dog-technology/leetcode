#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//动态规划
//用 dp[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。
//状态转移方程为：
//如果 A 和 B 的最后一个字母相同：dp[i][j] = min(dp[i][j - 1] + 1，dp[i - 1][j - 1], dp[i-1][j] + 1);
//如果 A 和 B 的最后一个字母不同：dp[i][j] = min(dp[i][j - 1] + 1，dp[i - 1][j - 1]+1, dp[i-1][j] + 1);
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>>dp(m+1, vector<int>(n+1));

		// 有一个字符串为空串
		if (n * m == 0) return n + m;

		for (int i = 0; i < m + 1; i++)
		{
			dp[i][0] = i;
		}

		for (int j = 0; j < n + 1; j++)
		{
			dp[0][j] = j;
		}

		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (word1[i - 1] != word2[j - 1]) dp[i - 1][j - 1] += 1;
				dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j - 1], dp[i-1][j] + 1));
			}
		}

		return dp[m][n];
	}
};

int main()
{
	string word1 = "horse";
	string word2 = "ros";
	Solution newsoluiton;
	int res = newsoluiton.minDistance(word1, word2);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}