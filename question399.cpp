#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//floyd解法
class Solution {
public:
	vector<vector<double>>g;
	unordered_map<string, int>h;
	int n = 0;
	void floyd() {
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					// 只有当g[i][k], g[k][j]能走的时候才进行更新 g[i][j]
					if (g[i][k] >= 0 && g[k][j] >= 0) g[i][j] = g[i][k] * g[k][j];
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		for (int i = 0; i < equations.size(); i++)
		{
			if (!h.count(equations[i][0]))
				h[equations[i][0]] = n++;
			if (!h.count(equations[i][1]))
				h[equations[i][1]] = n++;
		}

		g = vector<vector<double>>(n, vector<double>(n, -1));

		for (int i = 0; i < n; i++)
		{
			g[i][i] = 1;
		}

		for (int i = 0; i < equations.size(); i++)
		{
			g[h[equations[i][0]]][h[equations[i][1]]] = values[i];
			g[h[equations[i][1]]][h[equations[i][0]]] = 1 / values[i];
		}

		vector<double>result;

		floyd();

		for (auto q : queries)
		{
			string a = q[0], b = q[1];
			if (!h.count(a) || !h.count(b) || g[h[a]][h[b]] == -1)
				result.push_back(-1.0);
			else
				result.push_back(g[h[a]][h[b]]);
		}

		return result;
	}
};

int main()
{
	vector<vector<string>>equations = { {"a", "b"}, {"b", "c"} };
	vector<double>values = { 2.0, 3.0 };
	vector<vector<string>>queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };

	Solution newsolution;
	vector<double>result = newsolution.calcEquation(equations, values, queries);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	system("pause");
	return EXIT_SUCCESS;
}