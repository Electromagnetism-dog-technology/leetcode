#include<iostream>
#include<vector>
using namespace std;

//方法一：暴力法
class Solution1 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>result;
		int len1 = nums.size();
		int i = 0;
		for (i = 0; i < len1; i++)
		{
			if (nums[i] == target)
			{

				result.push_back(i);
			}

		}

		int len2 = result.size();
		if (result.empty())
		{
			return { -1,-1 };
		}
		else
		{
			return {result[0],result[len2-1]};
		}
		

	}
};

//方法二：二分法
class Solution2 {
private:
	int findFirstPosition(vector<int>& nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (target == nums[mid])
			{
				left = mid;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		if (nums[left] != target)
		{
			return -1;
		}

		return left;
	}

	int findLastPosition(vector<int>& nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left < right)
		{
			int mid = left + (right - left+1) / 2;
			if (target == nums[mid])
			{
				 left= mid;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		if (nums[left] != target)
		{
			return -1;
		}

		return left;
	}

public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>result;
		int len = nums.size();
		if (len==0)
		{
			return { -1,-1 };
		}

		int firstposition = findFirstPosition(nums,target);

		if (firstposition == 0)
		{
			return { -1,-1 };
		}
		
		int lastposition = findLastPosition(nums, target);

		return { firstposition,lastposition };

	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}