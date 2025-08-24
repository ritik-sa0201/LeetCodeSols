class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m=votes[0].size();
        vector<vector<int>>count(26,vector<int>(m,0));
//   1 2 3 4 5 6 
// A 5 0 0
// B 0 2 3
// C 0 3 2

       for(string str : votes){
        for(int i=0;i<str.size();i++){
            int x = count[str[i]-'A'][i];
            x++;
            count[str[i]-'A'][i]=x;
        }
       }
       
         vector<char>teams(votes[0].begin(),votes[0].end());
        
            sort(teams.begin(), teams.end(), [&](char a, char b) {
            for(int i=0; i<m; i++) {
                if(count[a-'A'][i] != count[b-'A'][i])
                    return count[a-'A'][i] > count[b-'A'][i];
            }
            return a < b; 
        });

          
return string(teams.begin(),teams.end());
    }
};