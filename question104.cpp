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

//1、迭代法：层序遍历
class Solution1 {
public:
	int maxDepth(TreeNode* root) {
		queue<TreeNode*>que;
		if (root != NULL)que.push(root);
		int j = 0;

		while (!que.empty())
		{
			j++;
			int size = que.size();
			vector<int>vec;
			for (int i = 0; i < size; i++)
			{
				TreeNode* Node = que.front();
				que.pop();
				vec.push_back(Node->val);
				if (Node->left)que.push(Node->left);
				if (Node->right)que.push(Node->right);

			}
			
		}

		return j;
	}
};

//2、递归法
class Solution2 {
public:
	int getDepth(TreeNode* node) {
		if (node == NULL) return 0;
		int leftDepth = getDepth(node->left);      
		int rightDepth = getDepth(node->right);     
		int depth = 1 + max(leftDepth, rightDepth); 
		return depth;
	}
	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
};



int main()
{

	system("pause");
	return EXIT_SUCCESS;
}