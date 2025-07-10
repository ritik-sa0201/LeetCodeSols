class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int lucky = -1;
        for(auto&it:mp){
            if(it.second == it.first){
                lucky = max(lucky,it.first);
            }
        }
        return lucky;
    }
};