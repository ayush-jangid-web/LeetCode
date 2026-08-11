class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childcount;

    TrieNode(char val){
        data = val;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
            isTerminal = false;
            childcount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
};

class Solution {
    void CreateTrie(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int idx = word[0]-'a';
        TrieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[idx] = child;
            root->childcount++;
        }

        CreateTrie(child,word.substr(1));
    }
    
    void lcp(string word,string &ans,TrieNode*){
        
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie* t1 = new Trie();

        for(int i=0;i<n;i++){
            CreateTrie(t1->root,strs[i]);
        }

        string ans="";
        string first = strs[0];
        TrieNode* curr = t1->root;
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];

            if(curr->childcount == 1 && curr->isTerminal == false){
                ans.push_back(ch);
                int idx = ch-'a';
                curr = curr->children[idx];
            }
            else{
                break;
            }
        }
        return ans;
    }
};