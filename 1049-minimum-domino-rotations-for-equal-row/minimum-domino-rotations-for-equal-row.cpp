class Solution {
   
   int bottom(vector<int>& tops, vector<int>& bottoms,int idx){
             int ans=0;
             for(int i=0;i<tops.size();i++){
                if(bottoms[i]==idx)continue;
                if(tops[i]!=idx && bottoms[i]!=idx){
                    ans = -1;
                    break;
                }
                if(tops[i]==idx && bottoms[i]!=idx)ans++;
             }
            return ans;
   }

    int top(vector<int>& tops, vector<int>& bottoms,int idx){
        int ans=0;
             for(int i=0;i<tops.size();i++){
                if(tops[i]==idx)continue;
                if(tops[i]!=idx && bottoms[i]==idx){
                    ans++;
                }
                if(tops[i]!=idx && bottoms[i]!=idx){
                    ans = -1;
                    break;
                }
             }
            return ans;
   }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         int res = INT_MAX;

          for(int i=1;i<7;i++){
            int bot = bottom(tops,bottoms,i);
            int top_r = top(tops,bottoms,i);
            if(bot!=-1)res = min(res,bot);
            if(top_r!=-1)res = min(res,top_r);
          }
          return res==INT_MAX?-1:res;
    }
};