#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		int i = 0, j = 0;
		for (i = len - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				break;
			}

		}
		if (i == 0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		for (j = len - 1; j > i; j--)
		{
			if (nums[j] > nums[i - 1])
			{
				break;
			}


		}

		std::swap(nums[j], nums[i - 1]);
		reverse(nums.begin() + i, nums.end());
	}
};



int main()
{
	vector<int> nums = {1,4,2,6,4};
	Solution newsolution;
	newsolution.nextPermutation(nums);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}