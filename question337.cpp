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
 
//1���ݹ鷨
class Solution1 {
public:
	unordered_map<TreeNode*, int>vals;
	int rob(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == 0 && root->right == 0)
			return root->val;

		//�ظ������ֱ�ӷ���֮ǰ�����ֵ
		/*������Ǳ����ظ�����ڵ��ˣ�����˵���ǿ���͵root����������������������Ҫ���� root ���ĸ�����������
			����Ҳ����͵ root ��������������ô�ּ����� root �����������������߻�� root �����������ظ�����һ�顣���Ծͼ�¼һ��*/
		if (vals[root])
			return vals[root];

		//͵���ڵ�
		int val1 = root->val;
		if (root->left)
			val1 += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			val1 += rob(root->right->left) + rob(root->right->right);

		//��͵���ڵ�
		int val2 = rob(root->left) + rob(root->right);
		vals[root] = max(val1, val2);

		return max(val1, val2);
	}
};

//2����̬�滮
class Solution2 {
public:
	//�� f(o) ��ʾѡ�� o �ڵ������£�o �ڵ�������ϱ�ѡ��Ľڵ�����Ȩֵ�ͣ�
	//g(o) ��ʾ��ѡ�� o �ڵ������£�o �ڵ�������ϱ�ѡ��Ľڵ�����Ȩֵ��.

	unordered_map <TreeNode*, int> f, g;

	void dfs(TreeNode* o) {
		if (!o) {
			return;
		}
		dfs(o->left);
		dfs(o->right);
		//o �ڵ㱻ѡ�У���ô�����ӽڵ㲻�ܱ�ѡ�У����� f[o] = o->val + g[o->left] + g[o->right];
		f[o] = o->val + g[o->left] + g[o->right];
		//o �ڵ�û�б�ѡ�У���ô��Ҫ�������������ˣ���������Ҳ������ѡ�кͲ�ѡ�����������
		//���� g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
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