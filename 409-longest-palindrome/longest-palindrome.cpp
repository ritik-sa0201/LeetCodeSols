class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(int ch:s)mp[ch]++;;
        int ans=0;
        bool odd=false;
        for(auto& it:mp){
            int c=it.second;
            if(c%2==0){
                ans+=c;
            }
            else{
              odd=true;
               int i=c/2;
               ans+=i*2;
            }
        }
        return odd?ans+1:ans;
    }
};