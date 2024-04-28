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
queue<string> q;

// Implement breadth-first search, refer to Lab 10

void buildGraph()
{
  // Build adjacency list
  for (size_t i = 0; i < V.size(); ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      string temp = V[i];
      for (char c = 'a'; c <= 'z'; ++c)
      {
        if (c != temp[j])
        {
          temp[j] = c;
          if (find(V.begin(), V.end(), temp) != V.end())
          {
            adj[V[i]].push_back(temp);
          }
        }
      }
    }
  }
}

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

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  readWordList();
  buildGraph();
  // Perform breadth-first search
  q.push(s);
  visited[s] = true;
  pred[s] = "";

  while (!q.empty())
  {
    string u = q.front();
    q.pop();

    if (u == t)
    {
      // Reconstruct the path
      while (u != "")
      {
        p.push_back(u);
        u = pred[u];
      }
      steps = p.size() - 1;
      reverse(p.begin(), p.end());
      return;
    }

    for (const auto &v : adj[u])
    {
      if (!visited[v])
      {
        visited[v] = true;
        pred[v] = u;
        q.push(v);
      }
    }
  }
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