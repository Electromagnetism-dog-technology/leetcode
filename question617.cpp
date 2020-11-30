#include<iostream>
#include<queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//1���ݹ鷨
class Solution1 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL)
			return t2;
		if (t2 == NULL)
			return t1;

		t1->val = t1->val+ t2->val;

		t1->left=mergeTrees(t1->left, t2->left);
		t1->right=mergeTrees(t1->right, t2->right);

		return t1;
	}
};

//2��������
class Solution2 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) return t2;
		if (t2 == NULL) return t1;
		queue<TreeNode*> que;
		que.push(t1);
		que.push(t2);
		while (!que.empty()) {
			TreeNode* node1 = que.front(); que.pop();
			TreeNode* node2 = que.front(); que.pop();
			// ��ʱ�����ڵ�һ����Ϊ�գ�val���
			node1->val += node2->val;

			// �����������ڵ㶼��Ϊ�գ��������
			if (node1->left != NULL && node2->left != NULL) {
				que.push(node1->left);
				que.push(node2->left);
			}
			// ����������ҽڵ㶼��Ϊ�գ��������
			if (node1->right != NULL && node2->right != NULL) {
				que.push(node1->right);
				que.push(node2->right);
			}

			// ��t1����ڵ� Ϊ�� t2��ڵ㲻Ϊ�գ��͸�ֵ��ȥ
			if (node1->left == NULL && node2->left != NULL) {
				node1->left = node2->left;
			}
			// ��t1���ҽڵ� Ϊ�� t2�ҽڵ㲻Ϊ�գ��͸�ֵ��ȥ
			if (node1->right == NULL && node2->right != NULL) {
				node1->right = node2->right;
			}
		}
		return t1;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}