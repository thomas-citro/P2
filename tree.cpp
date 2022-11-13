#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include "parser.h"
#include "tree.h"

using namespace std;



// Create and initialize the tree with just the root node
node* createTree(string token){
	node *temp = new Node();
	temp->token = token;
	temp->first = temp->second = temp->third = temp->fourth = NULL;
	return temp;
}
/*
void addSubtree(node* myNode, node* subtree){
	if (myNode->first == NULL) {
        	myNode->first = subtree;
	} else if (myNode->second == NULL) {
		myNode->second = subtree;
    	} else if (myNode->third == NULL) {
        	myNode->third = subtree;
	} else if (myNode->fourth == NULL) {
		myNode->fourth = subtree;
    	}
}

struct Node* insertNode(node* myNode, struct Token* token) { 
	// If the node is empty, return a new node, end case
    	if (myNode == NULL){
        	return createTree(token);
    	}
	//copy the token
	struct Token* temp = new Token();
	temp->instance = token->instance;
	temp->line = token->line;
	temp->tkId = token->tkId;
	//if the first is not empty move to second:
	if (myNode->first == NULL){
		myNode->first = createTree(temp);
	} else if (myNode->second == NULL) {
		myNode->second = createTree(temp);
	} else if (myNode->third == NULL) {
		myNode->third = createTree(temp);
	} else if (myNode->fourth == NULL) {
		myNode->fourth = createTree(temp);
	} else {
		//something weird happend if we got here
		perror("ERROR: Tree.cpp: For some reason all of the child nodes are full");
		exit(1);
	}
	return myNode; 
} 

//Inorder traversal
void inorderTraversal(node* myNode, int depth){
	//arg depth is to keep track of depth recusively
	if (myNode == NULL) {
		return;
	}
	if (depth == 0) {
		cout << node->token->instance << endl;
	}
	string depthStr = "";
	//get the depth string of spaces
	for (int i = 0; i < depth+1; i++) {
		depthStr += "__|";
	}
	
	//print children
	if (myNode->first != NULL) {
		cout << depthStr << myNode->first->token->instance << endl;
		if (myNode->second != NULL) {
			cout << depthStr << myNode->second->token->instance << endl;
			if (myNode->third != NULL) {
				cout << depthStr << myNode->third->token->instance << endl;
			}
		}
	}
        if (myNode->fourth != NULL) {
                cout << depthStr << myNode->fourth->token->instance << endl;
        }

	inorderTraversal(myNode->first,depth+1);
	inorderTraversal(myNode->second,depth+1);
	inorderTraversal(myNode->third,depth+1);
	inorderTraversal(myNode->fourth,depth+1);
}
*/
