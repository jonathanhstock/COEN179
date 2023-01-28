// Jonathan Stock
// COEN 179
#include "triedict.cpp"
#include "quicksort.cpp"
using namespace std;

void parse(trie *root, string input, int start, const string &output);

void parse(trie *root, string input, int start, const string &output)
{
    string temp;
    temp = input[start];

    while (start < input.size())
    {
        int word;
        char end = temp[temp.size() - 1];

        if (end == '.' || end == ',' || end == '!' || end == '?' || end == ';')
        {
            word = trie::search(root, temp.substr(0, temp.size() - 1));
        }
        else
        {
            word = trie::search(root, temp);
        }

        if (word == 1)
        {
            parse(root, input, start + 1, output + temp + " ");
            temp += input[++start];
        }
        else if (word == 0)
        {
            temp += input[++start];
        }
        else
        {
            return;
        }
    }
    if (start >= input.size() && temp.size() == 1)
    {
        ofstream myFile;
        myFile.open("output.txt", ios_base::app);
        if (myFile.is_open())
        {
            myFile << output << endl;
            myFile.close();
        }
        else
        {
            cout << "Error opening output.txt" << endl;
            return;
        }
    }
}

int main()
{
    trie *root = new trie;
    createTrieDict(root);

    ifstream text;
    text.open("input.txt");
    if (text.is_open())
    {
        string input;
        string output;

        getline(text, input);
        parse(root, input, 0, output);
    }
    else
    {
        cout << "Error opening input.txt" << endl;
        return 0;
    }

    fstream final;
    final.open("output.txt");
    string word;
    int lines = 0;

    if (final.is_open())
    {
        while (getline(final, word))
        {
            lines++;
        }
        final.close();
    }
    else
    {
        cout << "Error opening output.txt" << endl;
        return 0;
    }

    final.open("output.txt");
    string arr[lines];
    int i = 0;
    while (getline(final, word))
    {
        arr[i] = word;
        i++;
    }
    final.close();

    int ranks[lines];

    for (int x = 0; x < lines; x++)
    {
        string curr = arr[x];
        string str;
        int rank = 0;

        for (int j = 0; j < sizeof(curr); j++)
        {
            if (curr[j] == ' ' || curr[j] == '.' || curr[j] == ',' || curr[j] == '?' || curr[j] == '!' || curr[j] == ';')
            {
                rank += trie::getValue(root, str);
                str.clear();
            }
            else
            {
                str += curr[j];
            }
        }
        ranks[x] = rank;
    }

    quickSort(ranks, arr, 0, lines - 1);

    final.open("output.txt");

    if (final.is_open())
    {
        for (int k = lines - 1; k >= 0; k--)
        {
            final << "Rank: " << ranks[k] << "\t" << arr[k] << endl;
        }
    }
    else
    {
        cout << "Error opening output.txt" << endl;
        return 0;
    }
}