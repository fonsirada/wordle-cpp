#include <iostream>
#include <fstream>
#include <string>
#include "wordle.h"

using namespace std;

int main(int argc, char ** argv) {
    //reads in file from terminal that contains 5 letter words, I found the text file online
    //source: https://github.com/charlesreid1/five-letter-words/blob/master/sgb-words.txt
    ifstream file(argv[1]);
    vector<string> words;
    string word;
    //each line of the file contains a word and it stores all
    // of these words in a vector
    while (getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    
    //rng to randomly choose a word from the vector, for the Wordle
    //source: https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
    srand(time(nullptr));
    int randomIndex = rand() % words.size();
    string randomWord = words[randomIndex];
    Wordle game(randomWord, words);
    game.play();
}