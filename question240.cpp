#include<iostream>
#include<vector>
using namespace std;

//1、线性查找法
class Solution1 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int m = matrix.size(), n = matrix[0].size();
		int i = 0, j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] < target)
				i++;
			else if (matrix[i][j] > target)
				j--;
			else if (matrix[i][j] == target)
				return true;
		}

		return false;
	}
};

//2、二分法
class Solution2 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size(); ++i)
		{
			if (binarySearch(matrix, i, target))
				return true;
		}
		return false;
		
	}

	bool binarySearch(vector<vector<int>>& matrix, int i, int target)
	{
		int left = 0, right = matrix[0].size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (target > matrix[i][mid]) 
				left = mid + 1;
			else if (target < matrix[i][mid])   
				right = mid - 1;
			else    
				return true;

		}
		return false;
	}
};

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}