class Solution {
    void rev(int i,int j,vector<char>&s){
    if(i>=j)return;
    swap(s[i],s[j]);
    rev(i+1,j-1,s);
    }
public:
    void reverseString(vector<char>& s) {
        rev(0,s.size()-1,s);
    }
};