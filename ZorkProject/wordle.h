#ifndef WORDLE_H
#define WORDLE_H

#include <string>
#include <vector>
using namespace std;

class Wordle
{
private:
    int remainingGuesses;
public:
    Wordle();
    string word;
    void play();
    vector<string>words;
    string generateRandomWord();
    bool isCorrect();
};

#endif // WORDLE_H
