#include<bits/stdc++.h>
using namespace std;

class trieNode{
public:
    bool isTerminal;
    trieNode* child[26];

    trieNode(){
        isTerminal = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

void add(string word, trieNode* trie){
    int n = word.size();
    for(int i=0;i<n;i++){
        if(trie->child[word[i] - 'A'] == NULL){
            trie->child[word[i]-'A'] = new trieNode();
        }
        trie = trie->child[word[i]-'A'];
    }
    trie->isTerminal =true;
}

bool triesearch(string word, trieNode *trie){
    int n = word.size();
    for(int i=0;i<n;i++){
        if(trie->child[word[i]-'A'] == NULL) return false;
        trie = trie->child[word[i]-'A'];
    }
    return trie->isTerminal;
}

int main(){
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");

    trieNode* root = new trieNode();
    for(int i=0;i<dict.size();i++){
        add(dict[i], root);
    }

    cout<<triesearch("ARE",root)<<endl;
    cout<<triesearch("DO",root)<<endl;
    cout<<triesearch("NES",root)<<endl;
    return 0;
}
