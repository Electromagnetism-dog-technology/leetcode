#include<iostream>
#include<bitset>
using namespace std;

//1��bitset<32>����32λ��λ����
class Solution1 {
public:
	int hammingDistance(int x, int y) {
		return bitset<32>(x ^ y).count();
	}
};

//2��Ԫ������
class Solution2 {
public:
	int hammingDistance(int x, int y) {
		int n = x ^ y;
		int result = 0;
		while (n > 0)
		{
			result += n & 1;//a&b��ʾ��a��b��λ����������
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