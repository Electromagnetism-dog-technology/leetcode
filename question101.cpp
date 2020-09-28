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

//1、迭代法
class Solution1 {
public:
	bool BFS(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == NULL&&p2==NULL)
		{
			return true;
		}

		if (p1 == NULL || p2 == NULL)
		{
			return false;
		}
		
		if (p1->val != p2->val)
		{
			return false;
		}
		return BFS(p1->left,p2->right )&& BFS(p1->right, p2->left);
		
	}

	bool isSymmetric(TreeNode* root) {
		
		return BFS(root, root);
	}
};

//2、递归法
class Solution2 {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)return true;
		queue<TreeNode*>que;
		que.push(root->left);// 将左子树头结点加入队列
		que.push(root->right);// 将右子树头结点加入队列
		while (!que.empty())
		{
			TreeNode* LeftNode = que.front();
			que.pop();
			TreeNode* RightNode = que.front();
			que.pop();
			if (!LeftNode && !RightNode)// 左节点为空、右节点为空，此时说明是对称的
			{
				continue;
			}

			// 左右一个节点不为空，或者都不为空但数值不相同，返回false
			if ((!LeftNode || !RightNode || (LeftNode->val != RightNode->val))) {
				return false;
			}

			que.push(LeftNode->left);   // 加入左节点左孩子
			que.push(RightNode->right); // 加入右节点右孩子
			que.push(LeftNode->right);  // 加入左节点右孩子
			que.push(RightNode->left);  // 加入右节点左孩子

		}
		return true;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}