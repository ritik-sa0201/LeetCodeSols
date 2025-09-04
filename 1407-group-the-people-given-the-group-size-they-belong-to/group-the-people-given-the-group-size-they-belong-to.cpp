class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
       map<int,vector<int>>mp;
        for(int i=0;i<gs.size();i++){
            mp[gs[i]].push_back(i);
        }
        vector<vector<int>>ans;
        
        for(auto& it : mp){
            int sz  =it.first;
            int i=0;
            int k=0;
            vector<int>temp;
            while(i<it.second.size()){
                    temp.push_back(it.second[i]);
                    i++;
                    k++;
                 if(k==sz){
                    ans.push_back(temp);
                    temp.clear();
                    k=0;
                 }
                    
            }
        }
        return ans;

    }
};