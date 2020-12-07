#include<iostream>
#include<string>
#include<regex>
using namespace std;

//1、调库法
class Solution1 {
public:
	bool isMatch(string s, string p) {
		return regex_match(s, regex(p));
	}


};

//2、动态规划
//如果 p的第 j 个字符是一个小写字母，那么我们必须在 s中匹配一个相同的小写字母
//如果 p 的第 j 个字符是 *
//本质上只会有两种情况：
//匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；
//不匹配字符，将该组合扔掉，不再进行匹配。
//动态规划的边界条件为 f[0][0] = true，即两个空字符串是可以匹配的。
class Solution2 {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();

		auto matches = [&](int i, int j)
		{
			if (i == 0)
				return false;
			if (p[j - 1] == '.')
				return true;

			return s[i - 1] == p[j - 1];
		};

		vector<vector<int>> f(m + 1, vector<int>(n + 1));

		f[0][0] = true;

		for (int i = 0; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (p[j - 1] == '*')
				{
					f[i][j] |= f[i][j - 2];

					if (matches(i, j - 1))
					{
						f[i][j] |= f[i - 1][j];
					}
				}

				else {
					if (matches(i, j)) {
						f[i][j] |= f[i - 1][j - 1];
					}
				}

			}
		}

		return f[m][n];
	}


};

int main()
{
	string s = "aab" , p = "c*a*b";
	Solution2 newsolution;
	bool res = newsolution.isMatch(s, p);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}