class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        queue<int>q;
        for(int i : nums){
            q.push(i);
        }
        while(q.size()>1){
            int sz = q.size();
            int prev=q.front();
            if(sz==2){
            int a = q.front();q.pop();
            int b = q.front();q.pop();
            return (a+b)%10;
            }
            else if(sz>2){
              int a = q.front();q.pop();
              int b = q.front();q.pop();
              q.push((a+b)%10);
              prev = b;
            }
            for(int i=0;i<sz-2;i++){
            int val = q.front();q.pop();
             q.push((val + prev)%10);
             prev= val;
            }
        }
        return q.front();
    }
};