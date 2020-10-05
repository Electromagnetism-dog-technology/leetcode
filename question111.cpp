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

//1、递归法:前序遍历
class Solution {
public:
	void inorder(TreeNode* root)
	{
		TreeNode* root1 = new TreeNode(0);
		if (root == NULL) return;
		inorder(root->left);
		root1->right=root;
		root1 = root1->right;
		inorder(root->right);
	}
	void flatten(TreeNode* root) {
		vector<int> result;
		inorder(root);
		
	}
};

//2、迭代法
class Solution2 {
public:
	void flatten(TreeNode* root) {
		auto v = vector<TreeNode*>();
		auto stk = stack<TreeNode*>();
		TreeNode *node = root;
		while (node != nullptr || !stk.empty()) {
			while (node != nullptr) {
				v.push_back(node);
				stk.push(node);
				node = node->left;
			}
			node = stk.top(); stk.pop();
			node = node->right;
		}
		int size = v.size();
		for (int i = 1; i < size; i++) {
			auto prev = v.at(i - 1), curr = v.at(i);
			prev->left = nullptr;
			prev->right = curr;
		}
	}

};

//3、前序遍历和展开同步
class Solution3 {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		auto stk = stack<TreeNode*>();
		stk.push(root);
		TreeNode *prev = nullptr;
		while (!stk.empty()) {
			TreeNode *curr = stk.top(); stk.pop();
			if (prev != nullptr) {
				prev->left = nullptr;
				prev->right = curr;
			}
			TreeNode *left = curr->left, *right = curr->right;
			if (right != nullptr) {
				stk.push(right);
			}
			if (left != nullptr) {
				stk.push(left);
			}
			prev = curr;
		}
	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}