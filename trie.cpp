// Jonathan Stock
// COEN 179
// trie implementation used from https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/

#include "trie.h"
using namespace std;

trie *newTrie();
void insert(trie *&root, const string &str, const int &rank);
int search(trie *root, const string &str);
int getValue(trie *root, const string &str);

trie *trie::newTrie()
{
    trie *node = new trie;
    node->end = 0;
    node->value = 0;
    return node;
}

void trie::insert(trie *&root, const string &str, const int &rank)
{
    if (root == nullptr)
    {
        root = newTrie();
    }

    trie *curr = root;
    for (int i = 0; i < str.size(); i++)
    {
        // create a new node if the path doesn't exist
        if (curr->map.find(str[i]) == curr->map.end())
        {
            curr->map[str[i]] = newTrie();
        }

        // go to the next node
        curr = curr->map[str[i]];
    }

    // mark the current node as a leaf of the word
    curr->end = 1;
    curr->value = rank;
}

int trie::search(trie *root, const string &str)
{
    if (root == nullptr)
    {
        return 0;
    }

    trie *curr = root;
    for (int i = 0; i < str.size(); i++)
    {
        // go to the next node
        curr = curr->map[str[i]];

        // if the string is invalid (reached end of a path in the Trie)
        if (curr == nullptr)
        {
            return -1;
        }
    }
    // return true if the current node is a leaf and the end of string is reached
    return curr->end;
}

int trie::getValue(trie *root, const string &str)
{
    if (root == nullptr)
    {
        return 0;
    }

    trie *curr = root;
    for (int i = 0; i < str.size(); i++)
    {
        // go to the next node
        curr = curr->map[str[i]];

        // if the string is invalid (reached end of a path in the Trie)
        if (curr == nullptr)
        {
            return 0;
        }
    }
    // return the rank of the word
    if (curr->end)
    {
        return curr->value;
    }
    else
    {
        return 0;
    }
}