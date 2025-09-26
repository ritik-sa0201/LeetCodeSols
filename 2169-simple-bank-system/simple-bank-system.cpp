class Bank {
public:
int n=1;
vector<long long>curr;
    Bank(vector<long long>& balance) {
        n =balance.size();
        curr = balance;
    }
    bool transfer(int account1, int account2, long long money) {
        if((1<=account1 && account1<=n)&& (1<=account2 && account2<=n)
        && (money <= curr[account1-1])
        ){
             curr[account1-1] -=money;
             curr[account2-1] +=money;
             return true;
        }  
        else{
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        if(1<=account && account<=n){
             curr[account-1] +=money;
             return true;
        }
        else{
            return false;
        }
    }
    
    bool withdraw(int account, long long money) {
         if(1<=account && account<=n && money <=curr[account-1]){
             curr[account-1] -=money;
             return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */