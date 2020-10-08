#include<iostream>
using namespace std;


//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//相遇时：
//
//slow走过的路程：x + y + n(y + z), n代表slow绕了n圈
//fast走过的路程：x + y + m(y + z)，m代表fast饶了m圈
//m > n
//因为fast速度是slow两倍：
//
//2(x + y + n(y + z)) = x + y + m(y + z)
//x + y = (m - 2n)(y + z)
//x = (m - 2n)(y + z) - y
//y + z就是1圈，假设 o = m - 2n，o是一个正整数，那么 x = o(y + z) - y
//如果o = 1，那么 x = z，和答主假设的情况一样
//如果o > 1，那么 x = (o - 1)(y + z) + y + z - y, x = (o - 1)(y + z) + z，即x的长度为o - 1圈加上z
//所以，从第一阶段获得的相遇点，走过x距离机会到达环的起点。
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;//快指针
		ListNode *slow = head;//慢指针

		if (head == NULL)
		{
			return NULL;
		}
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				slow = head;
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}

				return fast;
				
			}
		}

		return NULL;
	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}