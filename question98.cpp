#include<iostream>
#include<vector>
#include<stack>
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
	bool DFS(TreeNode* root, long long max, long long min) {
		if (root == NULL)
			return true;

		if (min >= root->val || max <= root->val)
			return false;
		return DFS(root->left, root->val, min) && DFS(root->right, max, root->val);


	}

	bool isValidBST(TreeNode* root) {

		return DFS(root, LONG_MAX, LONG_MIN);

	}
};

//2、中序遍历法
class Solution2 {
public:
	bool isValidBST(TreeNode* root) {

		stack<TreeNode*>S;
		long long inorder = (long long)INT_MIN - 1;
		while (root != NULL || !S.empty())
		{
			while (root)
			{
				S.push(root);
				root = root->left;
			}
			root = S.top();
			S.pop();
			if (root->val <= inorder) {
				return false;
			}
			inorder = root->val;
			root = root->right;

		}
		return true;

	}
};
int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}