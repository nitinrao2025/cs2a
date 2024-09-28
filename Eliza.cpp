// Student ID: 20558765
// TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//
#include <iostream>
#include <sstream>
using namespace std;
// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
// TODO - Your code for rotate_vowels goes here
// Return a string in which all occurrences of s have been replaced by th
// TODO - Your code for lispify goes here
// Enter the user-interaction loop as described earlier
string lispify(string s) {
    string lisp;
    for (unsigned int i = 0; i < s.length(); i++){
        if (s[i] == 's') 
        lisp += "th";
        else if (s[i] == 'S')
        lisp += "Th";
        else 
        lisp += s[i];
        
    }
    return lisp;
}
string rotate_vowels(string& s) {
    for(unsigned int i = 0; i < s.length(); i++) {
        switch(s[i]) {
            case 'a':   s[i] = 'e';
                        break;
            case 'e':   s[i] = 'i';
                        break;
            case 'i':   s[i] = 'o';
                        break;
            case 'o':   s[i] = 'u';
                        break;
            case 'u':   s[i] = 'a';
                        break;
            case 'A':   s[i] = 'E';
                        break;
            case 'E':   s[i] = 'I';
                        break;
            case 'I':   s[i] = 'O';
                        break;
            case 'O':   s[i] = 'U';
                        break;
            case 'U':   s[i] = 'A';
                        break;
        }
    }
    return s;
}
void enter() {
    string user_input;
    int rem = 0;
    cout << "What?" << endl;
    while (true) {
        getline(cin, user_input);
        if (user_input.empty()){
            continue;
        }
        cout << "    " << user_input << "\n\n";
        if (user_input.find("!") != string::npos) {
            cout << "OMG! You don't say!! " << user_input << "!!!!!"<< endl;
            continue; 
        }
        if (user_input.find("why") != string::npos or user_input.find("what") != string::npos) {
            cout << "I'm sorry, I don't like questions that contain what or why."<< endl;
            continue;
        }
        if (user_input.find('s') != string::npos) {
            cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl;
            cout << lispify(user_input) << "! Sheesh! Now what?"<< endl;
            continue;
        }
        if (user_input == "bye" or user_input == "Bye" or user_input == "quit" or user_input == "Quit") {
            cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break;
        }
        rem = rand() % 10;
        if (rem == 8 or rem == 9) {
            cout <<  "Huh? Why do you say: " << user_input << "?" << endl;
        }
            else {
                cout << rotate_vowels(user_input) << "?" << endl;
            }   
    }
}