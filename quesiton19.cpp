#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//方法一：先遍历求出长度，再从前往后遍历找到并删除
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = head;
		int len = 1;//记录l1的长度


		//获取链表的长度
		while (p->next != NULL)
		{
			len++;
			p = p->next;
		}

		if (len <= 1)
		{
			head = NULL;
		}

		//删除第一个结点时
		else if (n == len)
		{
			return head->next;
		}
		else
		{
			int n1 = len - n - 1;
			ListNode *pre = head;
			//将指针移动到目标结点的前一个结点
				for (int i = 0; i < n1; i++)
				{
					pre = pre->next;
				}

				//删除结点
				pre->next = pre->next->next;
		}

		return head;
	}
};

//方法二：双指针法：当快的前进n时，慢的开始；当快的到结尾时，慢的正好到可以删除的那个节点前一个
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(NULL);
		dummy->next = head;  //添加头节点，便于操作
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