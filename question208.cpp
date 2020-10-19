#include<iostream>
#include<vector>
using namespace std;

class Trie {

private:
	bool isEnd;
	Trie* next[26];

public:
	/** Initialize your data structure here. */
	Trie() {
		isEnd = false;
		memset(next, 0, sizeof(next));

	}

	/** Inserts a word into the trie. */


	/*���ȴӸ������ӽ�㿪ʼ�� word ��һ���ַ�����ƥ�䣬һֱƥ�䵽ǰ׺����û�ж�Ӧ���ַ���
	��ʱ��ʼ���Ͽ����µĽ�㣬ֱ�������� word �����һ���ַ���
	ͬʱ��Ҫ�����һ�����isEnd = true; ����ʾ����һ�����ʵ�ĩβ��*/
	void insert(string word) {
		
		Trie* node = this;
		for (char c : word)
		{
			if (node->next[c - 'a'] == NULL)
			{
				node->next[c - 'a'] = new Trie();
			}
			node = node->next[c - 'a'];
		}

		node->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	/*�Ӹ������ӽ�㿪ʼ��һֱ����ƥ�伴�ɣ�������ֽ��ֵΪ�վͷ��� false�����ƥ�䵽�����һ���ַ���������ֻ���ж� node->isEnd���ɡ�*/
	bool search(string word) {
		Trie* node = this;
		for (char c : word)
		{
			node = node->next[c - 'a'];
			if (node == NULL)
			{
				return false;
			}
				
		}
		
		return node->isEnd;
		
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* node = this;
		for (char c : prefix)
		{
			node = node->next[c - 'a'];
			if (node == NULL)
			{
				return false;
			}
		}

		return true;
	}


};

int main()
{
	Trie* obj = new Trie();
	obj->insert("apple");
	bool param_2 = obj->search("apple");
	bool param_3 = obj->startsWith("app");
	system("pause");
	return EXIT_SUCCESS;
}