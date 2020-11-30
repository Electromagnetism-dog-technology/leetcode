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
 
//1、递归法
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

//2、迭代法
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
			// 此时两个节点一定不为空，val相加
			node1->val += node2->val;

			// 如果两棵树左节点都不为空，加入队列
			if (node1->left != NULL && node2->left != NULL) {
				que.push(node1->left);
				que.push(node2->left);
			}
			// 如果两棵树右节点都不为空，加入队列
			if (node1->right != NULL && node2->right != NULL) {
				que.push(node1->right);
				que.push(node2->right);
			}

			// 当t1的左节点 为空 t2左节点不为空，就赋值过去
			if (node1->left == NULL && node2->left != NULL) {
				node1->left = node2->left;
			}
			// 当t1的右节点 为空 t2右节点不为空，就赋值过去
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