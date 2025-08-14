class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int>mp;
        int j=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]]>1){
                ans++;
                mp.clear();
            }
            else j++;
        }
        return ans+1;
    }
};