#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

//Ì°ÐÄ·¨
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int t = 0;
		int len = nums.size();
		for(int i = 0; i < len; i++)
		{
			if (i <= t)
			{
				t = max(i + nums[i], t);

				if (t >= len - 1)
				{
					return true;
				}
			}

			else
				return false;
		}
	}
};

//¼ò»¯°æ
class Solution2 {
public:
	bool canJump(vector<int>& nums) {
		int t = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (t < i)
				return false;
			t = max(i + nums[i], t);
		}
		return true;
	}
};

int main()
{
	vector<int>nums = { 2,0 };
	Solution newsolution;
	bool result = newsolution.canJump(nums);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}