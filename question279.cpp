#include<iostream>
#include<unordered_set>
#include<Windows.h>
using namespace std;

//DFS法（超出时间限制）
class Solution1 {
public:
	int numSquares(int n) {
		unordered_set<int>squares;
		int s = sqrt(n);
		for (int i = 1; i <= s; i++)
		{
			squares.insert(i*i);
		}

		return minNumSquares(n, squares);

	}

	int minNumSquares(int n, unordered_set<int>squares)
	{
		if (squares.count(n))
		{
			return 1;
		}

		int minNum = INT_MAX;
		for (auto square : squares)
		{
			if (n > square)
			{
				minNum = min(minNum, minNumSquares(n - square, squares) + 1);
			}
		}

		return minNum;
	}
};

//2、数学法
class Solution2 {
public:
	int numSquares(int n) {
		vector<int> result(n + 1, 0x7FFFFFFF); // 每个数的最优解都存在result数组里
		result[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; i - j * j >= 0; j++) {  // 观察比N小的数，且符合N = IxI + N'的数值
				result[i] = min(result[i], result[i - j * j] + 1); // 把最优解（最小值）+ 1 写入result
			}
		}
		return result[n];
	}
};

int main()
{
	int x = 12;
	Solution1 newsolution;
	int y = newsolution.numSquares(x);
	cout << y << endl;
	system("pause");
	return EXIT_SUCCESS;
}