class Solution {
public:
   bool solve(int a,int b){
        while(a!=0){
            if(a%10==0)return false;
            a /=10; 
        }
        while(b!=0){
            if(b%10==0)return false;
            b/=10;
        }
        return true;
   }

    vector<int> getNoZeroIntegers(int n) {
        int a1=n;
        int a2=0;
        while(n){
            a1--;
            a2++;
            if(solve(a1,a2))break;
        }
        return {a1,a2};
    }
};