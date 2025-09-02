class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;   
        st.insert(1);       
        long long ugly = 1;
        for (int i = 0; i < n; i++) {
            ugly = *st.begin();   
            st.erase(st.begin()); 
            st.insert(ugly * 2);
            st.insert(ugly * 3);
            st.insert(ugly * 5);
        }
        
        return (int)ugly;
    }
};
