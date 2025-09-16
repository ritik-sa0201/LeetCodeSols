class Solution {
   int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

    long long lcm(long long a, long long b){
        return (a/gcd(a,b))*b;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<long long> st;

        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++){  
            long long curr = nums[i];
            while(!st.empty() && gcd(st.top(), curr) > 1){ 
                curr = lcm(st.top(), curr);
                st.pop();
            }
            st.push(curr);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
