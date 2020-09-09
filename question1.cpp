#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1.暴力法
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					/*vector<int> result;
					result.push_back(i);
					result.push_back(j);

					return result;*/

					return { i,j };
				}

			}
		}
		return {};

	}
};

//2.双指针法
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>tmp = nums;
		vector<int>ans;
		sort(tmp.begin(), tmp.end());
		int left = 0;
		int right = tmp.size() - 1;
		while (left < right)
		{
			if (tmp[left] + tmp[right] > target) {
				right--;
			}
			else if (tmp[left] + tmp[right] < target) {
				left++;
			}
			else
			{
				break;
			}
		}
		for (int k = 0; k < tmp.size(); k++) {
			if (nums[k] == tmp[left]) {
				ans.push_back(k);
			}
			else if (nums[k] == tmp[right]) {
				ans.push_back(k);
			}
			

		}
		return ans;

	}
};



int main()
{
	vector<int>nums = {3,2,4};//vector元素是用{ }表示的
	/*nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(19);*/

	Solution2 newsolution;
	vector<int>nums1=newsolution.twoSum(nums,6);
	cout << nums1[0]  <<","<<nums[1]<< endl;//下标是从0开始的
	system("pause");
	return EXIT_SUCCESS;
}