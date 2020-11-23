#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//1、暴力法(超出时间限制）
class Solution1 {
public:
	int subarraySum(vector<int>& nums, int k) {
		int cnt = 0;
		
		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0;
			for (int j = i; i >= 0; j--)
			{

				sum += nums[j];
				if (sum == k)
				{
					cnt++;
				}
			}
		}

		return cnt;
			
	}
};

//2、哈希法
class Solution2 {
public:
	int subarraySum(vector<int>& nums, int k) {
		
		unordered_map<int, int>m;

		m[0] = 1;
		int cnt = 0;
		int sum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];

			if (m.find(sum - k) != m.end())
			{
				cnt += m[sum-k];
			}

			m[sum]++;
		}

		return cnt;

	}
};

int main()
{
	vector<int>nums = { 1,2,3,5,3 };
	Solution2 newsolution;
	int result = newsolution.subarraySum(nums,8);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}