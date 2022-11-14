#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include "parser.h"
#include "tree.h"

using namespace std;


/* Global variables */
int tokenID;
node* tree;


// Create a nonterminal token
token* nonterminal(string myStr) {
	token* tk = new Token();
	tk->instance = myStr;
	tk->tokenType = "nonterminal";
	return tk;
}

// Create a terminal token
token* terminal(vector<string> myVector) {
	token* tk = new Token();
	tk->tokenType = myVector[0];
	tk->instance = myVector[1];
	tk->lineNum = stoi(myVector[2]);
	tk->characterNum = stoi(myVector[3]);
	return tk;
}

// Print a parser error and exit
void parserError(string message, int line) {
	// Get error line
	ifstream file;
	file.open("input.txt");
	if (file.fail()) {
		cout << "File failed to open." << endl;
		exit(0);
	}
	int currentLineNumber = 0;
	string currentLine;
	while (!file.eof()) {
		currentLineNumber++;
		getline(file, currentLine);
		if (currentLineNumber == line) break;
	}
	if (currentLineNumber < line) {
		cout << "Line not found!" << endl;
		exit(0);
	}
	file.close();
	
	// Output error
	cout << "Parser Error: " << message << endl;
	cout << "   ^ On line number " << line << ": " << currentLine;
	exit(0);
}

// BNF: <program> -> <vars> program <block>
void parser(vector<vector<string>>& tokens) {
	tokenID = 0;
	tree = createTree(nonterminal("<program>"));
	if (tokens[tokenID][0] == "program") {
		tokenID++;
	} else {
		addSubtree(tree, vars(tokens));
	}
	addSubtree(tree, block(tokens));
	preorderTraversal(tree, 0);
}

// BNF: <vars> -> empty | whole Identifier := Integer ; <vars>
node* vars(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<vars>"));
	if (!(tokens[tokenID][0] == "whole")) {
		parserError("Expected 'program' or 'whole' keyword. Received '" + tokens[tokenID][1] + "'.", stoi(tokens[tokenID][2]));
	}
	tokenID++;
		
	if (!(tokens[tokenID][0] == "identifier")) {
		parserError("Expected identifier after 'whole' keyword.", stoi(tokens[tokenID][2]));
	}
	tree = insertNode(tree, terminal(tokens[tokenID]));
	tokenID++;
	
	if (!(tokens[tokenID][0] == "operator" && tokens[tokenID][1] == ":=")) {
		parserError("Expected ':=' for variable initialization.", stoi(tokens[tokenID][2]));
	}
	tokenID++;
	
	if (!(tokens[tokenID][0] == "integer")) {
		parserError("Expected integer value for variable initialization.", stoi(tokens[tokenID][2]));
	}
	tree = insertNode(tree, terminal(tokens[tokenID]));
	tokenID++;
	
	if (!(tokens[tokenID][0] == "operator" && tokens[tokenID][1] == ";")) {
		parserError("Expected semicolon after variable initialization.", stoi(tokens[tokenID][2]));
	}
	tokenID++;
	
	if (!(tokens[tokenID][0] == "program")) {
		tokenID++;
		addSubtree(tree, vars(tokens));
	}
	return tree;
}

// BNF: <block> -> begin <vars> <stats> end
node* block(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<block>"));
	return tree;
}

// BNF: <expr> -> <N> - <expr> | <N>
node* expr(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<expr>"));
	return tree;
}

// BNF: <N> -> <A> + <N> | <A> * <N> | <A>
node* N(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<N>"));
	return tree;
}

// BNF: <A> -> <M> <A2>
node* A(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<A>"));
	return tree;
}

// BNF: <A2> -> / <M> <A2> | empty
node* A2(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<A2>"));
	return tree;
}

// BNF: <M> -> :<M> | <R>
node* M(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<M>"));
	return tree;
}

// BNF: <R> -> ( <expr> ) | Identifier | Integer
node* R(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<R>"));
	return tree;
}

// BNF: <stats> -> <stat> <mStat>
node* stats(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<stats>"));
	return tree;
}

// BNF: <mStat> -> empty | <stat> <mStat>
node* mStat(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<mStat>"));
	return tree;
}

// BNF: <stat> -> <in>; | <out>; | <block> | <if>; | <loop>; | <assign>; | <goto>; | <label>;
node* stat(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<stat>"));
	return tree;
}

// BNF: <in> -> input Identifier
node* in(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<in>"));
	return tree;
}

// BNF: <out> -> output <expr>
node* out(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<out>"));
	return tree;
}

// BNF: <if> -> if [ <expr> <RO> <expr> ] then <stat> | if [ <expr> <RO> <expr> ] then <stat> pick <stat>
node* _if(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<if>"));
	return tree;
}

// BNF: <loop> -> while [ <expr> <RO> <expr> ] <stat>
node* loop(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<loop>"));
	return tree;
}

// BNF: <assign> -> assign Identifier = <expr>
node* assign(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<assign>"));
	return tree;
}

// BNF: <RO> -> > | < | == | [=] | !=
node* RO(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<RO>"));
	return tree;
}

// BNF: <label> -> label Identifier
node* label(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<label>"));
	return tree;
}

// BNF: <goto> -> warp Identifier
node* _goto(vector<vector<string>>& tokens) {
	node* tree = createTree(nonterminal("<goto>"));
	return tree;
}
