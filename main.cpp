// The purpose of this function is to translate English to Pig Latin.

#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {
	string english, pLatin;
	int i = 0;
	char yn;

	do {

		cout << "Enter a sentence in English: \n";
		getline(cin, english);
		cout << endl;
		
		goThroughEnglish(english, pLatin, i);

		cout << "Pig Latin: \n";
		cout << pLatin << endl;
		cout << endl;
		cout << "Enter another sentence? (y/n): ";
		cin >> yn;

		//english.clear();
		pLatin.clear();
		cin.get();
		i = 0;

	} while (tolower(yn) == 'y');

	

	return 0;
}