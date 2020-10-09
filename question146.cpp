#include<iostream>
#include<map>
using namespace std;

//��������
struct Node
{
	int key;
	int value;
	Node* pre;
	Node* next;
	// ���캯����ʼ��
	Node(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
};


class LRUCache {
public:
	LRUCache(int capacity) {
		this->size = capacity;
		head = NULL;
		tail = NULL;
	}

	// ��ȡ�������� key ��Ӧ�� value
	int get(int key) {
		// 1.���� key ֵ����
		if (p.count(key) > 0)
		{
			Node *cur = p[key];
			int value = cur->value;
			remove(cur);// �������ɾ����ϣ˫�������еĽڵ㣬����ɾ����ϣ���е�
			setHead(cur);// ���ڵ����²��뵽��������ͷ��
			return value;
		}

		//2.����keyֵ������
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		// 1.���� key ֵ����
		if (p.count(key) > 0)
		{
			// ɾ���� key ��Ӧ��ԭ���ڵ�
			Node* cur = p[key];
			cur->value = value;
			remove(cur);    // �������ɾ����ϣ˫�������еĽڵ㣬����ɾ����ϣ���е�                                
			// ���ڵ����ֲ��뵽��������ͷ��
			setHead(cur);
		}
		else// 2.���� key ֵ������
		{
			Node *node = new Node(key, value);
			//�жϵ�ǰ��������С�Ƿ�����
			if (p.size() >= size)
			{
				//ɾ��β�����
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

	//ɾ���ڵ�
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

	//���ڵ����ͷ��
	void setHead(Node *cur)
	{
		cur->next = head;
		if (head != NULL)
		{
			head->pre = cur;
		}
		head = cur;//���¸���head

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
	cache->get(1);       // ����  1
	cache->put(3, 3);    // �ò�����ʹ�ùؼ��� 2 ����
	cache->get(2);       // ���� -1 (δ�ҵ�)
	cache->put(4, 4);    // �ò�����ʹ�ùؼ��� 1 ����
	cache->get(1);       // ���� -1 (δ�ҵ�)
	cache->get(3);       // ����  3
	cache->get(4);       // ����  4

	
	system("pause");
	return EXIT_SUCCESS;
}