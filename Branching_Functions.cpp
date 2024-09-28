//Student ID: 20558765
#include <iostream>
// This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3) {
double m;
m = (n1+n2+n3)/3.0;
return m;
}

// This function returns the maximum of the 5 given numbers
int max_of_5(int n1, int n2, int n3, int n4, int n5) {
int mx = n1;
if (n2 > mx) mx = n2;
if (n3 > mx) mx = n3;
if (n4 > mx) mx = n4;
if (n5 > mx) mx = n5;
return mx;
}
// This function returns the minimum of the 5 given numbers
int min_of_5(int n1, int n2, int n3, int n4, int n5) {
int mn = n1;
if (n2 < mn) mn = n2;
if (n3 < mn) mn = n3;
if (n4 < mn) mn = n4;
if (n5 < mn) mn = n5;
return mn;
}
// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid triangles. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
bool sides_make_triangle(int a, int b, int c) {
if ((a + b >= c) && (b + c >= a) && (c + a >= b))
return true;
else
return false;
}
// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {
if (A + B + C == 180)
return true;
else
return false;
}
// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {
bool leap;
double rem1, rem2, rem3;
rem1 = yyyy / 4.0 - yyyy / 4;
if (rem1 > 0)
leap = false;
else 
leap = true;
rem2 = yyyy / 100.0 - yyyy / 100;
if (rem2 == 0)
leap = false;
rem3 = yyyy / 400.0 - yyyy / 400;
if (rem3 == 0)
leap = true;
return leap;
}
