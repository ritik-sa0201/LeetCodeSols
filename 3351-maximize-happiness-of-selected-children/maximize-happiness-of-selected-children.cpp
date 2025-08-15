class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int n=happiness.size();
          int idx=0;
          long long ans=0;
         for(int i=n-1;i>=n-k;i--){
            if(happiness[i]-idx>=0)ans+=happiness[i]-idx;
               idx++;
         }
        return ans;
    }
};