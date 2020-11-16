#include<iostream>
#include<bitset>
using namespace std;

//1、bitset<32>定义32位的位运算
class Solution1 {
public:
	int hammingDistance(int x, int y) {
		return bitset<32>(x ^ y).count();
	}
};

//2、元素左移
class Solution2 {
public:
	int hammingDistance(int x, int y) {
		int n = x ^ y;
		int result = 0;
		while (n > 0)
		{
			result += n & 1;//a&b表示啊a和b按位进行与运算
			n >>= 1;
		}

		return result;

	}
};

int main()
{
	Solution1 newsolution;
	int result = newsolution.hammingDistance(1, 4);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}