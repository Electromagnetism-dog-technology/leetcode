#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//�ݹ鷨
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int m = preorder.size();
		if (m == 0) return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		vector<int> preorder_left, inorder_left, preorder_right, inorder_right;

		int i;
		for (i = 0; i < m; i++)
		{
			if (inorder[i] == preorder[0]) break;
			inorder_left.push_back(inorder[i]);
			
		}

		for (i = i + 1; i < m; i++)
		{
			inorder_right.push_back(inorder[i]);
		}

		int n = inorder_left.size();
		for (int j = 1; j <= n; j++)
		{
			preorder_left.push_back(preorder[j]);
		}

		for (int j = n+1; j < m; j++)
		{
			preorder_right.push_back(preorder[j]);
		}

		root->left = buildTree(preorder_left, inorder_left);
		root->right = buildTree(preorder_right, inorder_right);

		return root;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}