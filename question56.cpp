#include<iostream>
#include<Windows.h>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>>result;
		sort(intervals.begin(), intervals.end());
		int len = intervals.size();
		int i = 0;
		while (i < len)
		{
			int k = intervals[i][1];
			int j = i + 1;
			while (j < len&&intervals[j][0] <= k)
			{
				k = max(k, intervals[j][1]);
				j++;
			}
			result.push_back({ intervals[i][0],k });
			i = j;
		}

		return result;
	}
};

int main()
{
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	Solution newsolution;
	vector<vector<int>>result=newsolution.merge(intervals);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
			cout << result[i][j] << ",";
		cout << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}