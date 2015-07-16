struct CacheNode
{
    int key;
    int val;
    CacheNode(int k, int v): key(k), val(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(!cacheMap.count(key))
            return -1;
        else
        {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            return cacheMap[key]->val;
        }
    }
    
    void set(int key, int value) {
        if(!cacheMap.count(key))
        {
            if(cacheList.size() == size)
            {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else
        {
            cacheMap[key]->val = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
        
    }
private:
    int size;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
};
