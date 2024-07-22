class RandomizedCollection {
private:
    vector<int> elements;
    unordered_map<int, set<int>> counter;
    int length;

public:
    RandomizedCollection() {
        length = 0;
    }
    
    bool insert(int val) {
        bool present = counter.count(val);
        elements.push_back(val);
        counter[val].insert(length);
        length++;
        return !present;
    }
    
    bool remove(int val) {
        if (counter.count(val)) {
            int toBeRemovedIndex = *(counter[val].begin());

            int lastElement = elements[length-1];
            elements[toBeRemovedIndex] = lastElement;
            counter[lastElement].erase(length-1);
            elements.pop_back();
            counter[val].erase(toBeRemovedIndex);
            if (toBeRemovedIndex != length-1) counter[lastElement].insert(toBeRemovedIndex);

            if (counter[val].size() == 0) counter.erase(val);
            length--;

            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index = rand()%(length);
        return elements[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
