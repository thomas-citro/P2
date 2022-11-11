#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include "prototypes.h"
using namespace std;

void parserError(string message, int line) {
    // Get error line
    ifstream file;
    file.open("testFile.txt");
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


void parser(vector<vector<string>>& tokens) {
    tree = createTree("<program>");
    if (tokens[tokenID][0] == "keywordToken" && tokens[tokenID][1] == "program") {
        tokenID++;
        addSubtree(tree, block(tokens));
    } else {
        addSubtree(vars(tokens));
    }
}


void vars(vector<vector<string>>& tokens) {
    if (!(tokens[tokenID][0] == "keywordToken" && tokens[tokenID][1] == "whole")) {
        parserError("Expected 'program' or 'whole' keyword. Received '" + tokens[tokenID][1] + "'.", stoi(tokens[tokenID][2]));
    }
    tokenID++;
        
    if (!(tokens[tokenID][0] == "identifierToken")) {
        parserError("Expected identifier after 'whole' keyword.", stoi(tokens[tokenID][2]));
    }
    tokenID++;
    
    if (!(tokens[tokenID][0] == "operatorToken" && tokens[tokenID][1] == ":=")) {
        parserError("Expected ':=' for variable initialization.", stoi(tokens[tokenID][2]));
    }
    tokenID++;
    
    if (!(tokens[tokenID][0] == "integerToken")) {
        parserError("Expected integer value for variable initialization.", stoi(tokens[tokenID][2]));
    }
    tokenID++;
    
    if (!(tokens[tokenID][0] == "operatorToken" && tokens[tokenID][1] == ";")) {
        parserError("Expected semicolon after variable initialization.", stoi(tokens[tokenID][2]));
    }
    tokenID++;
    
    if (tokens[tokenID][0] == "keywordToken" && tokens[tokenID][1] == "program") {
        tokenID++;
        block(tokens);
    } else {
        tokenID++;
        vars(tokens);
    }
}


void block(vector<vector<string>>& tokens) {
    
}
