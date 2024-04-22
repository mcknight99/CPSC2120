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
using namespace std;

// Reflects what each node represents...
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state;

// Bit position representation for wolf/goat/cabbage/me
bool bit(int x, int i) { return (x >> i) & 1; }
const int wolf = 0, goat = 1, cabbage = 2, me = 3;

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;       // have we queued up this state for visitation?
map<state, state> pred;         // predecessor state we came from
map<state, int> dist;           // distance (# of hops) from source node
map<state, vector<state>> nbrs; // vector of neighboring states

map<pair<state, state>, string> edge_label;

// GENERIC (breadth-first search, outward from curnode)
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

string state_string(state s)
{
  string items[4] = {"wolf", "goat", "cabbage", "you"}, result = "";
  for (int i = 0; i < 4; i++)
    if (!bit(s, i))
      result += items[i] + " ";
  result += " |river| ";
  for (int i = 0; i < 4; i++)
    if (bit(s, i))
      result += items[i] + " ";
  return result;
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t)
  {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n";
  }
  else
  {
    cout << "Initial state: " << state_string(s) << "\n";
  }
}

string neighbor_label(int s, int t)
{
  string items[3] = {"wolf", "goat", "cabbage"}, which_cross;
  if (bit(s, me) == bit(t, me))
    return ""; // must cross river
  int cross_with = 0;
  for (int i = 0; i < 3; i++)
  {
    if (bit(s, i) != bit(t, i) && bit(s, i) == bit(s, me))
    {
      cross_with++;
      which_cross = items[i];
    }
    if (bit(s, i) != bit(t, i) && bit(s, i) != bit(s, me))
      return "";
  }
  if (cross_with > 1)
    return "";
  if (cross_with == 0)
    return "Cross alone";
  else
    return "Cross with " + which_cross;
}

void build_graph()
{
  // Iterate through all possible states
  for (state s = 0; s < 16; ++s)
  {
    vector<state> goodStates;

    // Generate possible moves
    for (int i = 0; i < 3; ++i)
    {
      // If the item is on the same side as "me", it can be moved
      if (bit(s, i) == bit(s, me))
      {
        // Create the new state with the item and "me" moved to the opposite side
        state t = s ^ (1 << i); // Move the object to the opposite side
        t = t ^ (1 << me);      // Move "me" to the opposite side
        // If the state is invalid (wolf with goat, goat with cabbage), skip it
        if (!((bit(t, wolf) == bit(t, goat)) && (bit(t, goat) != bit(t, me)) || (bit(t, goat) == bit(t, cabbage)) && (bit(t, goat) != bit(t, me))))
        {
          // If the new state is valid, add it to neighbors
          // nbrs[s].push_back(t);
          // Determine the action label for the transition
          string label = neighbor_label(s, t);
          // Store the action label for the transition
          goodStates.push_back(t);
          edge_label.insert(pair<pair<state, state>, string>(pair<state, state>(s, t), label));
        }
      }
    }
    // Add a step where "me" crosses alone
    // If the state is invalid (wolf with goat, goat with cabbage), skip it
    state t = s ^ (1 << me);
    if (!((bit(t, wolf) == bit(t, goat)) && (bit(t, goat) != bit(t, me)) || (bit(t, goat) == bit(t, cabbage)) && (bit(t, goat) != bit(t, me))))
    {
      goodStates.push_back(t);
      string label = neighbor_label(s, t);
      edge_label.insert(pair<pair<state, state>, string>(pair<state, state>(s, t), label));
    }

    nbrs.insert(pair<state, vector<state>>(s, goodStates));
  }
}


int main(void)
{
  build_graph();

  state start = 0, end = 15;

  search(start);
  if (visited[end])
    print_path(start, end);
  else
    cout << "No path!\n";

  return 0;
}
