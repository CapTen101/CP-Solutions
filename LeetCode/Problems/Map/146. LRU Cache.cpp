#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru_order; // list stores {key, value}
    int capacity;

    LRUCache(int n)
    {
        capacity = n;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            int value = cache[key]->second;
            lru_order.erase(cache[key]); // erase the element from the middle of the list

            lru_order.push_front({key, value}); // put the new element in the front
            cache[key] = lru_order.begin();     // store the new address of the new element in map
            return value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        // if already present, remove current element
        if (cache.find(key) != cache.end())
        {
            lru_order.erase(cache[key]); // remove the location of key inside list
            cache.erase(key);            // remove from cache as well
        }

        // can't insert anymore, eject lru element
        if (cache.size() == capacity)
        {
            cache.erase(lru_order.back().first); // remove last element
            lru_order.pop_back();                // remove from cache as well
        }

        lru_order.push_front({key, value}); // insert at front
        cache[key] = lru_order.begin();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}