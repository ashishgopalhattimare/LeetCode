// https://leetcode.com/problems/lru-cache/
// Medium
// Map and List, Iterators

class LRUCache {
public:
    
    unordered_map<int, list<int>::iterator>pos;
    unordered_map<int,int>map;
    list<int>ll; // contains only key
    
    
    int maxSize;
    
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        
        ll.erase(pos[key]);     // remove from the list
        ll.push_front(key);     // push it to most recently used
        
        pos[key] = ll.begin();  // removing iterator from list is easy
        
        return map[key];
    }
    
    void put(int key, int value) {
        
        if(map.find(key) == map.end()) {// if not available
            if(ll.size() == maxSize)    // remove the least recently used
            {
                pos.erase(ll.back());   // remove pos address iterator
                map.erase(ll.back());   // remove key value pair
                ll.pop_back();          // remove key
            }
        }
        else { // already in the list, move it to most recetly used position
            ll.erase(pos[key]); // remove iterator
        }
        
        ll.push_front(key);
        pos[key] = ll.begin();
        
        map[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
