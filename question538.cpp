#include<iostream>
#include<stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1、反中序遍历法（递归）
class Solution1 {
public:
	int sum = 0;

	TreeNode* convertBST(TreeNode* root) {
		if (root != nullptr) {
			convertBST(root->right);
			sum += root->val;
			root->val = sum;
			convertBST(root->left);
		}
		return root;
	}

};

//2、反中序遍历法（迭代）
class Solution2 {
public:
	int sum = 0;

	TreeNode* convertBST(TreeNode* root) {
		if (root != nullptr) {
			stack<TreeNode*> st;
			TreeNode* cur = root;
			while (cur != NULL || !st.empty()) {
				if (cur != NULL) {
					st.push(cur);
					cur = cur->right;   // 右
				}
				else {
					cur = st.top();     // 中
					st.pop();
					cur->val += sum;
					sum = cur->val;
					cur = cur->left;    // 左
				}
			}

		}
		return root;
	}

};
int main()
{

	system("pause");
	return EXIT_SUCCESS;
}