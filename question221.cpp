#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>>dp(m, vector<int>(n));

		if (m == 0 || n == 0) {
			return 0;
		}

		int maxnum = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1') {
					if (i == 0 || j == 0) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
					maxnum = max(maxnum, dp[i][j]);
				}

				
			}
		}

		return maxnum*maxnum;


	}
};

int main()
{
	vector<vector<char>>matrix = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
	Solution newsolution;
	int res = newsolution.maximalSquare(matrix);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}