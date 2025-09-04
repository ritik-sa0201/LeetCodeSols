class Solution {
    int revDig(int n){
        int ans=0;
        while(n!=0){
            ans = ans*10 + (n%10);
            n /= 10;
        }
        return ans;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for(int num : nums){
            st.insert(num);
            st.insert(revDig(num)); 
        }
        return st.size();
    }
};
