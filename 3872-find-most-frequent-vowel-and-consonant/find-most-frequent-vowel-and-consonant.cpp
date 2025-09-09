class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(char ch:s)mp[ch]++;
        int v=0,c=0;
        for(auto& it:mp){
            if(it.first=='a'||it.first=='u'||it.first=='o'||it.first=='i'||it.first=='e'){
                v = max(v,it.second);
            }
            else{
                 c= max(c,it.second);
            }
        }
        return v+c;
    }
};