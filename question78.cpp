#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//
class Solution {
public:
	vector<vector<int>>result;
	vector<int>digits;
	void getCombinations(int number, vector<int>& nums)
	{
		if (number == nums.size())
		{
			result.push_back(digits);
			return;
		}

		//选择该元素
		digits.push_back(nums[number]);
		getCombinations(number + 1, nums);
		//撤销选择
		digits.pop_back();
		//不选择该元素
		getCombinations(number + 1, nums);

	}
	vector<vector<int>> subsets(vector<int>& nums) {

		getCombinations(0, nums);
		return result;
	}

};

int main()
{
	vector<int>nums = { 1, 2, 3 };
	Solution newsolution;
	vector<vector<int>>result=newsolution.subsets(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
			cout << result[i][j] << ",";
		cout << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}