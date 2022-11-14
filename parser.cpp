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
	tk->tokenType = "nonterminalToken";
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
	string nonterminalStr = "<program>";
	tree = createTree(nonterminal(nonterminalStr));
	if (tokens[tokenID][0] == "keywordToken" && tokens[tokenID][1] == "program") {
		tokenID++;
	} else {
		addSubtree(tree, vars(tokens));
	}
	addSubtree(tree, block(tokens));
	preorderTraversal(tree, 0);
}

// BNF: <vars> -> empty | whole Identifier := Integer ; <vars>
node* vars(vector<vector<string>>& tokens) {
	string nonterminalStr = "<vars>";
	node* tree = createTree(nonterminal(nonterminalStr));
	if (!(tokens[tokenID][0] == "keywordToken" && tokens[tokenID][1] == "whole")) {
		parserError("Expected 'program' or 'whole' keyword. Received '" + tokens[tokenID][1] + "'.", stoi(tokens[tokenID][2]));
	}
	tokenID++;
		
	if (!(tokens[tokenID][0] == "identifierToken")) {
		parserError("Expected identifier after 'whole' keyword.", stoi(tokens[tokenID][2]));
	}
	tree = insertNode(tree, terminal(tokens[tokenID]));
	tokenID++;
	
	if (!(tokens[tokenID][0] == "operatorToken" && tokens[tokenID][1] == ":=")) {
		parserError("Expected ':=' for variable initialization.", stoi(tokens[tokenID][2]));
	}
	tokenID++;
	
	if (!(tokens[tokenID][0] == "integerToken")) {
		parserError("Expected integer value for variable initialization.", stoi(tokens[tokenID][2]));
	}
	tree = insertNode(tree, terminal(tokens[tokenID]));
	tokenID++;
	
	if (!(tokens[tokenID][0] == "operatorToken" && tokens[tokenID][1] == ";")) {
		parserError("Expected semicolon after variable initialization.", stoi(tokens[tokenID][2]));
	}
	tokenID++;
	
	if (!(tokens[tokenID][0] == "keywordToken" && tokens[tokenID][1] == "program")) {
		tokenID++;
		addSubtree(tree, vars(tokens));
	}
	return tree;
}


node* block(vector<vector<string>>& tokens) {
	string nonterminalStr = "<block>";
	node* tree = createTree(nonterminal(nonterminalStr));
	return tree;
}
