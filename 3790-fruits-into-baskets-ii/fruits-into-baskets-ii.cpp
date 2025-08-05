class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        for(int i=0;i<fruits.size();i++){
            int x=0;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j] = INT_MIN;
                    x=1;
                    break;
                }
            }
            if(x==0)count++;
        }
        return count;
    }
};