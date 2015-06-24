#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
//METHOD:1 抄的别人的，不知如何评价
class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!(node -> children[word[i] - 'a']))
                node -> children[word[i] - 'a'] = new TrieNode();
            node = node -> children[word[i] - 'a'];
        }
        node -> isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(word.c_str(), root);
    }
private:
    TrieNode* root;

    // Helper function for search()
    bool searchHelper(const char* word, TrieNode* node) {
        if (!node) return false;
        if (!*word) return node -> isKey;
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') {
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> children[j];
                    if (searchHelper(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        if (!run) return false;
        return run -> isKey;
    }
};
//METHOD: 2
//用一个list存储string，我觉得不如方法3
/*
class WordDictionary {
public:
	typedef struct list{
		string val;
		list* next;
		list(string x):val(x),next(NULL){}
	}list;
	list *head;
    // Adds a word into the data structure.
    void addWord(string word) {
        if(!head||head->val>word){
        	list* temp=head;
        	head=new list(word);
        	head->next=temp;
        	return;
		}
		list *foo,*temp=head;
		for(;temp->next&&temp->next->val<word;temp=temp->next);
		if(!(temp->next))
			temp->next=new list(word);
		else if(temp->next->val>word){
			foo=temp->next;
			temp->next=new list(word);
			temp->next->next=foo;
		}
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int res,i;
        int len=word.length();
        for(list* temp=head;temp;temp=temp->next){
        	//cout<<temp->val<<endl;
        	string foo=temp->val;
        	int foo_len=foo.length();
        	if(len!=foo_len)
        		continue;
			for(i=0;i<len;i++){
				if(word[i]=='.'||word[i]==foo[i]);
				else if(foo[i]>word[i])
					return 0;
				else
					break;
			}
			if(i==len)
				return 1;
		}
		return 0;
    }
    WordDictionary():head(NULL){}
};*/
//METHOD 3:建立一个叔，每个节点包括兄弟节点和孩子节点，兄弟节点是有相同前缀的，儿子节点是以该节点及之前
//节点作为前缀的字符串,按理说应该是时间最快，空间最小的方法吧。
/*
class WordDictionary {
public:
	typedef struct dict{
		char val;
		dict* son;
		dict* bro;
		dict(char x):val(x),son(NULL),bro(NULL){}
	}dict;
	
	dict *head;
    // Adds a word into the data structure.
    WordDictionary():head(NULL){}
    void addWord(string word) {
    	dict *temp=head;
    	int i=0;
    	int len=word.length();
    	
    	if(!len)
    		return;
        while(1){
        	if(!temp||temp->val>word[i]){
        		dict *foo=temp;
        		temp=new dict(word[i]);
        		temp->bro=foo;
        		if(foo==head)
        			head=temp;
        		break;
        	}

        	while(temp->bro&&temp->bro->val<word[i]){
        		temp=temp->bro;
			}
			if(temp->val==word[i]){
				temp=temp->son;
			}
			else{
				dict* bar=temp->bro;
				temp->bro=new dict(word[i]);
				temp=temp->bro;
				temp->bro=bar;
				break;
			}	
		}
		//cout<<i<<endl;
		for(i++;i<len;i++){
			temp->son=new dict(word[i]);
			temp=temp->son;
		}
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        //dict* temp=head;
        int res=0;
        check(word,0,res,head);
        return res;
    }
    void check(string &w,int i,int &res,dict* head){
    	int len=w.length();
    	//cout<<i<<endl;
    	if(i==len&&head==NULL){
    		res=1;
    		return;
		}
		if(i==len)
			return;
    	if(!head)
    		return;
    	if(w[i]=='.'){
    		for(dict* temp=head;temp;temp=temp->bro)
    			check(w,i+1,res,temp->son);
		}
		else{
			for(dict* temp=head;temp;temp=temp->bro){
				if(temp->val>w[i])
					return;
				if(temp->val==w[i])
					check(w,i+1,res,temp->son);
			}
		}
    		
	}
};
*/
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main()
{
	WordDictionary A;
	A.addWord("b");
	A.addWord("bad");
	A.addWord("dad");
	A.addWord("mad");
	cout<<A.search("pad")<<endl;
	cout<<A.search("bad")<<endl;
	cout<<A.search(".ad")<<endl;
	cout<<A.search("..d")<<endl;
	cout<<A.search("mad")<<endl;
	cout<<A.search("d")<<endl;
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
