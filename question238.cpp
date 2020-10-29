#include<iostream>
#include<vector>
using namespace std;

//1、暴力法：超出时间限制
class Solution1 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int>result(len, 0);
		for (int j = 0; j < len; j++)
		{
			for (int i = 0; i < len; i++)
			{
				while (i != j)
				{
					result[j] += nums[i];
				}

			}
		}

		return result;
	}
};

//2、左右乘积列表法
class Solution2 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int>result(len, 0);
		vector<int>left(len, 0);
		vector<int>right(len, 0);
		
		// Left[i] 为索引 i 左侧所有元素的乘积
		// 对于索引为 '0' 的元素，因为左侧没有元素，所以 Left[0] = 1
		left[0] = 1;
		for (int i = 1; i < len; i++)
		{
			left[i] = left[i - 1] * nums[i - 1];
		}

		// right[i] 为索引 i 右侧所有元素的乘积
		// 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 right[length-1] = 1
		right[len-1] = 1;
		for (int j = len-2; j >=0; j--)
		{
			right[j] = right[j + 1] * nums[j + 1];
		}

		// 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
		for (int k = 0; k < len; k++)
		{
			result[k] = left[k] * right[k];
		}

		return result;
	}
};

//3、空间复杂度为 O(1)的方法
class Solution3 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int>result(len, 0);
		
		result[0] = 1;
		for (int i = 1; i < len; i++)
		{
			result[i] = result[i - 1] * nums[i - 1];
		}

		int right = 1;
		for (int j = len - 1; j >= 0; j--)
		{
			result[j] = result[j] * right;
			right *= nums[j];
		}
		return result;
	}
};

int main()
{
	vector<int>nums = {1,2,3,4};
	Solution3 newsolution;
	vector<int>result = newsolution.productExceptSelf(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << result[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}