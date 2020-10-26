#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1¡¢µÝ¹é·¨
class Solution1 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

//2¡¢µü´ú·¨
class Solution2 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		stack<TreeNode*>st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			swap(node->left, node->right);
			if (node->left)
				st.push(node->left);
			if (node->right)
				st.push(node->right);
		}

		return root;
	}
};

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}