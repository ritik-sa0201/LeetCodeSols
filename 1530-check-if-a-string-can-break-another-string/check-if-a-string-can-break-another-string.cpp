class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int i=0;
        if(s2>s1){
        while(i<s1.size()){
            if(s2[i]<s1[i])return false;
            i++;
        }
        return true;
        }
        else{
           while(i<s1.size()){
            if(s2[i]>s1[i])return false;
            i++;
        }
        return true;  
        }
    }
};