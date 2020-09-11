#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

//回溯算法
class Solution {
public:
	vector<vector<int>>result;
	vector<int>s;
	int start = 0;

	void getCombinations(vector<int> digits, int target, int start, int sum)
	{
		if (sum > target) {
			return;
		}
		if (sum == target) {
			result.push_back(s);
			return;
		}

		for (int i = start; i < digits.size(); i++)
		{
			sum += digits[i];
			s.push_back(digits[i]);
			getCombinations(digits, target,i, sum);
			sum -= digits[i];
			s.pop_back();
		}

	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		if (candidates.size() == 0)
		{
			return result;
		}

		getCombinations(candidates, target, 0, 0);
		return result;
	}

	//if (sum > target) {
	//	return;
	//}
	//if (sum == target) {
	//	result.push_back(path);
	//	return;
	//}

	//// 这里i 依然从 startIndex开始，因为求的是组合，如果求的是排列，那么i每次都从0开始
	//for (int i = startIndex; i < candidates.size(); i++) {
	//	sum += candidates[i];
	//	path.push_back(candidates[i]);
	//	backtracking(candidates, target, sum, i); // 关键点在这里，不用i+1了，表示可以重复读取当前的数
	//	sum -= candidates[i];
	//	path.pop_back();

	//}

	
};

int main()
{
	Solution newsolution;
	vector<string>result1 = newsolution.letterCombinations("23");
	for (int i = 0; i < result1.size(); i++)
	{
		cout << result1[i] << endl;
	}


	system("pause");
	return EXIT_SUCCESS;
}