class Solution {
public:
    vector<string> ans;
 
    void solve(int i, string &s, unordered_map<string,int>& mp, string curr) {
        if(i == s.size()){
            if(!curr.empty() && curr.back() == ' ') curr.pop_back();
            ans.push_back(curr);
            return;
        }

        string q = curr;
        string p = s;

      
        for(int j = i; j < s.size(); j++){
            string str = s.substr(i, j - i + 1);
            if(mp.find(str) != mp.end()){
                curr += str;
                curr += " ";
                solve(j+1, s, mp, curr);  
                curr = q; 
            }
        }
    }
  
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto &str : wordDict){
            mp[str]++;
        }
        solve(0, s, mp, "");
        return ans;
    }
};
