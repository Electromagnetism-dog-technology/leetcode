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

		//ѡ���Ԫ��
		digits.push_back(nums[number]);
		getCombinations(number + 1, nums);
		//����ѡ��
		digits.pop_back();
		//��ѡ���Ԫ��
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