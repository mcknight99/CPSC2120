#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include "binarySearchTree.h"

using namespace std;

// Print keys in preorder: Node, Left, Right
void printPreorder(Node* T)
{
    if (T == nullptr) return;

    cout << T->key << " ";      // Visit node first
    printPreorder(T->left);     // Then recurse left
    printPreorder(T->right);    // Then recurse right
}

// Print keys in inorder: Left, Node, Right
void printInorder(Node* T)
{
    if (T == nullptr) return;

    printInorder(T->left);      // Visit left subtree
    cout << T->key << " ";      // Visit node
    printInorder(T->right);     // Visit right subtree
}

// Print keys in postorder: Left, Right, Node
void printPostorder(Node* T)
{
    if (T == nullptr) return;

    printPostorder(T->left);    // Visit left subtree
    printPostorder(T->right);   // Visit right subtree
    cout << T->key << " ";      // Visit node last
}

// Returns the height of the tree (max depth)
int treeHeight(Node* T)
{
    if (T == nullptr) return 0;
    return 1 + max(treeHeight(T->left), treeHeight(T->right));
}

// print preorder, inorder, postorder, height, and size of tree T
void printTreeInfo(Node* T)
{
    cout << "--------------------------------\n";
    cout << "Printing tree info:\n";
    cout << "Preorder: ";
    printPreorder(T);
    cout << "\nInorder: ";
    printInorder(T);
    cout << "\nPostorder: ";
    printPostorder(T);
    cout << "\nTree height: " << treeHeight(T) << endl;
    cout << "Tree size: " << (T ? T->size : 0) << endl << endl;
}

// Visualize the structure of the tree in the terminal
void printTree(Node* T)
{
    printTreeInfo(T);

    if (T == nullptr)
    {
        cout << "(empty tree)\n";
        return;
    }

    // Determine max depth for spacing calculations
    int height = treeHeight(T);

    // Find longest value length to align node output
    int longestValue = 0;
    {
        queue<Node*> q;
        q.push(T);
        while (!q.empty())
        {
            Node* n = q.front();
            q.pop();
            if (n)
            {
                int len = to_string(n->key).length();
                if (len > longestValue) longestValue = len;

                q.push(n->left);
                q.push(n->right);
            }
        }
    }

    // Level-order traversal to print each row with spacing
    queue<Node*> q;
    q.push(T);

    int level = 0;
    while (!q.empty())
    {
        int levelSize = q.size();

        // Compute spacing (matches example logic)
        int spacesBetween = (pow(2, height - level) - 1) * longestValue;
        int leadingSpaces = spacesBetween / 2;

        // Leading indent
        string line(leadingSpaces, ' ');

        for (int i = 0; i < levelSize; i++)
        {
            Node* node = q.front();
            q.pop();

            if (node)
            {
                // Convert key to string padded to equal width
                string val = to_string(node->key);
                if ((int)val.length() < longestValue)
                    val = string(longestValue - val.length(), '0') + val;

                line += val;

                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                // Print placeholder for missing nodes (preserves spacing)
                line += string(longestValue, ' ');

                q.push(nullptr);
                q.push(nullptr);
            }

            // Spacing between nodes
            if (i < levelSize - 1)
                line += string(spacesBetween, ' ');
        }

        // Trim trailing spaces for cleaner output
        line.erase(line.find_last_not_of(' ') + 1);

        cout << line << endl;

        // Detect if next level is entirely null (stop here)
        bool allNull = true;
        queue<Node*> temp = q;
        while (!temp.empty())
        {
            if (temp.front() != nullptr)
            {
                allNull = false;
                break;
            }
            temp.pop();
        }
        if (allNull) break;

        level++;
    }
}

#endif // HELPER_H