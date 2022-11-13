#ifndef PARSER_H
#define PARSER_H

// Structs
typedef struct Node {
	std::string token;
	struct Node *first, *second, *third, *fourth;		
}node;
typedef struct Token {
	std::string token;
	std::string tokenType;
	std::int lineNum;
	std::int characterNum;
}token;


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

#endif
