#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//方法1：排序法
class Solution1 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>result;
		unordered_map<string, vector<string>>m;
		string s;
		for (auto s : strs)
		{
			string t = s;
			sort(t.begin(),t.end());
			m[t].push_back(s) ;
		}

		vector<string> vs;
		for (auto vs : m)
		{
			result.push_back(vs.second);
		}

		return result;

	}
};

//方法2:质数法
//对26个字母分别赋予对应的质数值，因为不同的质数和必定为不同的数字结果，所以可以用来作为map的key值
class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map <double, vector<string> > m;
		string s;
		double a[26] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };
		for (auto s : strs)
		{
			double t = 1;
			for (char c : s)
				t *= a[c - 'a'];

			m[t].push_back(s);          
		}

		vector<string> vs;
		for (auto& vs : m)                
			result.push_back(vs.second);
		return result;
	}
};


int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}