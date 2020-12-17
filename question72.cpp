#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//��̬�滮
//�� dp[i][j] ��ʾ A ��ǰ i ����ĸ�� B ��ǰ j ����ĸ֮��ı༭���롣
//״̬ת�Ʒ���Ϊ��
//��� A �� B �����һ����ĸ��ͬ��dp[i][j] = min(dp[i][j - 1] + 1��dp[i - 1][j - 1], dp[i-1][j] + 1);
//��� A �� B �����һ����ĸ��ͬ��dp[i][j] = min(dp[i][j - 1] + 1��dp[i - 1][j - 1]+1, dp[i-1][j] + 1);
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>>dp(m+1, vector<int>(n+1));

		// ��һ���ַ���Ϊ�մ�
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