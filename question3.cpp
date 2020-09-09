#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<unordered_map>//要包含此头文件
using namespace std;

int max(int t1,int t2)
{
	if (t1 > t2)
	{
		t2= t1;
	}

	return t2;
}

//解法一：滑动窗口法
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0, end = 0, length = 0, result = 0;
		int sSize = s.size();
		while (end < sSize)
		{
			char tmp = s[end];
			for (int i = start; i < end; i++)
			{
				if (s[i] == tmp)
				{
					start = i + 1;
					length = end - start;
					break;
				}

				
			}
			end++;
			length++;
			result = max(result, length);
		}
		return result;
		
	}
};

//解法二：hash法
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(128, -1);
		int res = 0, left = -1;
		for (int i = 0; i < s.size(); ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;

	}
};

int main()
{
	Solution2 solution2;
	int t=solution2.lengthOfLongestSubstring("adrwaefw");
	cout << t << endl;
	system("pause");
	return EXIT_SUCCESS;
}