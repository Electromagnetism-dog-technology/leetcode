#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//1.��ϣ��
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

//2.����
class Solution2 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

//3.���η�
//����� a ������ nums ��������������ǽ� nums �ֳ������֣���ô a �ض�������һ���ֵ�������
//
//���ǿ���ʹ�÷�֤����֤��������ۡ����� a �Ȳ�����벿�ֵ�������Ҳ�����Ұ벿�ֵ���������ô a ���ֵĴ������� l / 2 + r / 2 �Σ����� l �� r �ֱ�����벿�ֺ��Ұ벿�ֵĳ��ȡ����� l / 2 + r / 2 <= (l + r) / 2��˵�� a Ҳ�������� nums ����������˳�����ì�ܡ����������������ȷ�ġ�
//
//����һ�������ǾͿ���ʹ�÷��η����������⣺������ֳ����������֣��ֱ������벿�ֵ����� a1 �Լ��Ұ벿�ֵ����� a2������� a1 �� a2 ��ѡ����ȷ��������
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
