#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1、排序法（后来才发现不能修改原数组）
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

//2、双指针法
class Solution2 {
public:
	int findDuplicate(vector<int>& nums) {
		
		/*假设有这样一个样例：[1, 2, 3, 4, 5, 6, 7, 8, 9, 5]。
		如果我们按照下面的循环下去就会得到这样一个路径: 1 2 3 4 5[6 7 8 9][6 7 8 9][6 7 8 9] . ..这样就有了一个环，也就是6 7 8 9。
		point 会一直在环中循环的前进。
		这时我们设置两个一快(fast)一慢(slow)两个指针，一个每次走两步，一个每次走一步，这样让他们一直走下去，直到他们在重复的序列中相遇，*/
		int fast = 0, slow = 0;
		while (true) {
			fast = nums[nums[fast]];
			slow = nums[slow];
			if (fast == slow)
				break;
		}

		
		// 设环长度为 b，链表头到环入口举例为 a，即 [1, 2, ... a, 1(环入口), 2, ... b, z1(出环了), z2, ...]；
		// 设快慢指针在环上第 x 步时相遇，则慢指针一共走了 a + x 步，快指针一共走了 2(a + x) 步；
		// 则在环上，快指针走了 a + 2x 步，并且快指针已经走完了一圈环又回到了 x 处，即 a + 2x - b = x、得 b - a = x；
		// 故快慢指针在环上某点相交、而不一定在环入口处相交，证毕。
		// 找到相交点后，慢指针从链表起点走 a 步可到达环入口；快指针从相交点走 a 步也会到达环入口，从而找到环入口（即重复元素）

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