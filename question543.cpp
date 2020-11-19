#include<iostream>
#include<stack>
#include<Windows.h>
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
	int res;

	int SearchTree(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int L = SearchTree(root->left);
		int R = SearchTree(root->right);

		res = max(res, L + R + 1);//记录最长路径

		return max(L , R) + 1;// 每个子树的深度
	}

    int diameterOfBinaryTree(TreeNode* root) {
		res = 1;
		SearchTree(root);
		return res-1;
	}
};



int main()
{

	system("pause");
	return EXIT_SUCCESS;
}