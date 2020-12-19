#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

//¶¯Ì¬¹æ»®
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool>dp(n+1,true);

		auto wordDictset = unordered_set<string>();
		for (auto c : wordDict)
		{
			wordDictset.insert(c);
		}

		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (dp[j] && wordDictset.find(s.substr(j, i - j))!=wordDictset.end())
				{
					dp[i] = true;
					break;
				}
			}
		}

		return dp[n];
	}
};

int main()
{
	string s = "leetcode";
	vector<string>wordDict = { "leet","code" };
	Solution newsolution;
	bool res = newsolution.wordBreak(s, wordDict);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}