#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//1�����ȶ���+make_pair
class Solution1 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>s;
		for (int i = 0; i < nums.size(); i++)
		{
			s[nums[i]]++;
		}

		//std::pair��Ҫ�������ǽ�����������ϳ�һ�����ݣ��������ݿ�����ͬһ���ͻ��߲�ͬ����
		priority_queue<pair<int, int>>que;
		for (auto m : s)
		{
		//make_pair���÷�
		//����д���ͱ� �Ϳ�������һ��pair����
		//����std::make_pair(42, '@');
		//�����ط���д�ɣ�std::pair<int, char>(42, '@')
			que.push(make_pair(m.second, m.first));//ע�⣬�Ƚϵ���m.second
		}

		vector<int>result;
		for (int j = 0; j<k;j++)
		{
			result.push_back(que.top().second);//����que.second��Ҳ����m.first
			que.pop();
		}

		return result;
	}
};

//2��С���ѷ�����ʵ����һ�ַ�����ͬһ�ַ�����ֻ�������������֤�Ѵ�СһֱΪk������greater�Ƚ�pair�Ĵ�С����û��make_pair)
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
				// ����ѵĴ�С����k������е�������֤�ѵĴ�СһֱΪk
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