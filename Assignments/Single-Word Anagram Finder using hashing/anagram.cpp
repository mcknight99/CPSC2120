/*
 * Name: Sam Pupke
 * Date Submitted: 14 March 2024
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);
/*
int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (size_t i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}
*/
vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if (inFile.is_open())
    {
        while (getline(inFile, word))
        {
            if (word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

// helper function to sort a string. sort of hashing, 
// but just because you can't really undo a sort and it could give you several words undone. 
// this is how anagrams can be found easier
string sortedWord(string input)
{
    sort(input.begin(), input.end());
    return input;
}

// Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    unordered_map<string, vector<string>> map;
    vector<string> result;

    // Sort the input word for direct comparison with keys in the map
    string sortedInput = sortedWord(word);

    // Populate the map: Key is sorted word, value is a vector of anagrams
    for (size_t i = 0; i < wordlist.size(); i++)
    {
        string currentWord = wordlist[i];
        string sortedCurrentWord = sortedWord(currentWord);

        map[sortedCurrentWord].push_back(currentWord);
    }

    // If the sorted input word is found in the map, retrieve the anagrams
    if (map.find(sortedInput) != map.end())
    {
        result = map[sortedInput];
    }

    return result;
}