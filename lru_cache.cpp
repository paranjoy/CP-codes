/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

put(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

//code snippet

class LRUCache {
public:
    struct QueueNode {
        int key;
        
        QueueNode *prev, *next;
        
        QueueNode(int key) : key(key) {}
    };
    
    QueueNode *front, *back;
    
    int size = 0, capacity;
    
    unordered_map<int,int> cache;
    
    unordered_map<int,QueueNode*> q;
    
     LRUCache(int capacity) {
      
         this->capacity = capacity;
         
         front = back = nullptr;
    }
    
    int get(int key) {
        
        if (cache.count(key)) {
            
            if (q[key] != back) {
               
                q[key]->prev->next = q[key]->next;
                
                if (front == q[key]) 
                    front = q[key]->prev;
                else 
                    q[key]->next->prev = q[key]->prev;

                back->prev = q[key];
                
                q[key]->next = back;
                
                q[key]->prev = nullptr;
                
                back = q[key];
            }
            return cache[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        
        if (cache.count(key))
            get(key);
        
        else {
            
            size = size > capacity ? size : size+1;
            
            if (size > capacity) {
                
                cache.erase(front->key);
                
                if (size == 2)
                    front = back = nullptr;
                else {
                    front = front->prev;
                    
                    front->next = nullptr; 
                }
            }
            
            q[key] = new QueueNode(key);
            
            q[key]->prev = nullptr;
            
            if (front == nullptr) {
                front = back = q[key];
                q[key]->next = nullptr;
            } 
            else {
                q[key]->next = back;
                
                back->prev = q[key];
                
                back = q[key];
            }
        }
        
        cache[key] = value;
    }
};

/*
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

