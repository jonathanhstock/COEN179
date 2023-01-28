// Jonathan Stock
// COEN 179
#include <iostream>
#include <fstream>
#include "trie.cpp"
using namespace std;

void createTrieDict(trie *root);
void fillTrieDict(trie *root);

void createTrieDict(trie *root)
{
    trie *trieDict = new trie;

    fillTrieDict(trieDict);

    ifstream myFile1;
    myFile1.open("dictionary3.txt");

    string word;
    int lines = 0;
    int ranking;

    if (myFile1.is_open())
    {
        while (getline(myFile1, word))
        {
            if (word[0] == '#')
            {
                continue;
            }
            else if (lines % 2 == 0)
            {
                if (word.length() == 1 && word != "I" && word != "A" && word != "a")
                {
                    lines += 2;
                    continue;
                }
                ranking = trie::getValue(trieDict, word);
                trie::insert(root, word, ranking);
                lines++;
            }
            else
            {
                trie::insert(root, word, ranking);
            }
        }
        myFile1.close();
    }
    else
    {
        cout << "Error opening dictionary3.txt" << endl;
        return;
    }
}

void fillTrieDict(trie *root)
{
    ifstream myFile2;
    myFile2.open("dictionary.txt");

    int rankings = 993;
    string word;

    if (myFile2.is_open())
    {
        while (getline(myFile2, word))
        {
            if (word[0] == '#')
            {
                rankings--;
                continue;
            }
            else
            {
                trie::insert(root, word, rankings);
            }
        }
        myFile2.close();
    }
    else
    {
        cout << "Error opening dictionary.txt" << endl;
    }
}