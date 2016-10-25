#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int ALPHABET_SIZE = 26;

static inline int charEquiv(char c) { return (c - 'a');}

#define ARRAY_SIZE(array) sizeof(array)/sizeof(array[0])

struct TrieNode
{
    int count;
    TrieNode* children[ALPHABET_SIZE];
    TrieNode()
    {
        count = 0;
        for (int i = 0; i < ALPHABET_SIZE ; ++i)
            children[i] =  NULL;
    }
};

class Trie
{
    private: 
        TrieNode* root;
        int count;
        
        inline bool isLeafNode(TrieNode* node) { return (node != NULL &&  node->count == 0);}
        bool isFreeNode(TrieNode* node);
        bool deleteHelper(TrieNode* node, char* input, int len, int level);
    public:
        Trie();
        ~Trie();
        void insert(char* input);
        bool search(char* input);
        void deleteKey(char* input);
};

Trie::Trie()
{
    root = new TrieNode();
    count = 0;
}

Trie:: ~Trie()
{
    // Delete somehow...
}

void Trie::insert(char* input)
{
    TrieNode* curr = root;
    int level=0;
    count++;
    int childIndex;
    while(level <strlen(input) )
    {
        childIndex = charEquiv(input[level]);
        if (curr->children[childIndex] == NULL)
        {
            curr->children[childIndex] =  new TrieNode();
        }
        curr = curr->children[childIndex];
        level++;
    }
    curr->count = count;
}

bool Trie::search(char* input)
{
    bool result = false;
    
    TrieNode* curr = root;
    int childIndex;
    int level=0;

    while(level <strlen(input))
    {
        childIndex = charEquiv(input[level]);
        if (curr->children[childIndex] == NULL)
        {
            return result;
        }
        curr = curr->children[childIndex];
        level++;
    }
    if (curr && curr->count != 0)
        result = true;
    
    return result;
}

void Trie::deleteKey(char *input)
{
    int len = strlen(input);
    if (len)
        deleteHelper(root, input, len, 0);
}

bool Trie::deleteHelper(TrieNode* node, char* input, int len, int level)
{
    if (len == level)
    {
        if (node->count)
            node->count = 0;
        return isFreeNode(node))
    }
    else
    {
        int childIndex = charEquiv(input[level]);
        
        if (deleteHelper(node->children[childIndex], input, len, level + 1))
        {
            delete node->children[childIndex];
            node->children[childIndex] = NULL;
            
            return (!isLeafNode(node) && isFreeNode(node));
        }
    }
}

bool Trie::isFreeNode(TrieNode* node)
{
    for(int i = 0; i < ALPHABET_SIZE ; ++i)
        if (node->children[i] != NULL)
            return false;
    
    return true;
}


// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    Trie trie;
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    // Construct trie
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        trie.insert(keys[i]);
    }
 
    // Search for different keys
    printf("%s --- %s\n", "the", output[trie.search("the")] );
    printf("%s --- %s\n", "these", output[trie.search("these")] );
    printf("%s --- %s\n", "their", output[trie.search("their")] );
    printf("%s --- %s\n", "thaw", output[trie.search("thaw")] );
    printf("%s --- %s\n", "answer", output[trie.search("answer")] );
    
    trie.deleteKey("their");

    printf("%s --- %s\n", "the", output[trie.search("the")] );
    printf("%s --- %s\n", "these", output[trie.search("these")] );
    printf("%s --- %s\n", "their", output[trie.search("their")] );
    printf("%s --- %s\n", "thaw", output[trie.search("thaw")] );
    printf("%s --- %s\n", "answer", output[trie.search("answer")] );
    
    
    return 0;
}