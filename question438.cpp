#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>res;
		string mp(26,0), ms(26,0);
		int len = p.size(), slen = s.size();
		if (slen < len)
			return res;

		for (int i = 0; i < len; i++)
		{
			mp[p[i]-'a']++;
			ms[s[i] - 'a']++;
		}

		if (mp == ms)
			res.push_back(0);

		for (int i = 0; i+len < slen; i++)
		{
			ms[s[i] - 'a']--;
			ms[s[i+len] - 'a']++;
			if (mp == ms)
				res.push_back(i+1);
		}

		return res;
	}
};

int main()
{
	string s = "cbaebabacd";
	string p = "abc";
	Solution newsolution;
	vector<int>result = newsolution.findAnagrams(s, p);

	cout<< "[" <<"" ;
	for (int i = 0; i < result.size()-1; i++)
	{
		cout << result[i] << ",";

	}
	cout << result[result.size() - 1] << "";
	cout << "]" << "";

	system("pause");
	return EXIT_SUCCESS;
}