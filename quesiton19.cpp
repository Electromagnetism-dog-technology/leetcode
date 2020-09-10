#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//����һ���ȱ���������ȣ��ٴ�ǰ��������ҵ���ɾ��
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = head;
		int len = 1;//��¼l1�ĳ���


		//��ȡ����ĳ���
		while (p->next != NULL)
		{
			len++;
			p = p->next;
		}

		if (len <= 1)
		{
			head = NULL;
		}

		//ɾ����һ�����ʱ
		else if (n == len)
		{
			return head->next;
		}
		else
		{
			int n1 = len - n - 1;
			ListNode *pre = head;
			//��ָ���ƶ���Ŀ�����ǰһ�����
				for (int i = 0; i < n1; i++)
				{
					pre = pre->next;
				}

				//ɾ�����
				pre->next = pre->next->next;
		}

		return head;
	}
};

//��������˫ָ�뷨�������ǰ��nʱ�����Ŀ�ʼ������ĵ���βʱ���������õ�����ɾ�����Ǹ��ڵ�ǰһ��
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(NULL);
		dummy->next = head;  //���ͷ�ڵ㣬���ڲ���
		ListNode* slow = dummy, *fast = dummy;
		int distance = 0;
		while (fast->next) {
			if (distance < n) {
				fast = fast->next;
				distance++;
			}
			else {
				fast = fast->next;
				slow = slow->next;
			}
		}
		slow->next = slow->next->next;
		return dummy->next;

	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}