class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
            long long sum = 0;
            int i=0,j=0;
            int n=nums.size();
            vector<int>ans(n,-1);
            if(n<(2*k+1))return ans;
            for(j;j<(2*k+1);j++){
            sum +=nums[j];
            }
            ans[(2*k+1)/2]= sum/(2*k+1);

            while(j<n){
                sum-=nums[i];
                i++;
                sum+=nums[j];
                j++;
                 ans[(j+i)/2]= sum/(2*k+1);
            }
            return ans;
    }
};