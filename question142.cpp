#include<iostream>
using namespace std;


//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//����ʱ��
//
//slow�߹���·�̣�x + y + n(y + z), n����slow����nȦ
//fast�߹���·�̣�x + y + m(y + z)��m����fast����mȦ
//m > n
//��Ϊfast�ٶ���slow������
//
//2(x + y + n(y + z)) = x + y + m(y + z)
//x + y = (m - 2n)(y + z)
//x = (m - 2n)(y + z) - y
//y + z����1Ȧ������ o = m - 2n��o��һ������������ô x = o(y + z) - y
//���o = 1����ô x = z���ʹ�����������һ��
//���o > 1����ô x = (o - 1)(y + z) + y + z - y, x = (o - 1)(y + z) + z����x�ĳ���Ϊo - 1Ȧ����z
//���ԣ��ӵ�һ�׶λ�õ������㣬�߹�x������ᵽ�ﻷ����㡣
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;//��ָ��
		ListNode *slow = head;//��ָ��

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