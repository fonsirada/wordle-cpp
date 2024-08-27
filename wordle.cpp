/**
 * @file wordle.cpp
 * @author Alfonso Rada
 * @brief Wordle subclass method definitions file
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "wordle.h" 

/**
 * @brief Construct a new Wordle game
 * 
 * @param answer - the answer to the Wordle
 */
Wordle::Wordle(string answer, vector<string> words) {
    _answer = answer;
    _words = words;
    _solved = false;
    for (int i = 0; i < 6; i++) {
        _attempted.push_back(false);
    }
    for (int i = 0; i < 25; i++) {
        _letters.push_back(i + 97);
        _letters_attempted.push_back(false);
        _letters_green.push_back(false);
        _letters_yellow.push_back(false);
    }
}

/**
 * @brief Checks if recent attempt is the answer
 * 
 */
void Wordle::check() {
    string word = _attempts[_attempts.size() - 1];
    if (word == _answer) {
        _solved = true;
        return;
    }
}

/**
 * @brief Prints out individual characters, 
 * depending on if it is in the Wordle answer
 * 
 * @param ch - the character
 * @param index - the index of the character in the word attempt
 */
void Wordle::print_char(char ch, int index) {
    //checks if character is in answer 
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_YELLOW);
    //same index, mark it as green
    if (ch == _answer[index]) {
        attron(COLOR_PAIR(2));
        printw("%c", ch);
        _letters_green[ch - 97] = true;
        attroff(COLOR_PAIR(2));
    }
    //Different index, mark as yellow
    else if (_answer.find(ch) != string::npos) {
        attron(COLOR_PAIR(3));
        printw("%c", ch);
        _letters_yellow[ch - 97] = true;
        attroff(COLOR_PAIR(3));
    }
    //if character not in the answer, dont give it a highlight
    else {
        attron(COLOR_PAIR(1));
        printw("%c", ch);
        attroff(COLOR_PAIR(1));
    }
    _letters_attempted[ch - 97] = true;
}

/**
 * @brief Shows the letters that the user has attempted
 * and whether or not they are in the answer
 * 
 */
void Wordle::show_letters() {
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_YELLOW);
    for (int i = 0; i < _letters.size(); i++) {
        if (_letters_attempted[i] == true) {
            if (_letters_green[i] == true) {
                attron(COLOR_PAIR(2));
                printw("%c", _letters[i]);
                attroff(COLOR_PAIR(2));
            }
            else if (_letters_yellow[i] == true) {
                attron(COLOR_PAIR(3));
                printw("%c", _letters[i]);
                attroff(COLOR_PAIR(3));
            }
            else {
                attron(COLOR_PAIR(1));
                printw("%c", _letters[i]);
                attroff(COLOR_PAIR(1));
            }
        }
        else {
            attron(COLOR_PAIR(1));
            printw("%c", ' ');
            attroff(COLOR_PAIR(1));
        }
    }
}

/**
 * @brief Function that prints out the Wordle grid
 * 
 */
void Wordle::show_grid() {
    show_letters();
    addstr("\n\n");
    for (int i = 0; i < _attempted.size(); i++) {
        //prints out user attempts in wordle grid
        if (_attempted[i] == true) {
            for (int j = 0; j < 5; j++) {
                //checks and prints characters of each attempt
                int ch = _attempts_by_char[i][j];
                print_char(ch, j);
            }
        }
        //prints attempts left as empty strings in wordle grid
        else {
            for (int k = 0; k < 5; k++) {
                init_pair(4, COLOR_WHITE, COLOR_WHITE);
                attron(COLOR_PAIR(4));
                printw("%c", ' '); 
                attroff(COLOR_PAIR(4));
            }
        }
        addstr("\n");
    }
    addstr("\n");
}

/**
 * @brief Start of wordle program, sets up the interface in the terminal
 * source for learning how to use ncurses: https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
 */
void Wordle::intro() {
    initscr();
    cbreak();
    noecho();
    mousemask(0, nullptr);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    addstr("Welcome to Wordle! You have 6 attempts to guess a 5 letter word. ");
    addstr("You can only guess real five letter words. \n");
    addstr("If a letter is green, it is in the answer and in the same index. ");
    addstr("If a letter is yellow, it is in the answer, but in a different index.\n");
    addstr("If a letter is not highlighted, it is not in the answer.");
    attroff(COLOR_PAIR(1));
}

