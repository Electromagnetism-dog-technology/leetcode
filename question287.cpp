#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1�����򷨣������ŷ��ֲ����޸�ԭ���飩
class Solution1 {
public:
	int findDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i + 1] == nums[i])
				return nums[i];
		}

		return 0;
	}
};

//2��˫ָ�뷨
class Solution2 {
public:
	int findDuplicate(vector<int>& nums) {
		
		/*����������һ��������[1, 2, 3, 4, 5, 6, 7, 8, 9, 5]��
		������ǰ��������ѭ����ȥ�ͻ�õ�����һ��·��: 1 2 3 4 5[6 7 8 9][6 7 8 9][6 7 8 9] . ..����������һ������Ҳ����6 7 8 9��
		point ��һֱ�ڻ���ѭ����ǰ����
		��ʱ������������һ��(fast)һ��(slow)����ָ�룬һ��ÿ����������һ��ÿ����һ��������������һֱ����ȥ��ֱ���������ظ���������������*/
		int fast = 0, slow = 0;
		while (true) {
			fast = nums[nums[fast]];
			slow = nums[slow];
			if (fast == slow)
				break;
		}

		
		// �軷����Ϊ b������ͷ������ھ���Ϊ a���� [1, 2, ... a, 1(�����), 2, ... b, z1(������), z2, ...]��
		// �����ָ���ڻ��ϵ� x ��ʱ����������ָ��һ������ a + x ������ָ��һ������ 2(a + x) ����
		// ���ڻ��ϣ���ָ������ a + 2x �������ҿ�ָ���Ѿ�������һȦ���ֻص��� x ������ a + 2x - b = x���� b - a = x��
		// �ʿ���ָ���ڻ���ĳ���ཻ������һ���ڻ���ڴ��ཻ��֤�ϡ�
		// �ҵ��ཻ�����ָ������������ a ���ɵ��ﻷ��ڣ���ָ����ཻ���� a ��Ҳ�ᵽ�ﻷ��ڣ��Ӷ��ҵ�����ڣ����ظ�Ԫ�أ�

		slow = 0;
		while (true) {
			slow = nums[slow];
			fast = nums[fast];
			if (slow == fast)
				break;
		}
		return slow;
		
	}
};

int main()
{
	vector<int>nums = { 0,1,2,3,1 };
	Solution1 newsolution;
	int result=newsolution.findDuplicate(nums);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}