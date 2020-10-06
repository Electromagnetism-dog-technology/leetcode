#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//1����ϣ��
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int>s;
		int result = 0;

		for (int j = 0; j < nums.size(); j++)
		{
			s[nums[j]]++;
		}

		for (unordered_map<int, int>::iterator it = s.begin(); it != s.end(); it++)
		{
			if (it->second == 1)
				result = it->first;
		}
		return result;
	}
};

//2�����
//�κ����� 0 ��������㣬�����Ȼ��ԭ������
//�κ�������������������㣬����� 0
class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto e : nums) ret ^= e;
		return ret;
	}
};


int main()
{
	vector<int>nums = { 1,2,2 };
	Solution2 newsolution;
	int result = newsolution.singleNumber(nums);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}