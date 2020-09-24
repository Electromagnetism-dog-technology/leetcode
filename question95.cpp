#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1、递归法
class Solution {
public:
	void inorder(TreeNode* root, vector<int>& vec)
	{
		if (root == NULL) return;
		inorder(root->left,vec);
		vec.push_back(root->val);
		inorder(root->right,vec);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inorder(root, result);
		return result;
	}
};

//2、迭代法:中序遍历
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*>S;
		while (root != NULL || !S.empty())
		{
			while (root)
			{
				S.push(root);
				root = root->left;
			}
			root = S.top();
			S.pop();

			result.push_back(root->val);

			root = root->right;

		}

		return result;
	}
};

//3、迭代法：前序遍历
class Solution3 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> S;
		vector<int> v;
		TreeNode* rt = root;
		while (rt || S.size()) {
			while (rt) {
				S.push(rt->right);
				v.push_back(rt->val);
				rt = rt->left;
			}
			rt = S.top(); S.pop();
		}
		return v;
	}
};

//4、迭代法：后序遍历
class Solution4 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> S;
		vector<int> v;
		TreeNode* rt = root;
		while (rt || S.size()) {
			while (rt) {
				S.push(rt->left);
				v.push_back(rt->val);
				rt = rt->right;
			}
			rt = S.top(); S.pop();
		}
		reverse(v.begin(), v.end());
		return v;
	}

};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}