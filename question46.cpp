#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

//1.回溯算法
class Solution {
public:
	vector<vector<int>>result;
	int index = 0;
	int start = 0;

	void getCombinations(vector<int> digits, vector<int>s,vector<bool>nums1)
	{
		if (s.size() == nums1.size()) {
			result.push_back(s);
			return;
		}

		else
		{
			for (int i = 0; i < digits.size(); i++)
			{
				if (nums1[i])
				{
					s.push_back(digits[i]);
					nums1[i] = false;
					getCombinations(digits, s,nums1);
					nums1[i] = true;
					s.pop_back();
				}
			}
		}
		

	}

	vector<vector<int>> permute(vector<int>& nums) {

		if (nums.size() == 0)
		{
			return result;
		}

		else if (nums.size() == 1)
		{
			return { {nums[0]} };
		}

		else
		{
			vector<bool> nums1(nums.size(), true);
			vector<int> s;
			getCombinations(nums, s,nums1);
			return result;
		}
		
	}



};

//2.交换法
class Solution2 {
public:
	vector<vector<int> > result;
	void func(vector<int> &nums, int start, int end)
	{
		if (start == end)
			result.push_back(nums);
		else
		{
			for (int i = start; i <= end; i++)
			{
				swap(nums[i], nums[start]);
				func(nums, start + 1, end);
				swap(nums[i], nums[start]);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
			return {};
		else if (nums.size() == 1)
			return { {nums[0]} };
		else
		{
			func(nums, 0, nums.size() - 1);
			return result;
		}
	}

};

int main()
{
	Solution newsolution;
	vector<int>nums = { 1,2,3 };
	vector<vector<int>>result;
	result=newsolution.permute(nums);
	for (int i = 0; i < result.size(); i++)
	{
		
			cout << result[i][0] <<result[i][1]<<result[i][2]<< endl;
		
	}
	
	system("pause");
	return EXIT_SUCCESS;
}