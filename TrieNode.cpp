#include"TrieClass.h"

struct TrieNode* getNewNode()
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndofWord = false;
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = nullptr;
    }
    return pNode;
}

void insert(TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for(int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!node->children[index])
            node->children[index] = getNewNode();
        node = node->children[index];
    }
    node->isEndofWord = true;
}

bool isEmpty(TrieNode* root)
{
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i])
            return false;
    }
    return true;
}

void autoComplete(TrieNode* currentNode, string currPrefix)
{
    if(currentNode->isEndofWord)
        cout << currPrefix << endl;
    for (int i = 0; i < ALPHABET_SIZE; i++)
		if (currentNode->children[i]) {
			char child = 'a' + i;
			autoComplete(currentNode->children[i], currPrefix + child);
		}
}

int printAutoComplete(TrieNode* root, const std::string& prefix)
{
    	struct TrieNode* node = root;

	for (int i = 0; i < prefix.length(); i++)
	{
		int index = prefix[i] - 'a';
	
		if (!node->children[index]) 
			return -1;
		node = node->children[index];
	}

	if (isEmpty(node)) 
	{
		cout << prefix << endl;
		return 0;
	}
	autoComplete(node, prefix);
	return 1;
}