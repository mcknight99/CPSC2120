/*
 * Name: Sam Pupke
 * Date Submitted: 22 April 2024
 * Lab Section: 001
 * Assignment Name: Using Breadth-First Search to Solve Puzzles
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int, int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;       // have we queued up this state for visitation?
map<state, state> pred;         // predecessor state we came from
map<state, int> dist;           // distance (# of hops) from source node
map<state, vector<state>> nbrs; // vector of neighboring states

map<pair<state, state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;

  while (!to_visit.empty())
  {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n])
      {
        pred[n] = curnode;
        dist[n] = 1 + dist[curnode];
        visited[n] = true;
        to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t)
  {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": "
         << "[" << t.first << "," << t.second << "]\n";
  }
  else
  {
    cout << "Initial state: "
         << "[" << s.first << "," << s.second << "]\n";
  }
}


void build_graph()
{
  // Generate all possible states (configurations of water in jugs)
  int AMAX = 3;
  int BMAX = 4;
  for (int a = 0; a <= AMAX; ++a)
  {
    for (int b = 0; b <= BMAX; ++b)
    {
      // Add the current state to the graph
      state current_state = make_pair(a, b);

      // Generate possible transitions from the current state
      for (int action = 0; action < 6; ++action)
      {
        int new_a = a, new_b = b;
        switch (action) //Ignore the ugly switch statement :)
        {
        case 0: // Fill A
          new_a = 3;
          break;
        case 1: // Fill B
          new_b = 4;
          break;
        case 2: // Empty A
          new_a = 0;
          break;
        case 3: // Empty B
          new_b = 0;
          break;
        case 4: // Pour A->B
          if (a + b > 4)
          {
            new_a = a - (4 - b);
            new_b = 4;
          }
          else
          {
            new_b = a + b;
            new_a = 0;
          }
          break;
        case 5: // Pour B->A
          if (a + b > 3)
          {
            new_b = b - (3 - a);
            new_a = 3;
          }
          else
          {
            new_a = a + b;
            new_b = 0;
          }
          break;
        }
        // Check if the transition is valid (not already visited)
        state next_state = make_pair(new_a, new_b);
        if (next_state != current_state && !visited[next_state])
        {
          nbrs[current_state].push_back(next_state);                          // Add the valid transition to neighbors
          edge_label[make_pair(current_state, next_state)] = actions[action]; // Store the action for this transition
        }
      }
    }
  }
}


int main(void)
{
  build_graph();

  state start = make_pair(0, 0);

  for (int i = 0; i < 5; i++)
    nbrs[make_pair(i, 5 - i)].push_back(make_pair(-1, -1));
  search(start);
  if (visited[make_pair(-1, -1)])
    print_path(start, pred[make_pair(-1, -1)]);
  else
    cout << "No path!\n";

  return 0;
}
