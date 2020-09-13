#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int pos1 = 0; 
		int pos2 = matrix.size() - 1;
		int add, temp;
		while (pos1 < pos2)
		{
			add = 0;
			while (add < pos2 - pos1)
			{
				temp = matrix[pos2 - add][pos1];
				matrix[pos2 - add][pos1] = matrix[pos2][pos2 - add];
				matrix[pos2][pos2 - add] = matrix[pos1 + add][pos2];
				matrix[pos1 + add][pos2] = matrix[pos1][pos1 + add];
				matrix[pos1][pos1 + add] = temp;
				add++;

			}
			pos1++;
			pos2--;
		}
	}
};

int main()
{
	vector<vector<int>>matrix = { {1,2,3},{4,5,6},{7,8,9} };
	Solution newsoluiton;
	newsoluiton.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << matrix[i][0] << "" << matrix[i][1] << ""<<matrix[i][2] << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}