#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//1、暴力法
class Solution1 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* l1 = headA;

		while (l1)
		{
			ListNode* l2 = headB;
			while (l2)
			{
				if (l1 == l2)
				{
					return l1;
				}
				l2 = l2->next;
			}
			l1 = l1->next;
		}

		return nullptr;
	}


};

//2、交叉链表法
//链表A长度：A = a + c,
//链表B长度：B = b + c。(c代表相交后面的公共节点)
//若无相遇点则，走过两轮后都停在NULL。
//假如有相遇点则a + c + b + c = b + c + a + c，最终都会在c相遇
//每个人都是一片森林，迷失的人迷失了，相逢的人会再相逢。
class Solution2 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;

		ListNode *l1 = headA;
		ListNode *l2 = headB;

		while (l1 != l2)//当两个链表都停在NULL的时候，就会跳出while循环
		{
			if (l1 != NULL) 
				l1 = l1->next;
			else 
				l1 = headB;

			if (l2 != NULL)
				l2 = l2->next;
			else
				l2 = headA;
		}
		
		return l1;
	}
};

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}

