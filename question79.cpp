#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool result;
	bool getCombinations(vector<vector<char>>& board,int l,int r, string word,int digit)
	{
		if (board[l][r] != word[digit])
		{
			return false;
		}

		if (digit == word.size()-1)
		{
			return true;
		}

		char tmp = board[l][r];
		board[l][r] = 0; // 避免该位重复使用
		digit++;

		if ((l < board.size() - 1 && getCombinations(board, l + 1, r, word, digit)) || (r < board[0].size() - 1 && getCombinations(board, l, r + 1, word, digit))
			|| (l > 0 && getCombinations(board, l - 1, r, word, digit)) || (r > 0 && getCombinations(board, l, r - 1, word, digit)))
		{
			return true;// 其中一条能走通，就算成功
		}

		board[l][r]=tmp;// 如果都不通，则回溯上一状态
		return false;
		

	}

	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (getCombinations(board, i, j, word, 0))
				{
					return true;
				}
				
			}
		}
			
		return false;
	}
};

int main()
{
	vector<vector<char>>board =
	{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	string word = "ABCCED";
	Solution newsolution;
	bool result=newsolution.exist(board,word);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}