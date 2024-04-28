#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm> //reverse()
using namespace std;

vector<string> V;                          // words from wordlist05.txt
unordered_map<string, vector<string>> adj; // Adjacency list for the graph

// Global variables for bfs distance, bfs predecessor, and neighboring nodes
// Should be unordered_map type

unordered_map<string, bool> visited;
unordered_map<string, string> pred;
unordered_map<string, int> dist;
unordered_map<string, vector<string>> nbrs;
queue<string> q;

void readWordList()
{
  ifstream file("wordlist05.txt");
  if (!file.is_open())
  {
    cout << "Failed to open file!" << endl;
    return;
  }
  string word;
  while (file >> word)
  {
    V.push_back(word);
  }
  file.close();
}

void build_graph(void)
{
  for (string word : V)
  {
    for (size_t j = 0; j < word.length(); ++j)
    {
      for (char letter = 'a'; letter <= 'z'; letter++)
      {
        if (letter != word[j])
        {
          string newWord = word;
          newWord[j] = letter;
          nbrs[word].push_back(newWord);
        }
      }
    }
  }
}

int path_finder(string start, string end, vector<string> &path)
{
  // avoid segfault when no path exists
  if (pred.find(end) == pred.end())
    return 0;
  if (start.compare(end) != 0)
  {
    int step = 1 + path_finder(start, pred[end], path);
    path.push_back(end);
    return step;
  }
  else
  {
    path.push_back(end);
    return 0;
  }
}

// Implement breadth-first search, refer to Lab 10

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  readWordList();
  build_graph();
  // Implement this function
  queue<string> to_visit;
  to_visit.push(s);
  visited[s] = true;
  dist[s] = 0;

  while (!to_visit.empty())
  {
    string curnode = to_visit.front();
    to_visit.pop();
    for (string n : nbrs[curnode])
      if (!visited[n])
      {
        pred[n] = curnode;
        dist[n] = 1 + dist[curnode];
        visited[n] = true;
        to_visit.push(n);
      }
  }

  steps = path_finder(s, t, p);
}

/*
int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;

  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
    cout << "No path!\n";
  }
  else
  {
    cout << "Steps: " << steps << "\n\n";
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i] << endl;
    }
  }
  return 0;
}
*/