class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>oddh;
        priority_queue<int>evenh;
         string a = to_string(num);
         for(int i=0;i<a.size();i++){
            int ch = int(a[i]);
            if(ch%2==0){
                evenh.push(ch);
            }
            else{
                oddh.push(ch);
            }
         }

          for(int i=0;i<a.size();i++){
            int ch = int(a[i]);
            if(ch%2==0){
                if(!evenh.empty()){
                    char rep = char(evenh.top());
                    evenh.pop();
                    a[i]=rep;
                }
            }
            else{
                if(!oddh.empty()){
                      char rep = char(oddh.top());
                    oddh.pop();
                    a[i]=rep;
                }
            }
          }
         return stoi(a);
    }
};