class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        bool flag1=false;
        bool flag2 = false;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0){
                sum1+=1;
                flag1=true;
            }
            else  sum1+=nums1[i];
        }
          for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0){
                flag2=true;
                sum2+=1;
            }
            else  sum2+=nums2[i];
        }
        if(flag1==false && flag2==false && sum1==sum2)return sum1;
        if(sum2>sum1 && flag1==true)return sum2;
        if(sum2>sum1 && flag1==false)return -1;
        if(sum2<sum1 && flag2==true)return sum1;
        if(sum2<sum1 && flag2==false)return -1;
        if(sum2==sum1 && (flag1==true || flag2==true))return sum2;
        return -1;
    }
};