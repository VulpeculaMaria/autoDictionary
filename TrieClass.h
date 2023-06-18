#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define ALPHABET_SIZE 26

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndofWord;
};

struct TrieNode* getNewNode();
void insert(TrieNode* root, string key);
bool isEmpty(TrieNode* root);
void autoComplete(TrieNode* currentNode, string currPrefix);
int printAutoComplete(TrieNode* root, const string& prefix);