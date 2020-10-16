#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//������Ȿ��Ҫ�жϵ��ǣ�������Ȩͼ���Ƿ���ڻ���
//��ˣ����������������ж����޻���

//����ʹ��һ�����������й��������������ʼʱ���������Ϊ 00 �Ľڵ㶼����������У����Ǿ��ǿ�����Ϊ����������ǰ��Ľڵ㣬��������֮������˳�����޹ؽ�Ҫ�ġ�
//�ڹ������������ÿһ���У�����ȡ�����׵Ľڵ� uu��
//���ǽ� uu ������У�
//�����Ƴ� uu �����г��ߣ�Ҳ���ǽ� uu ���������ڽڵ����ȼ��� 11�����ĳ�����ڽڵ� vv ����ȱ�Ϊ 00����ô���Ǿͽ� vv ��������С�
//�ڹ�����������Ĺ��̽�����������а������� nn ���ڵ㣬��ô���Ǿ��ҵ���һ���������򣬷���˵��ͼ�д��ڻ���Ҳ�Ͳ��������������ˡ�


class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> v;
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> graph(numCourses, v);//�����ٽӱ���vector�����ٽӵ㣬������ʣ�

		for (int i = 0; i < prerequisites.size(); i++)
		{
			indegree[prerequisites[i][0]]++;// ��εĳ�ʼ���ֵ
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//����ǳ���
		}
		//�����Ϊ0�Ķ������
		queue<int> myqueue;
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree[i] == 0)// �������Ϊ0�Ŀ�����
				myqueue.push(i);
		}
		int cnt = 0;
		while (!myqueue.empty())
		{
			int temp = myqueue.front();// ��ǰѡ�ĿΣ�����
			myqueue.pop();
			cnt++;                    // ѡ����+1,��ȡ���ſζ�Ӧ�ĺ�����
			//���£�
			for (int i = 0; i < graph[temp].size(); i++)
			{
				indegree[graph[temp][i]]--;// �������ĺ����ε����-1
				if (indegree[graph[temp][i]] == 0)//������������ֻ�ж��ڽӵ㡣
					myqueue.push(graph[temp][i]);// �����˼�Ϊ0������
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