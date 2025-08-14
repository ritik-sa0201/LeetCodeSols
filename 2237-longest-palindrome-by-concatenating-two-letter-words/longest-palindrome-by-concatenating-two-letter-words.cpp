class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp,same;
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1])same[words[i]]++;
            else mp[words[i]]++;
        }
        //lc-1 cl-1 gg-1
        //diff wala case
        int ans=0;
        for(auto&it:mp){
            string curr = it.first;
            string comp = curr;
            reverse(comp.begin(),comp.end());
            if(mp.find(comp)!=mp.end()){
               int mini = min(mp[curr],mp[comp]);
               ans +=mini*2;
            }
        }
        int flag = 0;
        for(auto&it:same){
            if(it.second%2==0)ans+=it.second*2;
            else{
                ans+=(it.second-1)*2;
                flag = 1;
            }
        }
        return flag==1?ans+2:ans;
    }
};