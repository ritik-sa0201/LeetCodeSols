class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n), nextGreater(n), prevSmaller(n), nextSmaller(n);

        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

       
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            long long maxCount = (i - prevGreater[i]) * (nextGreater[i] - i);
            long long minCount = (i - prevSmaller[i]) * (nextSmaller[i] - i);
            total += nums[i] * (maxCount - minCount);
        }

        return total;
    }
};
