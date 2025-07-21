class Solution {
    void solve(int i,int n,string op,vector<string>&ans,bool zero){
        if(i==n){
            ans.push_back(op);
           return;
        }
        solve(i+1,n,op+"1",ans,false);
        if(!zero){
            solve(i+1,n,op+"0",ans,true);
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(0,n,"",ans,false);
        return ans;
    }
};