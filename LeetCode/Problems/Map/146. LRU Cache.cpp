#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    vector<int> cache;
    set<int> lru_keys;
    int capacity;

    LRUCache(int capacity)
    {
        cache.resize(capacity);
        fill(cache.begin(), cache.end(), -1);
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (key < cache.size())
        {
            if (cache[key - 1] == -1)
                return -1;
            else
            {
                this->lru_keys.erase(key);
                return cache[key - 1];
            }
        }

        else
            return -1;
    }

    void put(int key, int value)
    {
        if (key > capacity)
        {
        }
        else
        {
            cache[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}