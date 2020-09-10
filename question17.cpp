#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

//回溯算法
class Solution {
public:
	vector<string>result;
	void getCombinations(string digits, int index, string s)
	{
		map<int, string>reference;

		reference[0] = "";
		reference[1] = "";
		reference[2] = "abc";
		reference[3] = "def";
		reference[4] = "ghi";
		reference[5] = "jkl";
		reference[6] = "mno";
		reference[7] = "pqrs";
		reference[8] = "tuv";
		reference[9] = "wxyz";
		
		if (index == digits.size())
		{
			result.push_back(s);
			return;
		}

		int digit = digits[index]-'0';//将char转换为int
		string letter = reference[digit];
		for (int i = 0; i < letter.size(); i++)
		{
			getCombinations(digits, index + 1, s + letter[i]);
		}

	}

	vector<string> letterCombinations(string digits) {
		
		if (digits.size() == 0)
		{
			return result;
		}

		getCombinations(digits, 0, "");
		return result;
	}
};

int main()
{
	Solution newsolution;
	vector<string>result1=newsolution.letterCombinations("23");
	for (int i = 0; i < result1.size(); i++)
	{
		cout << result1[i] << endl;
	}
	
	
	system("pause");
	return EXIT_SUCCESS;
}