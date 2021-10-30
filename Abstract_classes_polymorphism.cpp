################################ PROVIDED #############################################
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

################################ END PROVIDED #############################################
################################ MY CODE START #############################################

class LRUCache: public Cache  {
    public:
        LRUCache() = default;
        LRUCache(int capacity) 
        {
            cp = capacity;
            head = NULL;
            tail = NULL;
        };
    
        void set(int, int) override;
        int get(int) override;
        
        ~LRUCache(); // no virtual destructor provided
                     // all ints though so does not need manual cleanup?
} ;

void LRUCache::set(int key, int val)
{

    if (mp.empty()) {
        Node *myNewNode = new Node(key, val);
        head = tail = myNewNode;
        
        mp[key] = myNewNode;
        
    } else if (mp.find(key) == mp.end()) { 
        Node *myNewNode = new Node(NULL, head, key, val);
        Node *myOldHead = head;
        Node *myOldTail = tail;

        if (mp.size() == cp) {
            tail = myOldTail->prev;

            mp.erase(myOldTail->key);
            free(myOldTail);
            
            tail->next = NULL;
        }
        
        myNewNode->next = myOldHead;
        myOldHead->prev = myNewNode;
        head = myNewNode;
        
        mp[key] = myNewNode;
        
    } else {
        Node *myFoundNode = mp[key];
        Node *myOldHead = head;
        Node *myOldTail = tail;
        
        myFoundNode->value = val;
        mp[key]->value = val;
        
        if (myFoundNode == head) {
            return;
        }
        
        if (mp.size() == 1) {
            return;
        }
        
        if (myFoundNode == tail) {
            tail = myOldTail->prev;
            tail->next = NULL;
        
        } else if (myFoundNode != head) {
            Node *myFoundNext = myFoundNode->next;
            Node *myFoundPrev = myFoundNode->prev;
            
            myFoundNext->prev = myFoundPrev;
            myFoundPrev->next = myFoundNext;    
        }
                
        myFoundNode->prev = NULL;
        myFoundNode->next = myOldHead;
        myOldHead->prev = myFoundNode;
        head = myFoundNode;
    }
    
}

int LRUCache::get(int key)
{
    const auto myIt = mp.find(key);
    
    if (myIt != mp.end()) {
        set(key, myIt->second->value);
        return myIt->second->value;
    } 

    return -1;
}

LRUCache::~LRUCache()
{
    auto &myIt = head;
    while (myIt->next != NULL) {
        myIt = myIt->next;
        free(myIt->prev);
    }
    
    free(myIt);
}

################################ MY CODE END ##########################################
################################ PROVIDED #############################################

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
################################ END PROVIDED #############################################
