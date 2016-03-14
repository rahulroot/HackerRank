#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <fstream>
using namespace std;

struct Node
{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

typedef struct Node NODE;

class Cache
{
   protected: 
   	map<int,Node*> mp; //map the key to the node in the linked list
  	int cp;  //capacity
   	Node* tail; // double linked list tail pointer
  	Node* head; // double linked list head pointer
   	virtual void set(int, int) = 0; //set function
   	virtual int get(int) = 0; //get function

};

struct Node* getNode(int key, int value)
{
	struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->key = key;
	tmp->value = value;
	tmp->prev = tmp->next = NULL;
	return tmp;
}

void deleteNode(NODE *tmp)
{
	if(tmp!=NULL)
  {
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
  }
}



class LRUCache : public Cache
{
	public:
		LRUCache(int cap) { 
			cp = cap;
			tail = head = NULL;
			count = 0;
		}
		~LRUCache() { 
			//cout <<"LRUCache Destructor" << endl;
			mp.clear();
			deleteList();
		}
		int count;
		void set(int key, int value);
		int get(int key);
		void printList(NODE *head);
		void printCache();
		void SearchAndDelete(int key);
	private:
		void add(int key, int value);
		void deleteList();
};

void LRUCache::deleteList()
{
  while(head != NULL)
  {
    NODE *tmp = head;
    head = head->next;
    deleteNode(tmp);
  }
  head = NULL;
}


void LRUCache::SearchAndDelete(int key)
{
  if (head->key == key)
  {
    NODE *tmp = head;
    head = head->next;
		if(head)
    	head->prev = NULL;
		return;
  }

  NODE *cur = head;
  while(cur != NULL)
  {
    if(cur->key == key)
    {
      NODE *tmp = cur;
      cur->prev->next = cur->next;
      if(cur->next)
        cur->next->prev = cur->prev;
		//	deleteNode(tmp);
			break;
    }
    cur = cur->next;
  }
}

void LRUCache::printCache()
{
	cout <<"Printing Cache.." << endl;
	map<int, Node*>::iterator it;
	for(it=mp.begin(); it!=mp.end(); ++it)
		cout << it->first <<' '<< it->second->key <<' '<< it->second->value << endl;
}

void LRUCache::printList(NODE *head)
{
  int cnt = 0;
  while(head != NULL)
  {
    printf("%d->%d ", head->key, head->value);
    head = head->next;
  }
	cout <<"Tail node :" << tail->key <<' ' << tail->value << endl;

}

void LRUCache::add(int key, int value)
{
		map<int,NODE*>::iterator it;
		it = mp.find(key);
		if(it!=mp.end())
		{
			mp.erase(it);
			SearchAndDelete(key);
			count--;
		}
		/* remove the same from linked list */
		struct Node *tmp = NULL;
    if(!head)
  	{
    	tmp = getNode(key, value);
    	head = tmp;
    	tail = tmp;
    	count++;
    	mp.insert(make_pair(key, tmp));
  	}
		else
		{
			NODE *cur = head;
    	tmp = getNode(key,value);
			tmp->next = cur;
			cur->prev = tmp;
			//tail = cur;
			head = tmp;
			count++;
			mp.insert(make_pair(key, tmp));
		}
}


void LRUCache::set(int key, int value)
{
	struct Node *tmp = NULL;
	if(!head)
	{
		tmp = getNode(key, value);
		head = tmp;
		tail = tmp;
		count++;
		mp.insert(make_pair(key, tmp));
	}
	else if(count < cp)
	{
		/* find the key in LRUCache */
		/* if found, remvoe it and add it back at the fron tof LRUCache */
    add(key, value);
	}
	else if( count >= cp)
	{
		/* remove the node from tail, make some space and add the new node at head */
		cout <<"Can't add any more node in LRUCache..need to remove the LRU" << endl;
		/* delete the tail node from linked list first */
		/* node before the tail node, will be our new tail */
		struct Node *to_del = tail;
		map<int,NODE*>::iterator it;
		it = mp.find(tail->key);
		if(it!=mp.end())
		{
			mp.erase(it);
			count--;
		}
		to_del->prev->next = NULL;
		tail = to_del->prev;
		//deleteNode(to_del);
		/* Add the new key in LRUCache */
		NODE *cur = head;
    tmp = getNode(key,value);
		tmp->next = cur;
		cur->prev = tmp;
		//tail = cur;
		head = tmp;
		count++;
		mp.insert(make_pair(key, tmp));
	}
	//printList(head);
}

int LRUCache::get(int key)
{
	map<int,NODE*>::iterator it;
	it = mp.find(key);
	if(it!=mp.end())
	{
		//cout <<"Re-inserting it again " << key <<' '<< it->second->value << endl;
		add(key, it->second->value);
		//printList(head);
		return it->second->value;
	}
	return -1;
}

int main() 
{
	freopen("./sample.txt", "r", stdin);
  int n, capacity,i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for(i=0;i<n;i++) 
	{
     string command;
     cin >> command;
     if(command == "get") 
		 {
        int key;
        cin >> key;
			//	cout <<"Looking for key : " << key << endl;
        cout << l.get(key) << endl;
     } 
     else if(command == "set") 
		 {
       int key, value;
       cin >> key >> value;
			 //cout <<"Inserting " << key <<' '<< value << endl;
       l.set(key,value);
     }
  }
	//l.printCache();
  return 0;
}


	
