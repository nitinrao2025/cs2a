//Student ID: 20558765
//
// Limerick.cpp
// 2a-Lab-01
//
#include <iostream>
#include <sstream> // Need this for istringstream below
#include <cmath> // needed for sqrt
#include <cstdlib> // for exit()
using namespace std;
double eval_limerick(int dozen, int gross, int score) {
 double limerick = 0;
 limerick = (dozen + gross + score + 3 * sqrt (4)) / 7 + 5 * 11;
 return (limerick);
}

int main(int argc, char **argv) {
int dozen=58, gross=58, score=60;

 if (argc < 4) {
 cerr <<"Usage: limerick dozen-val gross-val score-val\n";
 exit(1);
 }
istringstream(argv[1]) >>dozen;
istringstream(argv[2]) >>gross;
istringstream(argv[3]) >>score;
cout << eval_limerick(dozen, gross, score) << endl;
return 0;
}
