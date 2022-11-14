#ifndef TREE_H
#define TREE_H

// Function prototypes for tree
struct Node* createTree(std::string);
struct Node* insertNode(struct Node*, std::string);
void addSubtree(struct Node*, struct Node*);
void preorderTraversal(struct Node*, int);

#endif
