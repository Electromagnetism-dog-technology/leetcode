#include<iostream>
#include<unordered_set>
#include<Windows.h>
using namespace std;

//DFS��������ʱ�����ƣ�
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

//2����ѧ��
class Solution2 {
public:
	int numSquares(int n) {
		vector<int> result(n + 1, 0x7FFFFFFF); // ÿ���������Žⶼ����result������
		result[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; i - j * j >= 0; j++) {  // �۲��NС�������ҷ���N = IxI + N'����ֵ
				result[i] = min(result[i], result[i - j * j] + 1); // �����Ž⣨��Сֵ��+ 1 д��result
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