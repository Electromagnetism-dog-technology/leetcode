#include<iostream>
#include<vector>
#include <Windows.h>//在头文件<windows.h>中定义了min,max的宏
using namespace std;


//1.暴力法 超出时间限制
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

//2.双指针法
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