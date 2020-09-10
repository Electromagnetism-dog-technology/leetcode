#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//方法一：迭代
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		//创建空链表
		ListNode* prehead = new ListNode(-1);
		ListNode* prev = prehead;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				prev->next = l1;
				l1=l1->next;
			}
			else
			{
				prev->next = l2;
				l2 = l2->next;
			}
			prev = prev->next;
		}

		prev->next = l1 == NULL ? l2 : l1; //由于最后至少一个未加入新链表中
		return prehead->next;


	}
};

//方法二：递归
class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (l1 == NULL)
		{
			return l2;
		}

		else if (l2 == NULL)
		{
			return l1;
		}

		else if (l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};
int main()
{

	system("pause");
	return EXIT_SUCCESS;
}