#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//单链表需要定义结构体
struct ListNode {
	int val;  //当前结点的值
	ListNode *next;  //指向下一个结点的指针
	ListNode(int x) : val(x), next(NULL) {}  //初始化当前结点值为x,指针为空
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1;
		ListNode *q = l2;
		int len1=1;//记录l1的长度
		int len2=1;//记录l2的长度

		//获取l1的长度
		while (p->next != NULL)
		{
			len1++;
			p = p->next;
		}

		//获取l2的长度
		while (q->next != NULL)
		{
			len2++;
			q = q->next;
		}

		//对l2补零
		if (len1 > len2)
		{
			for (int i = 1; i < len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}
			
		}

		//对l1补零
		else
		{
			for (int i = 1; i < len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;
			}

		}

		//从头节点开始
		p = l1;
		q = l2;
		//记录进位
		bool count = false;
		ListNode *l3 = new ListNode(-1);
		ListNode *w = l3;

		//记录相加结果
		int nums = 0;
		while (p != NULL && q != NULL)
		{
			nums = count + p->val + q->val;
			w->next = new ListNode(nums % 10);
			w = w->next;
			p = p->next;
			q = q->next;
		}

		//如果还有进位
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