#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//1.广度优先搜索
class Solution1 {
public:
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };
	queue<pair<int, int>> q;
	vector<vector<char>> flag;

	int numIslands(vector<vector<char>>& grid) {
		
		flag = grid;
		int result=0;
		int xx = grid.size();
		int yy = grid[0].size();
		
		for (int i = 0; i < xx; i++)
		{
			for (int j = 0; j < yy; j++)
			{
				
					flag[i][j] = '0';
					
			}
		}

		for (int i = 0; i < xx; i++)
		{
			for (int j = 0; j < yy; j++)
			{
				if (flag[i][j] =='0' && grid[i][j] == '1')
				{
					//广度优先搜索
					flag[i][j] = '1';
					q.push({ i,j });
					SearchLand(grid, xx, yy);
					result++;

				}
			}
		}
		return result;
	}

	void SearchLand(vector<vector<char>>& grid, int xx, int yy)
	{
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ax = x + dx[i];
				int ay = y + dy[i];

				if (ax >= 0 && ax < xx && ay >= 0 && ay < yy) {
					if (flag[ax][ay] == '0' && grid[ax][ay] == '1')
					{
						flag[ax][ay] = '1';
						q.push({ ax,ay });
					}
				}
			}
		}
	}
};

//2.深度优先搜索
class Solution2 {

	void SearchLand(vector<vector<char>>& grid, int i, int j)
	{
		if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0') return;
		grid[i][j] = '0';
		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };
		for (int index = 0; index < 4; index++)
		{
			SearchLand(grid, i + di[index], j + dj[index]);
		}
		return;

	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
	
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					//深度优先搜索
					SearchLand(grid, i, j);
					result++;

				}
			}
		}

		return result;

	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}