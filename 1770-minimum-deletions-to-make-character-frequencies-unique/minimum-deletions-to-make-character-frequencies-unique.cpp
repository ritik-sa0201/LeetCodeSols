class Solution {
public:
    int minDeletions(string s) {
     unordered_map<char,int>mp;
     for(char ch:s)  mp[ch]++;

     vector<int>a;
     for(auto& it:mp)a.push_back(it.second);
     //3 3 2 
         sort(a.begin(),a.end(),greater<int>());
         set<int>st;
        int ans=0;
         for(int i=0;i<a.size();i++){
            if(st.find(a[i])==st.end()){
                st.insert(a[i]);
            }
            else{
                while(st.find(a[i])!=st.end()){
                    ans++;
                    a[i]--;
                }
                if(a[i]!=0)st.insert(a[i]);
            }
         }
         return ans;
    }

};