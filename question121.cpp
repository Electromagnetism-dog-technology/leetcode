#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1��������
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				res = max(res, prices[j] - prices[i]);
			}
		}
		return res;
	}
};

//2����̬�滮
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
			return 0;
		
		int cur = prices[1] - prices[0];
		int profit = prices[1] - prices[0];

		for (int i = 2; i < n; i++) {
			int temp = prices[i] - prices[i - 1];
			cur = max(cur + temp, temp); //���µ�ǰ�������
			profit = max(profit, cur); //�������յ��������
		}

		return profit > 0 ? profit : 0;
	}
};

int main()
{
	vector<int> prices = { 7,1,5,3,6,4 };
	Solution2 newsolution;
	int res = newsolution.maxProfit(prices);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}