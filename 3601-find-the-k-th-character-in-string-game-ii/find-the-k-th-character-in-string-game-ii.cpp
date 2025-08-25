class Solution {
   
     char solve(int i,long long k,vector<int>& operations){
        if(i==0) return 'a';
        long long mid=0;
        if(i>=63){
            mid=k+1;
        }
        else mid=1LL<<(i-1);

        if(k <= mid){
           return solve(i-1,k,operations);
        }
        else {
            char ch = solve(i-1,k-mid,operations);
            if(operations[i-1] == 1){
                if(ch == 'z') return 'a';
                return ch + 1;
            }
            return ch;
        }
     }

public:
    char kthCharacter(long long k, vector<int>& operations) {
        return solve((int)operations.size(),k,operations); 
  
    }
};