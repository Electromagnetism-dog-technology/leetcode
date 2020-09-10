#include<iostream>
#include<vector>
using namespace std;

//方法一：暴力法
class Solution1{
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int i = 0;
		for (i = 0; i < len; i++)
		{
			if (nums[i] == target)
			{
				
				return i;
			}

		}

		return -1;
		
	}
};

//方法二：二分法
class Solution2 {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (!len) return -1;
		if (len == 1) return nums[0] == target ? 0 : -1;
		int l = 0, r = len - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] == target) return mid;
			if (nums[l] <= nums[mid])
			{
				if (nums[l] <= target && target <= nums[mid])
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
			else
			{
				if (nums[len-1] >= target && target > nums[mid])
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return -1;

	}
};

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}