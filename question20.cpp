#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

//1��������
class Solution {
public:
	bool isValid(string s) {
		map<char, int>reference;

		reference['{'] = 0;
		reference['['] = 1;
		reference['('] = 2;
		reference[')'] = 3;
		reference[']'] = 4;
		reference['}'] = 5;

		bool result = true;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (reference[s[i]] != 5 - reference[s[len - i-1]])
			{
				result= false;
				break;
			}
		}

		return result;
	}
};

//2������ջ
class Solution2 {
public:
	bool isValid(string s) {
		//��ϣ��洢
		unordered_map<char, int> m{ {'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6} };

		//�趨ջ
		stack<char> st;


		bool result = true;
		int len = s.length();
		//for (int i = 0; i < len; i++)
		//{
		//	//���Ϊ�����ţ�������ջ
		//	if (0 <= reference[s[i]] && reference[s[i]] <= 2)
		//	{
		//		st.push(s[i]);
		//	}

		//	//���ջ�ǿ�,��ջ��Ԫ������������ַ�(������)���Ӧ,��ջ
		//	else if (!st.empty() && reference[st.top()] == reference[s[i]] - 5)
		//	{
		//		st.pop();
		//	}

		//	//��������������������,��ζ��һ��ʼ���Ǹ�������,���߱����Ŷ���,û�ж�Ӧ��������ջ����
		//	else
		//	{
		//		result = false;
		//		break;
		//	}
		//}

		for (char c : s)
		{
			//���Ϊ������,������ջ
			if (1 <= m[c] && m[c] <= 3)st.push(c);

			//���ջ�ǿ�,��ջ��Ԫ������������ַ�(������)���Ӧ,��ջ
			else if (!st.empty() && m[st.top()] == m[c] - 3)st.pop();
			//��������������������,��ζ��һ��ʼ���Ǹ�������,���߱����Ŷ���,û�ж�Ӧ��������ջ����
			else
			{
				result = false;
				break;//��������˰�
			}
		}
		//���for�������,ջ�ǿ�,��ζ�ſ����Ŷ���,��Ƿ�
		if (!st.empty()) 
			result = false;

		return result;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}