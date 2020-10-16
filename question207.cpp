#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//而这道题本质要判断的是：有向无权图中是否存在环。
//因此，可以用拓扑排序判断有无环。

//我们使用一个队列来进行广度优先搜索。初始时，所有入度为 00 的节点都被放入队列中，它们就是可以作为拓扑排序最前面的节点，并且它们之间的相对顺序是无关紧要的。
//在广度优先搜索的每一步中，我们取出队首的节点 uu：
//我们将 uu 放入答案中；
//我们移除 uu 的所有出边，也就是将 uu 的所有相邻节点的入度减少 11。如果某个相邻节点 vv 的入度变为 00，那么我们就将 vv 放入队列中。
//在广度优先搜索的过程结束后。如果答案中包含了这 nn 个节点，那么我们就找到了一种拓扑排序，否则说明图中存在环，也就不存在拓扑排序了。


class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> v;
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> graph(numCourses, v);//构建临接表（用vector储存临接点，方便访问）

		for (int i = 0; i < prerequisites.size(); i++)
		{
			indegree[prerequisites[i][0]]++;// 求课的初始入度值
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//存的是出边
		}
		//将入度为0的顶点入队
		queue<int> myqueue;
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree[i] == 0)// 所有入度为0的课入列
				myqueue.push(i);
		}
		int cnt = 0;
		while (!myqueue.empty())
		{
			int temp = myqueue.front();// 当前选的课，出列
			myqueue.pop();
			cnt++;                    // 选课数+1,获取这门课对应的后续课
			//更新：
			for (int i = 0; i < graph[temp].size(); i++)
			{
				indegree[graph[temp][i]]--;// 依赖它的后续课的入度-1
				if (indegree[graph[temp][i]] == 0)//放在这里做！只判断邻接点。
					myqueue.push(graph[temp][i]);// 如果因此减为0，入列
			}
		}
		return cnt == numCourses;

	}
};



int main()
{

	system("pause");
	return EXIT_SUCCESS;
}