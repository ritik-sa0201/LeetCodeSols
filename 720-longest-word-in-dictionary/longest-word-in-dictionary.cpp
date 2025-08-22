class Solution {
    struct node{
        bool isEnd;
        node* children[26];
    };
    node* getNode(){
        node* newNode = new node;
        newNode->isEnd = false;
        for(int i=0;i<26;i++){
            newNode->children[i]=nullptr;
        }
        return newNode;
    }

    void insert(node* root,string word){
        node* temp = root;
        for(char ch:word){
            if(temp->children[ch-'a']==nullptr){
                temp->children[ch-'a']=getNode();
            }
            temp=temp->children[ch-'a'];
        }
        temp->isEnd = true;
    }

    bool Search(node* root,string word){
        if(word=="")return true;
         node* temp = root;
        for(char ch:word){
            if(temp->children[ch-'a']==nullptr){
               return false;
            }
            temp=temp->children[ch-'a'];
        }
        return true;
    }


public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string ans="";
        node* root =getNode();
        for(string word : words){
             string curr = word.substr(0,word.size()-1);
             if(Search(root,curr)){
                insert(root,word);
                if(ans.size() < word.size()){
                    ans = word;
                }
             }
        } 
        return ans;
    }
};