class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
       int i=0,j=2;
       while(j<=nums.size()-1){
        if(nums[j]-nums[i] > k)return {};
        else{
            vector<int>temp;
            for(int k=i;k<=j;k++)temp.push_back(nums[k]);
            ans.push_back(temp);
            i=j+1;
            j=j+3;
        }
       }
       return ans;
    }
};