/*
 * Name: Samuel Pupke
 * Date Submitted: 4 March 2024
 * Lab Section: 002
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

// Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

// Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

// Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    size_t hashValue = hash<string>{}(word) % size; //computes the hash value of the word 
    list<string> &bucket = table[hashValue]; //retrieves the linked list for the given has value

    for (string existingWord : bucket)
    {
        if (existingWord == word)
        {
            // Word already exists, do not insert duplicates
            return;
        }
    }

    // Word does not exist, insert it
    bucket.push_back(word);
    num_elems++;

    // Check if table needs to be expanded
    if (num_elems == size)
    {
        size *= 2; // Double the size of the table
        vector<list<string>> newTable(size);

        // Re-insert all elements into the new table
        for (list<string> &bucket : table)
        {
            for (string &word : bucket)
            {
                size_t newHashValue = hash<string>{}(word) % size;
                list<string> &newBucket = newTable[newHashValue];
                newBucket.push_back(word);
            }
        }

        // Update the table with the new one and deallocate the old table
        table = move(newTable);
    }
}

bool Stringset::find(string word) const
{
    size_t hashValue = hash<string>{}(word) % size;
    const list<string> &bucket = table[hashValue];

    for (const string &existingWord : bucket)
    {
        if (existingWord == word)
        {
            // Word found
            return true;
        }
    }

    // Word not found
    return false;
}

void Stringset::remove(string word)
{
    size_t hashValue = hash<string>{}(word) % size;
    list<string> &bucket = table[hashValue];

    for (auto it = bucket.begin(); it != bucket.end(); it++)
    {
        if (*it == word)
        {
            // Word found, remove it
            bucket.erase(it);
            num_elems--;
            return;
        }
    }
}