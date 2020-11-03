#include<iostream>
#include<vector>
using namespace std;

//1、双指针法（一遍过哈哈哈）
class Solution1 {
public:
	void moveZeroes(vector<int>& nums) {
		//两个指针i和j
		int i = 0, j = 1;
		while (j < nums.size())
		{
			//如果i是0，j是非零数，则交换
			if (nums[i] == 0 && nums[j] != 0)
			{
				swap(nums[i], nums[j]);
			}
			//如果i和j都是0，那么j后移
			else if (nums[i] == 0 && nums[j] == 0)
			{
				j++;
			}
			//其他情况，i和j都后移
			else
			{
				i++;
				j++;
			}
		}
		
	}
};

//2、官方的双指针题解
class Solution2 {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; j < nums.size(); j++) {
			if (nums[j] != 0) swap(nums[i++], nums[j]);
		}

	}
};

int main()
{
	vector<int>nums = { 0,1,0,3,12 };
	Solution1 newsolution;
	newsolution.moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}