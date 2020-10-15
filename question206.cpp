#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//1.�ݹ鷨
class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* result = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return result;
	}
};

//2.˫ָ�뷨
class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = NULL, *pre = head;
		while (pre != NULL)
		{
			ListNode* newhead = pre->next;
			pre->next = cur;
			cur = pre;
			pre = newhead;
		}
		return cur;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}