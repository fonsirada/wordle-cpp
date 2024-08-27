/**
 * @file wordle.h
 * @author Alfonso Rada
 * @brief Wordle sub-class header file
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Wordle {
public:
    Wordle(string answer, vector<string> words);
    void add_attempt(string word);
    bool valid_word(string userInput);
    void valid_case(string & userInput, char ch, string type);
    void check_attempt(string & userInput); 
    void make_attempt(); 
    void check();
    void print_char(char ch, int index);
    void show_letters();
    void show_grid();
    void intro();
    bool is_active();
    void play();

    string _answer;
    bool _solved;
    vector<string> _attempts;

private:
    vector<string> _words;
    vector<bool> _attempted;
    vector<char> _letters;
    vector<bool> _letters_attempted; 
    vector<bool> _letters_green;
    vector<bool> _letters_yellow;
    vector<vector<char>> _attempts_by_char;
};

ostream & operator<<(ostream & out, const Wordle & wordle);

#endif // WORDLE_H