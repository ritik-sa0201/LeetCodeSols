class Solution {
public:
    bool doesAliceWin(string s) {
   int ct=0;
   for(char ch:s){
    if(ch=='a'||ch=='o'||ch=='i'||ch=='e'||ch=='u')ct++;
   }
   if(ct!=0)return true;
   return false;
    }
};