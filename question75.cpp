#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class myquickSort
{
public:
	void quickSort(int left, int right, vector<int>& arr)
	{
		if (left >= right)
			return;
		int i, j, base, temp;
		i = left, j = right;
		int low = left, high = right;

		int m = (low + high) / 2;
		if (arr[low] > arr[high]) swap(arr[low], arr[high]);
		if (arr[m] > arr[high]) swap(arr[m], arr[high]);
		if (arr[m] > arr[low]) swap(arr[m], arr[low]);

		base = arr[low];  //取最左边的数为基准数

		while (i < j)
		{
			while (arr[j] >= base && i < j)
				j--;
			while (arr[i] <= base && i < j)
				i++;
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		//基准数归位
		arr[left] = arr[i];
		arr[i] = base;
		quickSort(left, i - 1, arr);//递归左边
		quickSort(i + 1, right, arr);//递归右边

	}
};

//1、原始快速排序法
class Solution1 {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		myquickSort newquickSort;
		newquickSort.quickSort(0, len - 1, nums);
	}
};

//2、循环不变量法
class Solution {
public:
	void sortColors(vector<int> &nums) {
		int size = nums.size();
		if (size < 2) {
			return;
		}
		int zero = 0;
		int two = size;
		int i = 0;
		while (i < two) {
			if (nums[i] == 0)
			{
				swap(nums[zero], nums[i]);
				zero++;
				i++;
			}
			else if (nums[i] == 1)
			{
				i++;
			}
			else
			{
				two--;
				swap(nums[i], nums[two]);
			}
		}
	}
};


int main()
{
	vector<int>arr = { 0,2,1,2,0,2,0,1 };
	int len = arr.size();
	Solution1 newsolution;
	newsolution.sortColors(arr);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}