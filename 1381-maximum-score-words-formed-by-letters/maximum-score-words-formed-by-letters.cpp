class Solution {

    int solve(int i,vector<string>& words,unordered_map<char,int>&mp,vector<int>& score){
        if(i==words.size()){
            return 0;
        }
        int ans=0;
        int sc=0;
        unordered_map<char,int>temp=mp;

        for(int j=0;j<words[i].size();j++){
             if(mp.find(words[i][j])==mp.end()){
                sc=0;
                break;
             }
             sc += score[words[i][j] - 'a'];
               mp[words[i][j]]--;
               if(mp[words[i][j]] == 0)mp.erase(words[i][j]);
        }
        
        //pick word
         if(sc) ans = max(ans,sc + solve(i+1,words,mp,score));
         mp=temp;
         //not pick word
         ans = max(ans,solve(i+1,words,mp,score));

        return ans;
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(char ch:letters){
            mp[ch]++;
        }
        return solve(0,words,mp,score);
    }
};