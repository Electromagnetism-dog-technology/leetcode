#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1��������չ��
class Solution1 {
public:
	int countSubstrings(string s) {
		int res = 0;
		int len = s.size();
		int n = 2 * len - 1;
		for (int i = 0; i < n; i++)
		{
			int l = i / 2;
			int r = i / 2 + i % 2;
			while (l >= 0 && r < n&&s[l] == s[r])
			{
				l--;
				r++;
				res++;
			}
		}

		return res;
	}
};

//2����̬�滮��
//dp[i][j]��ʾ[i, j]��Χ���ַ��Ƿ�Ϊ���Ĵ���i�Ӻ���ǰ������j��iλ�������������s[i] == s[j]����ôi��j����������������֮һ����dp[i][j] = true��
//
//���i��j���ڻ�ֻ����һ���ַ�����dp[i][j] = true
//�������dp[i + 1][j - 1] = true����dp[i][j] = true


class Solution2 {
public:
	int countSubstrings(string s) {
		int res = 0;
		int len = s.size();
		vector<vector<bool>>dp(len,vector<bool>(len));
		for (int i = len - 1; i >= 0; i--)
		{
			for (int j = i; j < len; j++)
			{
				dp[i][j] = (s[i] == s[j]) && ((j - i <= 2) || dp[i + 1][j - 1]);
				if (dp[i][j])
					res++;
			}
		}
		return res;
	}
};

int main()
{
	string s = "sss";
	Solution2 newsoluiton;
	int res = newsoluiton.countSubstrings(s);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}