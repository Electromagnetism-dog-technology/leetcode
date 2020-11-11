#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// 先排序:[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]

// 再一个一个插入:从A里挑身高最高的人x出来，插入到 B. 因为B中每个人的身高都比x要高，因此x插入的位置，就是看x前面应该有多少人就行了。
// [7,0]
// [7,0], [7,1]
// [7,0], [6,1], [7,1]
// [5,0], [7,0], [6,1], [7,1]
// [5,0], [7,0], [5,2], [6,1], [7,1]
// [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]


class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](const vector<int>&a, const vector<int>&b )
		{
			if (a[0] > b[0])
				return true;
			else if (a[0] == b[0] && a[1] < b[1])
				return true;
			else
				return false;
		}
	  );

		vector<vector<int>>result;

		for (auto t : people)
		{
			result.insert(result.begin() + t[1], t);
		}

		return result;
		
	}
};

int main()
{
	vector<vector<int>> people = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	Solution newsolution;
	vector<vector<int>>result = newsolution.reconstructQueue(people);
	for (int i = 0; i < people.size(); i++)
	{
		cout << "[" << people[i][0] << "," << people[i][1] << "]";
	}
	system("pause");
	return EXIT_SUCCESS;
}
