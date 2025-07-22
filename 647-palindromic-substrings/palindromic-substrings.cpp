class Solution {
public:
   vector<vector<int>>dp;

   int check(string s,int i,int j){
    if(i>=j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i]==s[j])return dp[i][j] =  check(s,i+1,j-1);
    else return dp[i][j] =  0;
   }



    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                     if(check(s,i,j))count++;
            }
        }
        return count;
    }
};