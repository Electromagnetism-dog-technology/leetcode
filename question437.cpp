#include<iostream>
#include<unordered_map>
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

//1��DFS
class Solution1 {
public:
	int clik = 0;
	int sum = 0;
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return clik;
		this->sum = sum;
		Calnum(root, 0, true);
		return clik;
	}

	//��һ��tart �������룬 ��֤start Ϊfalse�Ķ�·�����ߵ�Ҷ�ڵ�
	void Calnum(TreeNode* root, int num,bool start)
	{
		if (root == NULL)
			return;
		num += root->val;
		if (num == sum)
		{
			clik++;
		}
		
		Calnum(root->left, num, false);
		Calnum(root->right, num, false);

		if (start)
		{
			Calnum(root->left, 0, true);
			Calnum(root->right, 0, true);
		}
		
	}
};

//2��ǰ׺�ͣ����ݷ�˼�룩
class Solution2 {
public:
	int clik = 0;
	int sum = 0;
	unordered_map<int, int>m;
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		this->sum = sum;
		m[0] = 1;
		Calnum(root, root->val);
		return clik;
	}

	//��һ��tart �������룬 ��֤start Ϊfalse�Ķ�·�����ߵ�Ҷ�ڵ�
	void Calnum(TreeNode* root, int num)
	{
		if (root == NULL)
			return;
		
		if (m.count(num-sum))
		{
			clik++;
		}

		//����µ�num-sum�����ѻ��۵�num��Ҳ����·���͵��ڸ�����ֵ
		m[num]++;
		if (root->left)
			Calnum(root->left, num + root->left->val);
		if (root->right)
			Calnum(root->right, num + root->right->val);
		m[num]--;
		//������һ��󣬻��۵�num����1

	}
};

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}