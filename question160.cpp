#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//1��������
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

//2����������
//����A���ȣ�A = a + c,
//����B���ȣ�B = b + c��(c�����ཻ����Ĺ����ڵ�)
//�������������߹����ֺ�ͣ��NULL��
//��������������a + c + b + c = b + c + a + c�����ն�����c����
//ÿ���˶���һƬɭ�֣���ʧ������ʧ�ˣ������˻�����ꡣ
class Solution2 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;

		ListNode *l1 = headA;
		ListNode *l2 = headB;

		while (l1 != l2)//����������ͣ��NULL��ʱ�򣬾ͻ�����whileѭ��
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

