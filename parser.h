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
void parserError(std::string, int);
void nextToken();
token* nonterminal(std::string);
token* terminal(std::vector<std::string>);
void parser(std::vector<std::vector<std::string>>&);
node* vars(std::vector<std::vector<std::string>>&);
node* block(std::vector<std::vector<std::string>>&);
node* expr(std::vector<std::vector<std::string>>&);
node* N(std::vector<std::vector<std::string>>&);
node* A(std::vector<std::vector<std::string>>&);
node* A2(std::vector<std::vector<std::string>>&);
node* M(std::vector<std::vector<std::string>>&);
node* R(std::vector<std::vector<std::string>>&);
node* stats(std::vector<std::vector<std::string>>&);
node* mStat(std::vector<std::vector<std::string>>&);
node* stat(std::vector<std::vector<std::string>>&);
node* in(std::vector<std::vector<std::string>>&);
node* out(std::vector<std::vector<std::string>>&);
node* _if(std::vector<std::vector<std::string>>&);
node* loop(std::vector<std::vector<std::string>>&);
node* assign(std::vector<std::vector<std::string>>&);
node* RO(std::vector<std::vector<std::string>>&);
node* label(std::vector<std::vector<std::string>>&);
node* _goto(std::vector<std::vector<std::string>>&);

#endif
