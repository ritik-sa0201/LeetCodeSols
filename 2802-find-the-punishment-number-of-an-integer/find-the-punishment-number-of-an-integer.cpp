class Solution {

  int solve(int n){
    int ans=0;
    while(n>0){
        ans++;
        n=  n/10;
    }
    return ans;
  }  
  
  bool isPossible(int i,int n,int len){
     if(n==i)return true;
     while(len>0){
       int q=n/len;
       int rem = n%len;
       if(isPossible(i-q,rem,len/10)){
        return true;
       }
         len = len/10;
     }
     return false;
  }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int size = solve(i*i);
            int len = pow(10,size-1);
            if(isPossible(i,i*i,len)){
                ans+=i*i;
            }
        }
        return ans;
    }
};