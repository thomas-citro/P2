#ifndef PARSER_H
#define PARSER_H

// Structs
typedef struct Token {
	std::string instance;
	std::string tokenType;
	int lineNum;
	int characterNum;
}token;
typedef struct Node {
	struct Token *tk;
	struct Node *first, *second, *third, *fourth;		
}node;


// Function prototypes for main/scanner
void outputVector(std::vector<std::vector<std::string>>&);
void processLine(std::string, std::vector<std::vector<std::string>>&, bool&, int&, int);
void processCharacter(std::string&, std::string&, int&, std::vector<std::vector<std::string>>&, bool&, int&, int, char, unsigned int&);
int getColumn(char);


// Function prototypes for parser
void parser(std::vector<std::vector<std::string>>&);
node* vars(std::vector<std::vector<std::string>>&);
node* block(std::vector<std::vector<std::string>>&);
void parserError(std::string, int);
token* nonterminal(std::string);
token* terminal(std::vector<std::string>);

#endif
