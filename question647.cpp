#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1、中心扩展法
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

//2、动态规划法
//dp[i][j]表示[i, j]范围内字符是否为回文串，i从后向前遍历，j从i位置向后遍历，如果s[i] == s[j]，那么i和j满足下面两个条件之一，则dp[i][j] = true。
//
//如果i和j相邻或只隔着一个字符，则dp[i][j] = true
//否则如果dp[i + 1][j - 1] = true，则dp[i][j] = true


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