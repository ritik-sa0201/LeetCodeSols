class Solution {
public:
    string largestGoodInteger(string num) {
        if(num.size()<=2)return "";
        string res="";
        int i=0,j=1,k=2;
        while(k<num.size()){
            if(num[i]==num[j] && num[j]==num[k]){
                string ans = "";
                ans+=num[i];
                ans+=num[j];
                ans+=num[k];
                res = max(res,ans);
            }
            i++;
            j++;
            k++;
        }
        return res;
    }
};