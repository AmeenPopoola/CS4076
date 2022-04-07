#include "wordle.h"
#include <iostream>
#include <fstream>

const int wordCount = 2322;
const int totalGuesses = 6;

Wordle::Wordle()
{
play();
cout << word << endl;
}

void Wordle::play(){
    remainingGuesses = ::totalGuesses;
    string word = generateRandomWord();
    words.clear();
}

string Wordle::generateRandomWord(){
    string random;
    srand(time(NULL));
    int wordLine = 1 +(rand() % ::wordCount);
    fstream wordleFile("C:/CS4076/April/wordle.txt");
    int count = 0;
    while(getline(wordleFile,random)){
        count++;
        if(count == wordLine){
            break;
        }
    }
     wordleFile.close();
     return random;
}

bool Wordle::isCorrect(){
    if(words.size()>0){
        for (unsigned int i = 0; i < words.size(); i++) {
                   if (words[i].compare(word) == 0) {
                       return true;
                   }
               }
           }
           return false;
    }

