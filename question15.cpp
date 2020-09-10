#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//双指针法
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>>result;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				return result;
			}

			if (i > 0 && nums[i] == nums[i-1])
			{
				continue;
			}

			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left)
			{
				if (nums[i] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0)
				{
					left++;
				}
				else
				{
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left +1]) left++;
				

				right--;
				left++;
				}

			}

			
		}
		return result;
	}
};

int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	Solution newsolution;
	vector<vector<int>>result=newsolution.threeSum(nums);
	//vec.size()和 vec[0].size()来分别获取行数和列数。
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout << result[i][j] << endl;
		}
	}
	
	system("pause");
	return EXIT_SUCCESS;
}