// Jonathan Stock
// COEN 179
#include <unordered_map>
#include <string>

using namespace std;

// trie implementation used from https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/

class trie
{
public:
    // trie data structure
    // end is a flag if it indicates the last char in the word
    int end, value;
    unordered_map<char, trie *> map;

    static trie *newTrie();
    static void insert(trie *&root, const string &str, const int &rank);
    static int search(trie *root, const string &str);
    static int getValue(trie *root, const string &str);
};