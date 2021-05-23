#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


class LRUCache {
    int _capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator> > mp;

public : 

    LRUCache(int capacity) : _capacity(capacity) {}

    void put(int key, int value) {
        //Check if key is already
        if (mp.find(key) != mp.end() ) {
            //Update the list to move it to front
            keys.erase(mp[key].second);
            keys.push_front(key);
            int val = mp[key].first;
            mp[key] = {value, keys.begin()};
        } else {
            //If there is no capacity , we need to remove the last element from the list and remove it from map as well
            if(keys.size() == _capacity) {
                int k = keys.back();
                mp.erase(k);
                keys.pop_back();
            }
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        }
    }

    int get(int key) {
        //Check if the key is present in the map, 
        if ( mp.find(key) != mp.end() ) {
            //Erase the data from the list and add it in front.
            keys.erase(mp[key].second);
            keys.push_front(key);
            int val = mp[key].first;
            mp[key] = {val, keys.begin()};
            return val;
            
        }
        return -1;
    }
        
};

int main()
{
    return 0;
}
