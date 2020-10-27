#include<iostream>
#include<vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//1、复制数组法
class Solution1 {
public:
	bool isPalindrome(ListNode* head) {
		vector<int>vec;
		while (head != NULL)
		{
			vec.push_back(head->val);
			head = head->next;
			
		}

		int len = vec.size();

		for (int i = 0, j = len - 1; i < j; i++, j--)
		{
			if (vec[i] != vec[j])
				return false;
		}

		return true;
	}
};

//2、快慢指针+反转链表
class Solution2 {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* q = head;//快指针
		ListNode* cur = head, *pre = NULL;//反转链表模板
		while (q&&q->next)
		{
			q = q->next->next;
			ListNode* temp = cur->next;//利用temp存储原链表中cur的下一个结点
			cur->next = pre;//反转链表
			pre = cur;//将反转链表赋予pre
			cur = temp;//cur继续在原链表中后移一位
		}

		//奇数链表处理
		if (q)
		{
			cur = cur->next;
		}

		//判断回文链表
		while (pre)
		{
			if (pre->val != cur->val)
			{
				return false;
			}

			pre = pre->next;
			cur = cur->next;
		}

		return true;
	}
};

int main()
{
	ListNode* pNode = new ListNode(1);
	pNode->next = NULL;
	ListNode* pHead = pNode;

	ListNode* pTemp1 = new ListNode(2);
	pNode->next = pTemp1;
	pNode = pTemp1;

	ListNode* pTemp2 = new ListNode(2);
	pNode->next = pTemp2;
	pNode = pTemp2;

	ListNode* pTemp3 = new ListNode(1);
	pNode->next = pTemp3;
	pNode = pTemp3;

	Solution2 newsolution;
	bool result=newsolution.isPalindrome(pHead);

	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}