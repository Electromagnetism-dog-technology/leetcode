#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<stack>

using namespace std;

//1°¢≈≈–Ú∑®
class Solution1 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> snums = nums;
		sort(snums.begin(),snums.end());
		int start = snums.size(), end = 0;
		for (int i = 0; i < snums.size(); i++) {
			if (snums[i] != nums[i]) {
				start = min(start, i);
				end = max(end, i);
			}
		}
		return (end - start >= 0 ? end - start + 1 : 0);

	}
};

//2°¢ π”√’ª
class Solution2 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		stack<int>st1;
		int start = nums.size()-1, end = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			while (!st1.empty() && nums[st1.top()] > nums[i]) {
				start = min(start, st1.top());
				st1.pop();
			}
			st1.push(i);
		}

		stack<int>st2;
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!st2.empty() && nums[st2.top()] < nums[i]) {
				end = max(end, st2.top());
				st2.pop();
			}
			st2.push(i);
		}
		
};

int main()
{
	vector<int>nums = { 2, 6, 4, 8, 10, 9, 15 };
	Solution1 newsolution;
	int result = newsolution.findUnsortedSubarray(nums);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}