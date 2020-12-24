#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1����̬�滮
//��dp[i]��ʾ�� i �����֮����ۼ��������
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
		{
			return 0;
		}
		vector<vector<int>>dp(n,vector<int>(3));
		dp[0][0] = -prices[0];
		for (int i = 1; i < n; i++)
		{
			//0��ʾӵ��һ֧��Ʊ��״̬
			dp[i][0] = max(dp[i - 1][0], dp[i-1][2]-prices[i]);
			//1��ʾδӵ�й�Ʊ���Ҵ����䶳�ڵ����
			dp[i][1] = dp[i - 1][0] + prices[i];
			//2��ʾδӵ�й�Ʊ����δ�����䶳�ڵ����(δ�����κβ������������춼���䶳��
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
		}
		
		return max(dp[n - 1][1], dp[n - 1][2]);
	}
};



int main()
{
	vector<int>prices = { 1,2,3,0,2 };
	Solution newsoluiton;
	int res = newsoluiton.maxProfit(prices);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}