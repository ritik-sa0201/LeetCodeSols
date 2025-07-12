class RandomizedSet {
public:
    unordered_map<int, int> valToIndex;
    vector<int> values;

    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end())
            return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end())
            return false;
        
        int index = valToIndex[val];
        int lastVal = values.back();

      
        values[index] = lastVal;
        valToIndex[lastVal] = index;

        
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        if (values.empty()) return -1;
        int randIndex = rand() % values.size();
        return values[randIndex];
    }
};
