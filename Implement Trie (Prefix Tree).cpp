#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
/* 
class TrieNode {
public:
	char val;
    vector<TrieNode*> *next;	
    // Initialize your data structure here.
    TrieNode(char x):val(x) {
    	next=new vector<TrieNode*>;
    }
    TrieNode():val('a'),next(NULL){
    //	TrieNode('a');
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        insert_str(s,root);
    }
    void insert_str(string s,TrieNode *h){
    	int size;
    	if(h->next==NULL){
    		vector<TrieNode*> *cur=new vector<TrieNode*>;
    		h->next=cur;
    		size=0;
		}
		else
			size=h->next->size();
    	int i;
    	int length=s.length();
		for(i=0;i<size;i++){
			if((*(h->next))[i]->val==s[0]){	
				if(length>1){
					insert_str(s.substr(1,length-1),(*(h->next))[i]);
				}
				else
					return ;
			}
		}
		if(i==size){
			for(i=0;i<length;i++){
				//cout<<s[i]<<endl;
				//char x=s[i];
				TrieNode *cur=new TrieNode(s[i]);
				cur->next=new vector<TrieNode*>;
				h->next->push_back(cur);
				h=(*(h->next))[0];
			}
		}
	}

    // Returns if the word is in the trie.
    bool search(string key) {
        int i,j,length=key.length();
        int size;
        TrieNode *h=root;
		for(i=0;i<length;i++){
			if(h->next==NULL)
				return 0;
			size=h->next->size();
			for(j=0;j<size;j++){
				if((*(h->next))[j]->val==key[i]){
					h=(*(h->next))[j];
					break;
				}
			}
			if(j==size)
				return 0;
		}
		if(h->next->empty())
			return 1;
		else
			return 0;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i,j,length=prefix.length();
        int size;
        TrieNode *h=root;
		for(i=0;i<length;i++){
			if(h->next==NULL)
				return 0;
			size=(h->next)->size();
			for(j=0;j<size;j++){
				if((*(h->next))[j]->val==prefix[i]){
					h=(*(h->next))[j];
					break;
				}
			}
			if(j==size)
				return 0;
		}
		return 1;
    }
    void print(){
    	insert("a");
    //	insert("a");
    	cout<<search("a")<<endl;
    //	cout<<search("a")<<endl;
    	cout<<startsWith("a")<<endl;
    //	cout<<startsWith("abc")<<endl;
	}

private:
    TrieNode* root;
};
*/
class TrieNode {
public:
	char val;
	int isend;
    vector<TrieNode*> next;	
    // Initialize your data structure here.
    TrieNode(char x):val(x),isend(0){
    	//vector<TrieNode*> cur;
    	//next=cur;
    }
    TrieNode():val(' '),isend(0){
    //	TrieNode(' ');
    }
    ~TrieNode(){
	}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
	~Trie(){
		delete(root);
	}
    void insert(string s) {
    	int size,i,j;
    	int length=s.length();
    	TrieNode *h=root;
    	
		for(j=0;j<length;j++){
			size=h->next.size();	
			for(i=0;i<size;i++){
				if(h->next[i]->val==s[j]){
					h=h->next[i];
					break;
				}
			}
			if(i==size){
				TrieNode *cur=new TrieNode(s[j]);
				h->next.push_back(cur);
				h=h->next[size];
			}
		}
		h->isend=1;
    }

    bool search(string key) {
        int i,j,length=key.length();
        int size;
        TrieNode *h=root;
		for(i=0;i<length;i++){
			size=h->next.size();
			for(j=0;j<size;j++){
				if(h->next[j]->val==key[i]){
					h=h->next[j];
					break;
				}
			}
			if(j==size)
				return 0;
		}
		return h->isend;
    }

    bool startsWith(string prefix) {
        int i,j,length=prefix.length();
        int size;
        TrieNode *h=root;
		for(i=0;i<length;i++){
			size=h->next.size();
			for(j=0;j<size;j++){
				if(h->next[j]->val==prefix[i]){
					h=h->next[j];
					break;
				}
			}
			if(j==size)
				return 0;
		}
		return 1;
    }
    void print(){
    	insert("abc");
    	insert("ab");
    	cout<<search("ab")<<endl;
    	cout<<search("abc")<<endl;
    	cout<<startsWith("a")<<endl;
    	cout<<startsWith("abc")<<endl;
	}

private:
    TrieNode* root;
};
int main()
{
	Trie test;

//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
