#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*>que;
		if (root != NULL)que.push(root);
		
		vector<vector<int>>result;
		while (!que.empty())
		{
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
			result.push_back(vec);
		}
		
		return result;
		
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}