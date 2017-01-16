#pragma once

#include <iostream>
#include <string>
using namespace std;

// Boolean functions
bool isVowel(char letter);	//Checks if a character is a vowel
bool isCons(char letter);	//Checks if a character is a consonant
bool isPEQ(char letter);	//Checks if a character is punctuation (period, exclamation, question mark)

// String manipulators
string getWord(string whole, int &i, char &punc);	//Takes a single word from a string, starting at index i
void rotate(string &word);				//Rotates a string so that the first character becomes the last character in the string
void appWay(string &word);				//Appends the string "-way" to the end of a string
void appAy(string &word);				//Appends the string "-ay" to the end of the string
void goThroughEnglish(string whole, string &pLatin, int &i);	//Takes a string, uses getWord to grab each word in a string individually
void pigLatinify(string &word);