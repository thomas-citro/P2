#ifndef PROTOTYPES_H
#define PROTOTYPES_H

// Structs
struct Node {
	std::string token;
	struct Node *first, *second, *third, *fourth;		
};


// Function prototypes for main/scanner
void outputVector(std::vector<std::vector<std::string>>&);
void processLine(std::string, std::vector<std::vector<std::string>>&, bool&, int&, int);
void processCharacter(std::string&, std::string&, int&, std::vector<std::vector<std::string>>&, bool&, int&, int, char, unsigned int&);
int getColumn(char);


// Function prototypes for parser
void parser(std::vector<std::vector<std::string>>&);
void vars(std::vector<std::vector<std::string>>&);
void block(std::vector<std::vector<std::string>>&);
void parserError(std::string, int);


// Function prototypes for tree
struct Node* createTree(std::string);
struct Node* insertNode(struct Node*, std::string);
void addSubtree(struct Node*, struct Node*);
void inorderTraversal(struct Node*, int);

#endif
