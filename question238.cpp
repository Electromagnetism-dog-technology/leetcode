#include<iostream>
#include<vector>
using namespace std;

//1��������������ʱ������
class Solution1 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int>result(len, 0);
		for (int j = 0; j < len; j++)
		{
			for (int i = 0; i < len; i++)
			{
				while (i != j)
				{
					result[j] += nums[i];
				}

			}
		}

		return result;
	}
};

//2�����ҳ˻��б�
class Solution2 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int>result(len, 0);
		vector<int>left(len, 0);
		vector<int>right(len, 0);
		
		// Left[i] Ϊ���� i �������Ԫ�صĳ˻�
		// ��������Ϊ '0' ��Ԫ�أ���Ϊ���û��Ԫ�أ����� Left[0] = 1
		left[0] = 1;
		for (int i = 1; i < len; i++)
		{
			left[i] = left[i - 1] * nums[i - 1];
		}

		// right[i] Ϊ���� i �Ҳ�����Ԫ�صĳ˻�
		// ��������Ϊ 'length-1' ��Ԫ�أ���Ϊ�Ҳ�û��Ԫ�أ����� right[length-1] = 1
		right[len-1] = 1;
		for (int j = len-2; j >=0; j--)
		{
			right[j] = right[j + 1] * nums[j + 1];
		}

		// �������� i���� nums[i] ֮�������Ԫ�صĳ˻������������Ԫ�صĳ˻������Ҳ�����Ԫ�صĳ˻�
		for (int k = 0; k < len; k++)
		{
			result[k] = left[k] * right[k];
		}

		return result;
	}
};

//3���ռ临�Ӷ�Ϊ O(1)�ķ���
class Solution3 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int>result(len, 0);
		
		result[0] = 1;
		for (int i = 1; i < len; i++)
		{
			result[i] = result[i - 1] * nums[i - 1];
		}

		int right = 1;
		for (int j = len - 1; j >= 0; j--)
		{
			result[j] = result[j] * right;
			right *= nums[j];
		}
		return result;
	}
};

int main()
{
	vector<int>nums = {1,2,3,4};
	Solution3 newsolution;
	vector<int>result = newsolution.productExceptSelf(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << result[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}