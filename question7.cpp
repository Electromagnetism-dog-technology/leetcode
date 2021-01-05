#include<iostream>
#include<vector>
#include<string>
using namespace std;

//1��������������ʱ�����ƣ�
class Solution1 {
public:
	int reverse(int x) {
		int res = 0;

		int cnt = CalcBit(x);
		while (cnt > 0)
		{
			int num = x % 10;
			x = (x - num) / 10;
			res = res + num * pow(10, cnt - 1);
		}

		return res;
		
	}

	int CalcBit(int num)//����num��λ��
	{
		int cnt = 0;
		while (num / 10 != 0)
		{
			num = num / 10;
			cnt++;
		}
		cnt = cnt + 1;//num��λ��

		return cnt;
	}
};

//2���Ľ��ı����������������⣩
class Solution2 {
public:
	int reverse(int x) {
		int res = 0;

		while (x != 0)
		{
			int num = x % 10;
			x = x / 10;
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)) return 0;
			if (res < INT_MIN / 10 || (res == INT_MIN / 10 && num < -8)) return 0;

			res = res * 10 + num;
		}

		return res;

	}
};

int main()
{
	int x = -123;
	Solution2 newsolution;
	int res = newsolution.reverse(x);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}