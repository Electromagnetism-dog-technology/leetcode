#include<iostream>
using namespace std;


//Definition for singly - linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *fast = head;//��ָ��
		ListNode *slow = head;//��ָ��

		if (head = NULL)
		{
			return false;
		}
		while (fast != NULL&&fast->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}

		return false;
	}
};


int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}