class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int ch:arr){
            mp[ch]++;
        }
        int n=arr.size();
        vector<int>a;
        for(auto& it:mp)a.push_back(it.second);
        sort(a.begin(),a.end());
        int i=0;
        for(i;i<a.size();i++){
            if(k>=a[i]){
                k-=a[i];
            }
            else{
                break;
            }
        }
        return a.size()-i;
    }
};