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

//1��������
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

//2���ݹ鷨
class Solution2 {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)return true;
		queue<TreeNode*>que;
		que.push(root->left);// ��������ͷ���������
		que.push(root->right);// ��������ͷ���������
		while (!que.empty())
		{
			TreeNode* LeftNode = que.front();
			que.pop();
			TreeNode* RightNode = que.front();
			que.pop();
			if (!LeftNode && !RightNode)// ��ڵ�Ϊ�ա��ҽڵ�Ϊ�գ���ʱ˵���ǶԳƵ�
			{
				continue;
			}

			// ����һ���ڵ㲻Ϊ�գ����߶���Ϊ�յ���ֵ����ͬ������false
			if ((!LeftNode || !RightNode || (LeftNode->val != RightNode->val))) {
				return false;
			}

			que.push(LeftNode->left);   // ������ڵ�����
			que.push(RightNode->right); // �����ҽڵ��Һ���
			que.push(LeftNode->right);  // ������ڵ��Һ���
			que.push(RightNode->left);  // �����ҽڵ�����

		}
		return true;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}