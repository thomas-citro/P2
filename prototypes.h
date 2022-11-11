#ifndef PROTOTYPES_H
#define PROTOTYPES_H

// Structs
struct Node {
	string token;
	struct Node *first, *second, *third, *fourth;		
};


// Function prototypes for main/scanner
void outputVector(vector<vector<string>>&);
void processLine(string, vector<vector<string>>&, bool&, int&, int);
void processCharacter(string&, string&, int&, vector<vector<string>>&, bool&, int&, int, char, int&);
int getColumn(char);


// Function prototypes for parser
void parser(vector<vector<string>>&);
void vars(vector<vector<string>>&);
void block(vector<vector<string>>&);
void parserError(string, int);


// Function prototypes for tree
struct Node* createTree(string);
struct Node* insertNode(struct Node*, string);
void addSubtree(struct Node*, struct Node*);
void inorderTraversal(struct Node*, int);

#endif
