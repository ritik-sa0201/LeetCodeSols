class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp,curr;

        for(char ch:t)mp[ch]++;
           //t ka map

           int m = s.size();
           int n = t.size();

           int i=0,j=0,count=0, ai=-1,aj=-1,minm=INT_MAX;
           while(j<m && i<m){
              curr[s[j]]++;
              if(mp.find(s[j])!=mp.end()){
                if(curr[s[j]]==mp[s[j]])count++;
              }

              if(count==mp.size()){
                while(count==mp.size() && i<=j){
                     if(minm > j-i+1){
                        ai = i;
                        aj = j;
                        minm = j-i+1;
                     }
                   
                   if(mp.find(s[i])!=mp.end()){
                   if(curr[s[i]]==mp[s[i]])count--;
                   }
                   curr[s[i]]--;
                   i++;
                } 
              }
              j++;
           }
            string ans="";
            if(ai==-1 || aj==-1)return "";
            for(int x=ai;x<=aj;x++){
                ans+= s[x];
            }
            return ans;
    }
};