// Student ID: 20558765
// TODO - Replace the number above with your actual Student ID
//
// Looping_Functions.cpp
//
// Created by Anand Venkataraman on 8/9/19.
// Copyright © 2019 Anand Venkataraman. All rights reserved.
//
//
// Looping_Functions.h
//
// This is your header file. No need to make any major changes. You can just feel free
// to copy it verbatim.
#include <iostream>
#include <sstream>
#include <string>
#include "Looping_Functions.h"
using namespace std;
// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.
bool play_game(int n) {
int numb = 0;
string user_input, user_output;
bool guess;
cout << "Welcome to my number guessing game\n\n";
for (int i=1; i <= 6; i++ ) {
    cout << "Enter your guess: "; 
    cin >> numb;
//getline(cin, user_input);
//istringstream(user_input) >>numb;
cout << "\nYou entered: " << numb << endl;
if (n == numb){
    cout << "You found it in "<< i << " " << "guess(es)."  << endl;
    guess = true;
    break;
}
else if (i == 6) {
    cout << "I'm sorry. You didn't find my number."<< endl;
cout << "It was "<< n << endl;
guess = false;
}

}
return guess;
}
// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.
double etox(double x, size_t n) {
double result = 1.0;
double term = 1.0;
if (n == 0)
result = 0;
for (size_t i = 2; i <= n; i++) {
    term *= x / (i-1);
    result += term;
   // cout << term << " " << result << endl;
}
return result;
}
// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
size_t count = 0;
for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == c) {
        count += 1;
    }
}

return count;
}
// Use Euclid's algorithm to calculate the GCD of the given numbers
size_t gcd(size_t a, size_t b) {
size_t x, y, r, gcd1 = 0;

if (a > b) {
    x = a;
    y = b;
}
else {
    x = b;
    y = a;
}
while ((x != 0) && (y != 0)) {
r = x % y;
x = y;
y = r;
}
if (x == 0) gcd1 = y;
if (y == 0) gcd1 = x;
return gcd1;
}
// Return a string of the form n1,n2,n3,... for the given AP.
string get_ap_terms(int a, int d, size_t n) {
string ap = "";
int term = 0;
for (size_t i = 1; i <= n; i++) {
    term = a + (i-1)*d;
    ap += to_string(term);
    if (i != n) {
        ap += ",";
    }
}
return ap;
}
string get_gp_terms(double a, double r, size_t n) {
string gp = "";
double term = 0.0, rn = 0.0;
ostringstream tm;
tm.precision(6);
if (n == 0) {
return gp;
}
term = a;
tm << term;
for (size_t i = 2; i <= n; i++) {
    rn = 1;
    for (size_t j = 2; j <= i; j++) {
        rn *= r;
    }
    term = a * rn;
    tm <<"," << term;
    //cout << term << endl;
}
gp = tm.str();
return gp;
}
double get_nth_fibonacci_number(size_t n) {
double fib = 0.0;
double prev1 = 1;
double prev2 = 1;
if ((n == 1) or (n == 2)) {
    fib = 1.0;
}
for (size_t i = 3; i <= n; i++) {
    fib = prev1 + prev2;
    prev2 = prev1;
    prev1 = fib;
}

return fib;
}