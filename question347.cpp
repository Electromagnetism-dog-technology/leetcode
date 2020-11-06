#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//1、优先队列+make_pair
class Solution1 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>s;
		for (int i = 0; i < nums.size(); i++)
		{
			s[nums[i]]++;
		}

		//std::pair主要的作用是将两个数据组合成一个数据，两个数据可以是同一类型或者不同类型
		priority_queue<pair<int, int>>que;
		for (auto m : s)
		{
		//make_pair的用法
		//无需写出型别， 就可以生成一个pair对象
		//例：std::make_pair(42, '@');
		//而不必费力写成：std::pair<int, char>(42, '@')
			que.push(make_pair(m.second, m.first));//注意，比较的是m.second
		}

		vector<int>result;
		for (int j = 0; j<k;j++)
		{
			result.push_back(que.top().second);//返回que.second，也就是m.first
			que.pop();
		}

		return result;
	}
};

//2、小顶堆法（其实和上一种方法是同一种方法，只不过这个方法保证堆大小一直为k，加了greater比较pair的大小，且没用make_pair)
class Solution2 {
public:
	class greater
	{
	public:
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.second > rhs.second;
		}

	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>s;
		for (int i = 0; i < nums.size(); i++)
		{
			s[nums[i]]++;
		}

		
		priority_queue<pair<int, int>,vector<pair<int, int>>,greater>que;
		for (unordered_map<int, int>::iterator it = s.begin(); it != s.end(); it++) {
			que.push(*it);
			if (que.size() > k) 
			{ 
				// 如果堆的大小大于k，则队列弹出，保证堆的大小一直为k
				que.pop();
			}
		}


		vector<int> result(k);
		for (int i = k - 1; i >= 0; i--) {
			result[i] = que.top().first;
			que.pop();
		}
		return result;

	}
};

int main()
{
	vector<int>nums = { 1,1,1,2,2,3 };
	Solution1 newsolution;
	vector<int>result = newsolution.topKFrequent(nums,2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}