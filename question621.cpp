#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1.记录最大任务数量N，看一下任务数量并列最多的任务有多少个，即最后一个桶子的任务数X，计算NUM1 = （N - 1）*（n + 1） + x
//2.NUM2 = tasks.size()
//输出其中较大值即可
//因为存在空闲时间时肯定是NUM1大，不存在空闲时间时肯定是NUM2 >= NUM1

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int len = tasks.size();
		vector<int>nums(26);
		for (int i = 0; i < len; i++)
		{
			nums[tasks[i] - 'A']++;
		}

		sort(nums.rbegin(), nums.rend());
		
		int cnt = 0;
		for (int j = 0; j < 26; j++)
		{
			if (nums[j] == nums[0])
				cnt++;
		}

		int result = (n + 1)*(nums[0]-1) + cnt;

		return max(len,result);
	}
};


int main()
{
	vector<char> tasks = { 'A','A','A','B','B','B' };
	Solution newsolution;
	int res=newsolution.leastInterval(tasks, 2);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}