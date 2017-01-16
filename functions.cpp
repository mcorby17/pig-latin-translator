#include "functions.h"

bool isVowel(char letter) {
	letter = tolower(letter);

	if (isdigit(letter)) {	//If the letter is a number, treat it as a vowel
		return true;
	}

	switch (letter) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

bool isCons(char letter) {
	return !isVowel(letter) ? true : false;
}

bool isPEQ(char letter) {
	switch (letter) {
	case '.':
	case '!':
	case '?':
	case ',':
	case '/':
		return true;
	default:
		return false;
	}
}

string getWord(string whole, int &i, char &punc) {
	string word;
	punc = ' ';
	while (whole[i] != ' ' && whole[i] != '\0' && !isPEQ(whole[i])) {
		word += whole[i];
		i++;
	}
	if (isPEQ(whole[i])) { //If a word ends with punctuation, save whatever puctuation it is so it can be appended post-pigLatinify
		if (whole[i] == '.')
			punc = '.';
		else if (whole[i] == '!')
			punc = '!';
		else if (whole[i] == '?')
			punc = '?';
		else if (whole[i] == ',')
			punc = ',';
		else if (whole[i] == '/')
			punc = '/';
	}
	i++;
	return word;
}

void appWay(string &word) {
	word += "way";
}

void appAy(string &word) {
	word += "ay";
}

void rotate(string &word) {
	int len = word.length();		//Get word length 
	char firstLetter = word[0];		//Save first letter of word
	string firstLetterRemoved = word.substr(1, len - 1);  //Remove first letter from word
	firstLetterRemoved += firstLetter; //Append first letter to end word, which no longer has it's first letter
	word = firstLetterRemoved;		//Store result in original variable
}

void goThroughEnglish(string english, string &pLatin, int &i) {
	string word;
	char punc = ' ';	//Used to keep track of puctuation such as periods, question marks, etc
	while (i < english.length()) {
		word = getWord(english, i, punc);	//punc is passed by reference so it doesn't need to be returned by getWord
		pigLatinify(word);
		if (punc != ' ') {
			word += punc;
			if(punc != '/')
				i++;
		}
		pLatin += word;
		if(i != english.length() - 1 && punc != '/')
			pLatin += " ";
	}
}

void pigLatinify(string &word) {
	int rotations = 0;
	bool done = false;
	word += '-';
	while (rotations < word.length()) {
		if (isVowel(word[0]) && rotations == 0) { //If the first letter of a word is a vowel
			appWay(word);				  //Append "way" to the end and break the loop
			break;
		}
		else {
			while (!isVowel(word[0])) {	//As long as the first letter is not a vowel
				if (rotations != 0 && word[0] == 'y') {	//And any inner letter is not a 'y'
					appAy(word);
					done = true;
					break;
				}
				else {
					rotate(word);	//Keep rotating through the word until a vowel is found
					rotations++;
				}
					
			}
			if (!done) {	//If a vowel is found and "ay" wasn't previously appended due to a found 'y'
				appAy(word);
				done = true;
			}
		}
		if (done)
			break;
	}
}