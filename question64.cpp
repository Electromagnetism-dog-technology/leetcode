#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//¶¯Ì¬¹æ»®
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int len = grid.size();
		int width = grid[0].size();
		vector<vector<int>>dp(len,vector<int>(width,0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < grid.size(); i++)
		{
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}

		for (int j = 1; j < grid[0].size(); j++)
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}

		for (int i = 1; i < grid.size(); i++)
		{
			for (int j = 1; j < grid[0].size(); j++)
			{
				dp[i][j] = min(dp[i][j - 1],dp[i-1][j]) + grid[i][j];
			}
		}

		
		return dp[len - 1][width - 1];
	}
};

int main()
{
	vector<vector<int>> grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
	Solution newsolution;
	int res = newsolution.minPathSum(grid);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}