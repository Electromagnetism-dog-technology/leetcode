#include<iostream>
#include<vector>
#include<string>
using namespace std;

//��̬�滮

//��ʼ״̬��
//
//dp[i][i] = 1; //�����ַ��ǻ��Ĵ�
//dp[i][i + 1] = 1 if s[i] = s[i + 1]; //����������ͬ�ַ��ǻ��Ĵ�

//ת��״̬��
//dp[i][j] = 1 if s[i] = s[j]&& dp[i+1][j-1]; //����������ͬ�ַ��ǻ��Ĵ�
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<int>>dp(n, vector<int>(n));
		string res;

		for(int len = 0; len < n; len++)
		{
			for (int i = 0; i + len < n; i++)
			{
				int j = i + len;

				if (len == 0)
				{
					dp[i][j] = 1;
				}

				else if (len == 1)
				{
					dp[i][j] = (s[i] == s[j]);
				}
				
				else
				{
					dp[i][j] = (s[i] == s[j]&&dp[i+1][j-1]);
				}

				if (dp[i][j] && len + 1 > res.size())//�ж�������Ӵ�
				{
					res = s.substr(i, len + 1);
				}
			}
		}

		return res;
	}
};

int main()
{
	string s = "babad";
	Solution newslution;
	string res = newslution.longestPalindrome(s);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}