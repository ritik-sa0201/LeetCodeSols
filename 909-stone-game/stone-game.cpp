class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int i=0,j=n-1;
         int cntA=0,cntB=0;
         while(i<=j){
            if(piles[i]>=piles[j]){
                cntA+=piles[i];
                i++;
                cntB+=piles[j];
                j--;
            }
          else if(piles[i]<piles[j]){
            cntA+=piles[j];
            j--;
            cntB+=piles[i];
            i++;
          }
         }
         return cntA>cntB;
    }
};