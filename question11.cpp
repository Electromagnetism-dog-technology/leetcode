#include<iostream>
#include<vector>
#include <Windows.h>//��ͷ�ļ�<windows.h>�ж�����min,max�ĺ�
using namespace std;


//1.������ ����ʱ������
class Solution1 {
public:
	int maxArea(vector<int>& height) {
		int maxheight = 0;
		int sum = 0;
		int maxsum = 0;
		for (int i = 0; i < height.size(); i++)
		{
			for (int j = i + 1; j < height.size(); j++)
			{
				maxheight = min(height[i], height[j]);
				sum = maxheight * (j - i);
				if (sum > maxsum)
				{
					maxsum = sum;
				}

			}
		}
		return maxsum;
	}
};

//2.˫ָ�뷨
class Solution2 {
public:
	int maxArea(vector<int>& height) {
		int sum = 0;
		int maxsum = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j)
		{
			sum = min(height[j],height[i])*(j - i);
			maxsum = max(maxsum, sum);
			if (height[i] < height[j])
			{
				i++;
			}
			else
				j--;

		}
		return maxsum;
	}
};

int main()
{
	vector<int>height = { 1,8,6,2,5,4,8,3,7 };
	Solution1 solution1;
	Solution2 solution2;
	int result1=solution1.maxArea(height);
	int result2 = solution2.maxArea(height);
	cout << result1 << endl;
	cout << result2 << endl;
	system("pause");
	return EXIT_SUCCESS;
}