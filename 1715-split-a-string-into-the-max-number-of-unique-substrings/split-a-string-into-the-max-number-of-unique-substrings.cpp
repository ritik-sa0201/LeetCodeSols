class Solution {
    int res=INT_MIN;
    void solve(int i,string &s,set<string>&st){
        if(i==s.size()){
               res = max(res,(int)st.size());
            return;
        }
     
        for(int j=i;j<s.size();j++){
            string str = s.substr(i,j-i+1);
                  if(st.find(str)==st.end()){
                    st.insert(str);
                    solve(j+1,s,st);
                    st.erase(str);
                  }
        }
    }
public:
    int maxUniqueSplit(string s) {
        set<string>st;
        solve(0,s,st);
        return res==INT_MIN?1:res;
    }
};