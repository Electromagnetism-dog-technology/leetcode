#include<iostream>
#include<vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//1���������鷨
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

//2������ָ��+��ת����
class Solution2 {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* q = head;//��ָ��
		ListNode* cur = head, *pre = NULL;//��ת����ģ��
		while (q&&q->next)
		{
			q = q->next->next;
			ListNode* temp = cur->next;//����temp�洢ԭ������cur����һ�����
			cur->next = pre;//��ת����
			pre = cur;//����ת������pre
			cur = temp;//cur������ԭ�����к���һλ
		}

		//����������
		if (q)
		{
			cur = cur->next;
		}

		//�жϻ�������
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