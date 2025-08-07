class Solution {
    bool check(vector<int>nums,int k,int a){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==a){
                k--;
                nums[i]=nums[i]*-1;
                nums[i+1]=nums[i+1]*-1;
            }
        }
        if(k<0)return false;
        return true;
    }
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int ones=0,neg=0;
        for(int in:nums){
            if(in==-1)neg++;
            if(in==1)ones++;
        }
       

        if(ones%2==1 && neg%2==1)return false;
        if(ones%2==0 && neg%2==1)return check(nums,k,1);
        if(ones%2==1 && neg%2==0)return check(nums,k,-1);
        else{
            return check(nums,k,1) || check(nums,k,-1);
        }
    }
};