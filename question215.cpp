#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1��������
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int result = 0;
		result = nums[len - k];
		return result;
	}
};

//2��������
class Solution2 {
public:
	void HeapAdjust(vector<int>& a, int i, int heapSize) {
		int l = i * 2 + 1, r = i * 2 + 2, largest = i;
		if (l < heapSize && a[l] > a[largest]) {
			largest = l;
		}
		if (r < heapSize && a[r] > a[largest]) {
			largest = r;
		}
		if (largest != i) {
			swap(a[i], a[largest]);
			HeapAdjust(a, largest, heapSize);
		}
	}

	//��nums�е�Ԫ�ع�����һ���󶥶�
	void buildMaxHeap(vector<int>& a, int heapSize) {
		for (int i = heapSize / 2; i >= 0; --i) {
			HeapAdjust(a, i, heapSize);
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		int heapSize = nums.size();
		buildMaxHeap(nums, heapSize);
		for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
			swap(nums[0], nums[i]);//���Ѷ���¼�͵�ǰδ�����������е����һ�����н���
			--heapSize;
			HeapAdjust(nums, 0, heapSize);//���µ���Ϊ�󶥶�
		}
		return nums[0];
	}
};


int main()
{
	vector<int>nums = { 3, 2, 1, 5, 6, 4 };
	Solution newsolution;
	int res = newsolution.findKthLargest(nums, 2);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}