#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//��������Ҫ����ṹ��
struct ListNode {
	int val;  //��ǰ����ֵ
	ListNode *next;  //ָ����һ������ָ��
	ListNode(int x) : val(x), next(NULL) {}  //��ʼ����ǰ���ֵΪx,ָ��Ϊ��
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1;
		ListNode *q = l2;
		int len1=1;//��¼l1�ĳ���
		int len2=1;//��¼l2�ĳ���

		//��ȡl1�ĳ���
		while (p->next != NULL)
		{
			len1++;
			p = p->next;
		}

		//��ȡl2�ĳ���
		while (q->next != NULL)
		{
			len2++;
			q = q->next;
		}

		//��l2����
		if (len1 > len2)
		{
			for (int i = 1; i < len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}
			
		}

		//��l1����
		else
		{
			for (int i = 1; i < len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;
			}

		}

		//��ͷ�ڵ㿪ʼ
		p = l1;
		q = l2;
		//��¼��λ
		bool count = false;
		ListNode *l3 = new ListNode(-1);
		ListNode *w = l3;

		//��¼��ӽ��
		int nums = 0;
		while (p != NULL && q != NULL)
		{
			nums = count + p->val + q->val;
			w->next = new ListNode(nums % 10);
			w = w->next;
			p = p->next;
			q = q->next;
		}

		//������н�λ
		if (count)
		{
			w->next = new ListNode(1);
			w = w->next;
		}

		return l3->next;
	}
};

int main()
{
	Solution ss;
	ListNode l0(2), ll(7), l2(8), l3(5);
	ListNode *p0(&l0), *p1(&ll);
	ListNode *h0 = p0;
	ListNode *h1 = p1;
	p0->next = &l2;
	p1->next = &l3;
	ss.addTwoNumbers(h0, h1);

	system("pause");
	return EXIT_SUCCESS;
}