/**
 * @brief Method that checks if the game is still active
 * (if the user has guessed the word or if the user has reached 6 attempts)
 * 
 * @return true - active
 * @return false - not active
 */
bool Wordle::is_active() {
    if (_solved) {
        return false;
    }
    if (_attempts.size() >= 6) {
        return false;
    }
    return true;
}

/**
 * @brief Method that carries out the playing of the game
 * stops running when game is no longer active.
 * 
 */
void Wordle::play() {
    intro();
    while (is_active()) {
        show_grid();
        make_attempt();
        check();
        show_grid();
        clear();
    }
    if (_solved) {
        show_grid();
        printw("Correct! Nice job!\n");
    }
    else {
        show_grid();
        printw("Game over! The word was: ");
        printw("%s\n", _answer.c_str());
    }
    printw("Press any key to exit the game.");
    refresh();
    getch();
    endwin();
}

/**
 * @brief Operator that prints out in the terminal, after the game runs,
 * tells the user if they got the Wordle and in how many attempts.
 * Also tells the user what the answer was.
 * 
 * @param out - output
 * @param wordle - wordle game
 * @return ostream& - output
 */
ostream & operator<<(ostream & out, const Wordle & wordle) {
    out << "The answer to the Wordle was: " << wordle._answer << "." << endl;
    if (wordle._solved) {
        out << "You got the answer in " << wordle._attempts.size() << " attempts.";
    }
    else {
        out << "You did not get the answer.";
    }
    return out;
}

///////// added from wordgame /////////

/**
 * @brief Adds user attempt to vector of attempts
 * 
 * @param word - user attempt
 */
void Wordle::add_attempt(string word) {
    _attempts.push_back(word);
    int size = _attempts.size();
    _attempted[size - 1] = true;
    vector<char> letters;
    for (int i = 0; i < 5; i++) {
        letters.push_back(word[i]);
    }
    _attempts_by_char.push_back(letters);
}

/**
 * @brief Checks if the user attempt is an actual word.
 * (in vector containing all the possible answers)
 * 
 * @param userInput - user attempt
 * @return true - attempt is an actual word
 * @return false - attempt is gibberish
 */
bool Wordle::valid_word(string userInput) {
    for (int i = 0; i < _words.size(); i++) {
        if (_words[i] == userInput) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Method that reads the valid character types that the user is 
 * inputting, and adjusts their attempt on the interface accordingly.
 * 
 * @param userInput - user attempt
 * @param ch - character they are trying to input
 * @param type - the character type that they are inputting
 */
void Wordle::valid_case(string & userInput, char ch, string type) {
    if (type == "backspace") {
        if (!userInput.empty()) {
            userInput.pop_back();
            printw("\b \b");
            refresh();
        }
    }
    else if (type == "uppercase") {
        if (userInput.length() < 5) {
            printw("%c", tolower(ch));
            refresh();
            userInput += tolower(ch);
        }
    }
    else if (type == "normal") {
        if (userInput.length() < 5) {
            printw("%c", ch);
            refresh();
            userInput += ch;
        }
    }
}

/**
 * @brief Method that helps read the user input for an attempt
 * Checks for the attempt to be 5 letters and the user has to enter it.
 * The attempt also has to be an actual word, not gibberish.
 * Also accounts for backspace keys, uppercase letters, and other invalid characters.
 * 
 * @param userInput - user input passed by reference to adjust accordingly
 */
void Wordle::check_attempt(string & userInput) {
    int ch = getch();
    if (userInput.length() == 5 && ch == '\n' && valid_word(userInput)) {
        return;
    }
    if (ch == 127) {
        valid_case(userInput, ch, "backspace");
    }
    else if (ch >= 65 && ch <= 90) {
        valid_case(userInput, ch, "uppercase");
    }
    else if (ch >= 97 && ch <= 122) {
        valid_case(userInput, ch, "normal");
    }
    check_attempt(userInput);
}

/**
 * @brief Make attempt method for the user to input an attempt
 * 
 */
void Wordle::make_attempt() {
    addstr("Enter your guess: ");
    string userInput = "";
    //attempt has to be at least 5 letters and user must hit enter to submit
    check_attempt(userInput);
    addstr("\n\n");
    //adds attempt to wordle grid
    add_attempt(userInput);
}