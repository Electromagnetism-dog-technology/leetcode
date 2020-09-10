#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;

//»ØËÝ·¨
class Solution {
public:

    void getCombinations(vector<string>&res, string s,int n,int lc,int rc)
    {
		if (rc > lc || lc > n || rc > n) return;
		if (lc == rc && lc == n) {
			res.push_back(s);
			return;
		}

		getCombinations(res, s+'(', n, lc+1, rc);
		getCombinations(res, s + ')', n, lc, rc+1);

    }

	vector<string> generateParenthesis(int n) {
		vector<string>result;
			
		int lc=0,rc=0;
		getCombinations(result, "",n,lc,rc);
		return result;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}