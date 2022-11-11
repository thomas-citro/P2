#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include "prototypes.h"
using namespace std;
/*
// Create and initialize the tree with just the root node
struct Node* createTree(string token){
	struct Node *temp = new Node();
	temp->token = token;
	temp->first = temp->second = temp->third = temp->fourth = NULL;
	return temp;
}

void addSubtree(struct Node* node, struct Node* subtree){
	if (node->first == NULL) {
        node->first = subtree;
    } else if (node->second == NULL) {
        node->second = subtree;
    } else if (node->third == NULL) {
        node->third = subtree;
    } else if (node->fourth == NULL) {
        node->fourth = subtree;
    }
}

struct Node* insertNode(struct Node* node, struct Token* token) { 
	// If the node is empty, return a new node, end case
    if (node == NULL){
        return createTree(token);
    }
	//copy the token
	struct Token* temp = new Token();
	temp->instance = token->instance;
	temp->line = token->line;
	temp->tkId = token->tkId;
	//if the first is not empty move to second:
	if(node->first == NULL){
		node->first = createTree(temp);
	}
	else if(node->second == NULL){
		node->second = createTree(temp);
	}
	else if(node->third == NULL){
		node->third = createTree(temp);
	}
	else if(node->fourth == NULL){
		node->fourth = createTree(temp);
	}
	else{
		//something weird happend if we got here
		perror("ERROR: Tree.cpp: For some reason all of the child nodes are full");
		exit(1);
	}
	return node; 
} 
//Inorder traversal
void inorderTraversal(struct Node *node, int depth){
	//arg depth is to keep track of depth recusively
	if(node == NULL){
		return;
	}
	if(depth == 0){
		cout << node->token->instance << endl;
	}
	string depthStr = "";
	//get the depth string of spaces
	for(int i = 0; i < depth+1; i++){
		depthStr += "__|";
	}
	
	//print children
	if(node->first != NULL){
		cout << depthStr << node->first->token->instance << endl;
		if(node->second != NULL){
			cout << depthStr << node->second->token->instance << endl;
			if(node->third != NULL){
				cout << depthStr << node->third->token->instance << endl;
			}
		}
	}
        if(node->fourth != NULL){
                cout << depthStr << node->fourth->token->instance << endl;
        }

	inorderTraversal(node->first,depth+1);
	inorderTraversal(node->second,depth+1);
	inorderTraversal(node->third,depth+1);
	inorderTraversal(node->fourth,depth+1);
}

*/
