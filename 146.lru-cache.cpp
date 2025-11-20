/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:

    unordered_map<int, int> cache;
    LRUCache(int capacity) {

        

        
        
    }
    
    int get(int key) {

        if(cache.find(key) != cache.end())
        {
            return cache[key];
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {

        cache[key] = value;

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

