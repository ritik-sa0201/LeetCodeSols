class Solution {
    bool isValid(string s,int i,int j){
         if(j-i+1 ==1)return true;
         if(j-i+1 ==2){
            if(s[i]=='0')return false;
            else return true;
         }
         if(j-i+1 == 3){
            int x = stoi(s.substr(i,j-i+1));
            if(x>=100 && x<=255)return true;
            else return false;
         }
         else return false;
    }

    void ip(string &s,int i,string curr,vector<string>&ans,int count){
         if(count==3){
            if(isValid(s,i,s.size()-1)){
                curr += s.substr(i);
                ans.push_back(curr);
                return;
            }
            return;
         }
    
           for(int j=i;j<i+3 && j<s.size();j++){
            if(isValid(s,i,j)){
            string part = s.substr(i,j-i+1);
            part +='.';
            curr+=part;
            ip(s,j+1,curr,ans,count+1);
            int x=part.size();
            while(x!=0){
                curr.pop_back();
                x--;
            }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
     vector<string>ans;
       if(s.size()>12 || s.size()<4)return ans;
        ip(s,0,"",ans,0);
        return ans;
    }
};