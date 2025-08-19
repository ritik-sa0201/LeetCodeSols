class Solution {
    void solve(int i,string op,string s,vector<string>& ans){
        if(i==s.size()){
            ans.push_back(op);
            return;
        }
        if(s[i] >='a' && s[i]<='z'){
             op+=s[i];
            solve(i+1,op,s,ans);
            op.pop_back();
            op+=toupper(s[i]);
            solve(i+1,op,s,ans);
            op.pop_back();
            }
        else if(s[i]>='A' && s[i]<='Z'){
             op+=s[i];
            solve(i+1,op,s,ans);
            op.pop_back();
            op+=tolower(s[i]);
            solve(i+1,op,s,ans);
            op.pop_back();
        }
        else{
           op+=s[i];
           solve(i+1,op,s,ans);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(0,"",s,ans);
        return ans;
    }
};