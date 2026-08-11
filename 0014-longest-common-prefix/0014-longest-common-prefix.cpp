class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    int childcount;

    TrieNode(char val){
        data = val;
        for(int i=0;i<26;i++){
            children[i] = NULL;
            isterminal = false;
            childcount = 0;
        }
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertutil(TrieNode* root,string word){
        if(word.length() == 0){
            root->isterminal = true;
            return;
        }

        int idx = word[0]-'a';
        TrieNode* child;
        if(root->children[idx] != NULL){
            child = root->children[idx];
        }
        else{
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[idx] = child;
        }

        insertutil(child,word.substr(1));
    }

    void insert(string word){
        insertutil(root,word);
    }
};




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        Trie* t1 = new Trie();

        for(int i=0;i<n;i++){
            t1->insert(strs[i]);
        }

        string first = strs[0];

        TrieNode* curr = t1->root;
        
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            
            if(curr->childcount == 1 && curr->isterminal == false){
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