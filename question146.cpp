#include<iostream>
#include<map>
using namespace std;

//创建链表
struct Node
{
	int key;
	int value;
	Node* pre;
	Node* next;
	// 构造函数初始化
	Node(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
};


class LRUCache {
public:
	LRUCache(int capacity) {
		this->size = capacity;
		head = NULL;
		tail = NULL;
	}

	// 获取缓冲区中 key 对应的 value
	int get(int key) {
		// 1.当该 key 值存在
		if (p.count(key) > 0)
		{
			Node *cur = p[key];
			int value = cur->value;
			remove(cur);// 这里仅仅删除哈希双向链表中的节点，不必删除哈希表中的
			setHead(cur);// 将节点重新插入到缓冲区的头部
			return value;
		}

		//2.当该key值不存在
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		// 1.当该 key 值存在
		if (p.count(key) > 0)
		{
			// 删除该 key 对应的原来节点
			Node* cur = p[key];
			cur->value = value;
			remove(cur);    // 这里仅仅删除哈希双向链表中的节点，不必删除哈希表中的                                
			// 将节点重现插入到缓冲区的头部
			setHead(cur);
		}
		else// 2.当该 key 值不存在
		{
			Node *node = new Node(key, value);
			//判断当前缓冲区大小是否已满
			if (p.size() >= size)
			{
				//删除尾部结点
				map<int, Node*>::iterator it = p.find(tail->key);
				remove(tail);
				p.erase(it);
				setHead(node);
				p[key] = node;
			}
			else
			{
				setHead(node);
				p[key] = node;
			}
		}
		
	}

	//删除节点
	void remove(Node *cur)
	{
		if (cur == head)
		{
			head = cur->next;
		}
		else if (cur == tail)
		{
			tail = cur->pre;
		}
		else
		{
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
		}
	}

	//将节点插入头部
	void setHead(Node *cur)
	{
		cur->next = head;
		if (head != NULL)
		{
			head->pre = cur;
		}
		head = cur;//重新更新head

		if (tail == NULL)
		{
			tail = head;
		}
	}

private:
	int size;
	Node *head;
	Node *tail;
	map<int, Node*>p;
};

int main()
{
	LRUCache *cache = new LRUCache(2);

	cache->put(1, 1);
	cache->put(2, 2);
	cache->get(1);       // 返回  1
	cache->put(3, 3);    // 该操作会使得关键字 2 作废
	cache->get(2);       // 返回 -1 (未找到)
	cache->put(4, 4);    // 该操作会使得关键字 1 作废
	cache->get(1);       // 返回 -1 (未找到)
	cache->get(3);       // 返回  3
	cache->get(4);       // 返回  4

	
	system("pause");
	return EXIT_SUCCESS;
}