#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//1.哈希表法
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int>s;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			s[nums[i]]++;
		}

		for (int i = 0; i < len; i++)
		{
			if (s[nums[i]] >= len / 2 + 1)
				return nums[i];
		}

		return 0;
	}
};

//2.排序法
class Solution2 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

//3.分治法
//如果数 a 是数组 nums 的众数，如果我们将 nums 分成两部分，那么 a 必定是至少一部分的众数。
//
//我们可以使用反证法来证明这个结论。假设 a 既不是左半部分的众数，也不是右半部分的众数，那么 a 出现的次数少于 l / 2 + r / 2 次，其中 l 和 r 分别是左半部分和右半部分的长度。由于 l / 2 + r / 2 <= (l + r) / 2，说明 a 也不是数组 nums 的众数，因此出现了矛盾。所以这个结论是正确的。
//
//这样一来，我们就可以使用分治法解决这个问题：将数组分成左右两部分，分别求出左半部分的众数 a1 以及右半部分的众数 a2，随后在 a1 和 a2 中选出正确的众数。
class Solution3 {
public:
	int majorityElement_count(vector<int>& nums, int target, int left, int right)
	{
		int count = 0;
		for (int i = left; i <= right; ++i)
			if (nums[i] == target)
				++count;
		return count;
	}

	int majorityElement_find(vector<int>& nums, int left, int right)
	{
		if (left == right)
			return nums[right];
		int mid = (left + right) / 2;
		int left_majority= majorityElement_find(nums, left, mid);
		int right_majority = majorityElement_find(nums, mid+1, right);

		if (majorityElement_count(nums,left_majority, left, right) >= (right - left) / 2 + 1)
			return left_majority;
		if (majorityElement_count(nums,right_majority,left, right) >= (right - left) / 2 + 1)
			return right_majority;

		return 0;
	}

	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		return majorityElement_find(nums, 0, len-1);
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}
