#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

//1����ϣ����������ϣ��ʹ���˶���ռ䣩
class Solution1 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		unordered_map<int, int>s;
		vector<int>result;
		for (int i = 0; i < nums.size(); i++)
		{
			s[nums[i]]++;
		}

		for (int i = 1; i <= nums.size(); i++)
		{
			if (s[i] == 0)
			{
				result.push_back(i);
			}
		}

		return result;


	}
};

//2��ԭ�ع�ϣ��
//������Ԫ�ض�ӦΪ������λ�ü�n
//������n������飬������Ԫ��ֵС�ڵ���n����˵�������±�ֵ�����ڣ�����ʧ������
class Solution2 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int>result;
		int index = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			//��Ϊnums[index]����n��,������Ҫ����nums.size()
			index = (nums[i] - 1) % nums.size();
			nums[index] += nums.size();
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= nums.size())
			{
				result.push_back(i+1);
			}
		}

		return result;


	}
};

int main()
{
	vector<int>nums = { 4,3,2,7,8,2,3,1 };
	Solution1 newsolution;
	vector<int>result = newsolution.findDisappearedNumbers(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}