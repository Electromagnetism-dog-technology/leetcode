#include<iostream>
#include<vector>
using namespace std;

//�ݹ�
class Solution {
public:
	int numTrees(int n) {
		if (n < 2) return 1;
		vector<int> vec(n + 1);
		vec[0] = 1;
		vec[1] = 1;
		//i��ʾ�ܽ������j��ʾ�������Ľ����
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				vec[i] = vec[i] + vec[j] * vec[i - j - 1];
			}
		}
		return vec[n];
	}
};

int main()
{
	int n = 3;
	Solution newsolution;
	int result=newsolution.numTrees(n);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}