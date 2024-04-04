/*
 * Name: Sam Pupke
 * Date Submitted: 3 April 2024
 * Lab Section: 002
 * Assignment Name: Storing a Sequence in a Binary Search Tree
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

#include "bstSequence.h"

using namespace std;

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

/*
// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}
*/

// insert value v at rank r
Node *insert(Node *T, int v, int r)
{
    if (T == nullptr) return new Node(v);
    
    int rank_of_root = T->left ? T->left->size : 0;
    if (r <= rank_of_root) {
        T->left = insert(T->left, v, r);
    } else {
        T->right = insert(T->right, v, r - rank_of_root - 1);
    }
    fix_size(T);
    return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder;
  inorder=inorder_traversal(T->left);
  inorder.push_back(T->key);
  rhs=inorder_traversal(T->right);
  inorder.insert(inorder.end(), rhs.begin(), rhs.end());
  return inorder;
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
  assert(T!=nullptr && r>=0 && r<T->size);

  int rank_of_root = T->left ? T->left->size : 0;
  if (r == rank_of_root) return T;
  if (r < rank_of_root) return select(T->left, r);
  else return select(T->right, r - rank_of_root - 1);
}

// Split tree T on rank r into tree L (containing ranks < r) and 
// a tree R (containing ranks >= r)
void split(Node *T, int r, Node **L, Node **R)
{
    if (T == nullptr) {
        *L = nullptr;
        *R = nullptr;
        return;
    }
    
    int rank_of_root = T->left ? T->left->size : 0;
    
    if (r <= rank_of_root) {
        split(T->left, r, L, &(T->left));
        *R = T;
    } else {
        split(T->right, r - rank_of_root - 1, &(T->right), R);
        *L = T;
    }
    
    fix_size(T);
}

// Merge two binary search trees rooted at L and R
// Returns a pointer to the root of the merged tree
Node *merge(Node *L, Node *R)
{
    // Base cases: If one of the trees is empty, return the other tree
    if (L == nullptr)
        return R;
    if (R == nullptr)
        return L;

    // Choose the root of the merged tree based on the sizes of L and R
    if (rand() % (L->size + R->size) < L->size) {
        // If the randomly chosen number is less than the size of L,
        // make L the root and merge its right subtree with R
        L->right = merge(L->right, R);
        fix_size(L); // Update the size of the merged tree
        return L;    // Return the merged tree with L as the root
    } else {
        // Otherwise, make R the root and merge its left subtree with L
        R->left = merge(L, R->left);
        fix_size(R); // Update the size of the merged tree
        return R;    // Return the merged tree with R as the root
    }
}

// insert value v at rank r
Node *insert_random(Node *T, int v, int r)
{
    // Base case: if the tree is empty, create a new node
    if (T == nullptr)
        return new Node(v);

    // Calculate the size of the tree rooted at T
    int treeSize = T->size + 1; // Adding 1 to account for the new node to be inserted

    // Calculate the probability of inserting at the root
    double probability = 1.0 / treeSize;

    // Generate a random number between 0 and 1
    double randNum = (double)rand() / RAND_MAX;

    // If the random number is less than or equal to the probability,
    // insert the new node at the root
    if (randNum <= probability) {
        // Split the tree at rank r to get left and right subtrees
        Node *L = nullptr;
        Node *R = nullptr;
        split(T, r, &L, &R);

        // Create a new node with value v as the root
        Node *newRoot = new Node(v);

        // Merge the left subtree, new root, and right subtree
        return merge(merge(L, newRoot), R);
    }

    // Otherwise, recursively insert the new node either in the left or right subtree
    if (r <= (T->left ? T->left->size : 0))
        T->left = insert_random(T->left, v, r);
    else
        T->right = insert_random(T->right, v, r - (T->left ? T->left->size : 0) - 1);

    // Update the size of the tree rooted at T
    fix_size(T);

    return T;
}

// Returns true if team x defeated team y
// Leave this function unmodified
bool did_x_beat_y(int x, int y)
{
  assert (x != y);
  if (x > y) return !did_x_beat_y(y,x);
  unsigned long long lx = x;
  unsigned long long ly = y;
  return ((17 + 8321813 * lx + 1861 * ly) % 1299827) % 2 != 0;
}


// Return a BST containing a valid ordering of n teams
Node *order_n_teams(int n)
{
  Node *T = nullptr;

  // start by inserting the first team
  T = insert_random(T, 0, 0);
  // now insert the other teams...

  for (int i=1; i<n; i++) {
    // insert team i so the sequence encoded by the BST remains valid
    if (did_x_beat_y(i, select(T,0)->key)) { // can we insert at beginning?
      T = insert_random(T, i, 0);
    } else if (did_x_beat_y(select(T,T->size-1)->key, i)) { // can we insert at end?
	    T = insert_random(T, i, T->size);
    } else {
	    // 7 5 4 2 0 3 1 6    (when inserting team i=8)
	    // W W W L L L W L
      //Binary search to find the position to insert
      int lower = 0;
      int upper = T->size-1;

      while (lower != upper-1) {
        int mid = (lower + upper)/2;
        if (did_x_beat_y(select(T,mid)->key, i)) {
          lower = mid;
        }
        else {
          upper = mid;
        }
      }
      T = insert_random(T, i, upper);
      
    }
  }
  return T;
}



void printVector(vector<int> v)
{
    for (size_t i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

/*
int main(void)
{
  vector<int> inorder;
  Node *T = nullptr;

  // test insert at beginning
  for (int i=0; i<5; i++)
    T = insert(T, i+1, 0);
  cout << "Tree should contain 5 4 3 2 1:\n";
  inorder=inorder_traversal(T);
  printVector(inorder);

  // test insert at end
  for (int i=5; i<10; i++)
    T = insert(T, i+1, T->size);
  cout << "Tree should contain 5 4 3 2 1 6 7 8 9 10:\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
  
  // test insert at middle
  for (int i=10; i<15; i++)
    T = insert(T, i+1, T->size/2);
  cout << "Tree should contain 5 4 3 2 1 12 14 15 13 11 6 7 8 9 10:\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
    
  // once insert is working, the next step is to build the
  // insert_random function -- to test this, just change
  // calls to insert above to insert_random.

  int N = 100000; // this should run quickly even for very large N!
  Node *S = order_n_teams(N);
  if (S == nullptr || S->size != N)
    cout << "Size of tree returned by order_n_teams is wrong\n";
  else {
    cout << "Team ordering:\n";
    //    inorder=inorder_traversal(S);
    //    printVector(inorder);
    for (int i=0; i<N-1; i++) {
      Node *x = select(S, i);
      Node *y = select(S, i+1);
      if (!did_x_beat_y(x->key, y->key)) {
        cout << "Invalid sequence: team " << x->key << " (position " << i <<
	              ") lowerst to team " << y->key << " (position " << i+1 << ")\n";
      }
    }
  }  
  
  return 0;
}
*/