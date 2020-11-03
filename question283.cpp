#include<iostream>
#include<vector>
using namespace std;

//1��˫ָ�뷨��һ�����������
class Solution1 {
public:
	void moveZeroes(vector<int>& nums) {
		//����ָ��i��j
		int i = 0, j = 1;
		while (j < nums.size())
		{
			//���i��0��j�Ƿ��������򽻻�
			if (nums[i] == 0 && nums[j] != 0)
			{
				swap(nums[i], nums[j]);
			}
			//���i��j����0����ôj����
			else if (nums[i] == 0 && nums[j] == 0)
			{
				j++;
			}
			//���������i��j������
			else
			{
				i++;
				j++;
			}
		}
		
	}
};

//2���ٷ���˫ָ�����
class Solution2 {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; j < nums.size(); j++) {
			if (nums[j] != 0) swap(nums[i++], nums[j]);
		}

	}
};

int main()
{
	vector<int>nums = { 0,1,0,3,12 };
	Solution1 newsolution;
	newsolution.moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}