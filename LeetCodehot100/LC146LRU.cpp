#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> caches;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {

    }

    int get(int key) {
        auto iter = map.find(key);
        if (iter == map.end()) {
            return -1;
        }
        auto it = iter->second;
        int value = it->second;
        caches.splice(caches.begin(), caches, it);
        return value;
    }

    void put(int key, int value) {
        auto iter = map.find(key);
        if (iter != map.end()) { //找到
            auto it = iter->second;
            it->second = value;
            caches.splice(caches.begin(), caches, it);
            return;
        }
        // 没找到
        if (caches.size() == capacity) {
            auto last = caches.back();
            map.erase(last.first);
            caches.pop_back();
        }
        caches.push_front({key, value});
        map[key] = caches.begin();
    }
};
