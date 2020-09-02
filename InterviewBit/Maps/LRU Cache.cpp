#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

class LRUCache
{
public:
    int key;
    int value;

    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
};

map<int, int> lrucache;  // used to store actual values.
int sizeofcache;         // used for comparing size of map to the caapcity. this is will be assigned with capacity of the map given.
list<int> timeorderlist; // will store the most recent added list of items in the map since map cannot track that. the most recent one being in the last

LRUCache::LRUCache(int capacity)
{
    lrucache.clear();      // resetting the map
    timeorderlist.clear(); // resetting the recent items list
    sizeofcache = capacity;
};

int LRUCache::get(int key)
{
    if (lrucache.find(key) == lrucache.end())
        return -1; // key not found in the map;

    else // if found
    {
        timeorderlist.remove(key);
        timeorderlist.push_back(key);
        return lrucache[key];
    }
}

void LRUCache::set(int key, int value)
{
    if (sizeofcache == 0)
        return; // if the provided max capacity is zero, then return.

    // if (lrucache.find(key) != lrucache.end() && lrucache.size() <= sizeofcache) // if found in the cache and there is some space left in the cache.
    // {
    //     if (lrucache.size() == sizeofcache)
    //     {
    //         timeorderlist.pop_front();    // removing the least used item from the list
    //         timeorderlist.push_back(key); // pushing to the last, because the most recent stays in the beginning
    //         lrucache[key] = value;
    //         return;
    //     }

    //     timeorderlist.remove(key);
    //     timeorderlist.push_back(key); //  insert the most recently used key
    //     lrucache[key] = value;
    //     return;
    // }

    // // remaining case is if key is not found and size <= capacity
    // if (lrucache.size() == sizeofcache)
    // {
    //     lrucache.insert({key, value}); // insert the element
    //     timeorderlist.pop_front(); // taking out the least used key
    //     timeorderlist.push_back(key); // inserting the recently added key in the time order
    //     return;

    // }
    // lrucache.insert({key, value});
    // timeorderlist.push_back(key);
    // return;
    if (lrucache.size() == sizeofcache)
    {
        if (lrucache.find(key) == lrucache.end()) // if not found in the map
        {
            lrucache.insert({key, value});
            int removefrommap = timeorderlist.front();
            timeorderlist.pop_front();
            timeorderlist.push_back(key);
            lrucache.erase(removefrommap);
            return;
        }
        else // if found in the map
        {
            lrucache[key] = value;
            timeorderlist.remove(key);
            timeorderlist.push_back(key);
            return;
        }
    }
    else // if size is less than capacity
    {
        if (lrucache.find(key) == lrucache.end()) // if not found in the map
        {
            lrucache.insert({key, value});
            timeorderlist.push_back(key);
            return;
        }
        else // if found in the map
        {
            lrucache[key] = value;
            timeorderlist.remove(key);
            timeorderlist.push_back(key);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}