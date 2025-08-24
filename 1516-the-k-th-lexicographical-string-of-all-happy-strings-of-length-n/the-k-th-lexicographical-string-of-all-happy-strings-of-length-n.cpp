class Solution {
    int count=0;
    string ans="";

     void solve(int n,int k,string &curr,char prev){
             if(curr.size()==n){
                count++;
                if(count==k){
                    ans=curr;
                    return;
                }
                return;
             }

             for(int i=0;i<3;i++){
                char ch=char(97+i);
                if(prev=='q' || prev!=ch){
                    curr.push_back(ch);
                    solve(n,k,curr,ch);
                    curr.pop_back();
                }
             }
     }

public:
    string getHappyString(int n, int k) {
        string curr="";
        solve(n,k,curr,'q');
        return ans;
    }
};