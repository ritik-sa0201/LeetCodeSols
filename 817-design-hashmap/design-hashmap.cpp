class MyHashMap {
public:
vector<pair<int,int>>a;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0;i<a.size();i++){
            if(a[i].first == key){
                a[i].second = value;
                return;
            }
        }
        a.push_back({key,value});
        return;
    }
    
    int get(int key) {
        for(int i=0;i<a.size();i++){
            if(a[i].first==key)return a[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<a.size();i++){
            if(a[i].first==key){
                swap(a[i],a[a.size()-1]);
                a.pop_back();
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */