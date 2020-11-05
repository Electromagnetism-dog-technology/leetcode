#include<iostream>
#include<unordered_map>
#include<Windows.h>
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
	unordered_map<TreeNode*, int>vals;
	int rob(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == 0 && root->right == 0)
			return root->val;

		//重复计算的直接返回之前计算的值
		/*这个就是避免重复计算节点了，比如说我们可以偷root和他的孙子子树，我们需要计算 root 的四个孙子子树，
			我们也可以偷 root 的左右子树，那么又计算了 root 的左右子树，而后者会把 root 的孙子子树重复计算一遍。所以就记录一下*/
		if (vals[root])
			return vals[root];

		//偷父节点
		int val1 = root->val;
		if (root->left)
			val1 += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			val1 += rob(root->right->left) + rob(root->right->right);

		//不偷父节点
		int val2 = rob(root->left) + rob(root->right);
		vals[root] = max(val1, val2);

		return max(val1, val2);
	}
};

//2、动态规划
class Solution2 {
public:
	//用 f(o) 表示选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；
	//g(o) 表示不选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和.

	unordered_map <TreeNode*, int> f, g;

	void dfs(TreeNode* o) {
		if (!o) {
			return;
		}
		dfs(o->left);
		dfs(o->right);
		//o 节点被选中，那么左右子节点不能被选中，所以 f[o] = o->val + g[o->left] + g[o->right];
		f[o] = o->val + g[o->left] + g[o->right];
		//o 节点没有被选中，那么就要遍历左右子树了，左右子树也可以有选中和不选择两种情况，
		//所以 g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
		g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
	}

	int rob(TreeNode* o) {
		dfs(o);
		return max(f[o], g[o]);
	}
};


int main()
{
	system("pause");
	return EXIT_SUCCESS;
}