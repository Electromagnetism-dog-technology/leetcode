#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		return(head == NULL) ? NULL : MergeSort(head);
	}

private:
	//利用快慢指针确认中点
	ListNode* FindMid(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* previous = NULL;

		while (fast != NULL&&fast->next!=NULL)
		{
			previous = slow;
			fast = fast->next->next;
			slow = slow->next;
		}

		previous->next = NULL;
		return slow;
	}

	//合并两个链表
	ListNode* MergeList(ListNode* L1, ListNode* L2)
	{
		if (L1 == NULL)
		{
			return L2;
		}

		if (L2 == NULL)
		{
			return L1;
		}

		if (L1->val < L2->val)
		{
			L1->next=MergeList(L1->next, L2);
			return L1;
		}
		else
		{
			L2->next = MergeList(L1, L2->next);
			return L2;
		}

	}

	//归并排序
	ListNode* MergeSort(ListNode* head)
	{
		if (head->next == NULL)return head;
		ListNode* mid = FindMid(head);
		ListNode* L1 = MergeSort(head);
		ListNode* L2 = MergeSort(mid);

		return MergeList(L1, L2);

	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}