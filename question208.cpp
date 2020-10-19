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


	/*首先从根结点的子结点开始与 word 第一个字符进行匹配，一直匹配到前缀链上没有对应的字符，
	这时开始不断开辟新的结点，直到插入完 word 的最后一个字符，
	同时还要将最后一个结点isEnd = true; ，表示它是一个单词的末尾。*/
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
	/*从根结点的子结点开始，一直向下匹配即可，如果出现结点值为空就返回 false，如果匹配到了最后一个字符，那我们只需判断 node->isEnd即可。*/
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