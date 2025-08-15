class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');

        int i=0,j=0;
        int count=0;
        int ans=INT_MIN;
        for(j;j<k;j++){
            if(st.find(s[j])!=st.end()){
                count++;
            }
        }
        ans = max(ans,count);

        while(j<s.size()){
            if(st.find(s[i])!=st.end()){
                count--;
            }
            i++;
            if(st.find(s[j])!=st.end()){
                count++;
            }
            j++;
            ans = max(ans,count);
        }
return ans;
    }
};