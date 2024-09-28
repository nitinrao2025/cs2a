// Pet.cpp
// 2a-Lab-06-Pets
//
#include <iostream>
#include <sstream>
#include <vector>
#include "Pet.h"
using namespace std;
// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;
Pet::Pet(string name, long id, int num_limbs) {
_name = name;
_id = id;
_num_limbs = num_limbs;
_population++;

}
Pet::~Pet() {
_population--;
}
string Pet::get_name() const { 
    return _name; 
}
long Pet::get_id() const {
    return _id;
}
int Pet::get_num_limbs() const {
    return _num_limbs;
}
bool Pet::set_name(string name) {
    if (name == "")
    return false;
    _name = name;
    return true;
}
bool Pet::set_id(long id) {
    if (id < 0)
    return false;
    _id = id;
    return true;
}
bool Pet::set_num_limbs(int num_limbs) {
    if (num_limbs < 0)
    return false;
    _num_limbs = num_limbs;
    return true;
}
string Pet::to_string() const {
    string s;
    stringstream ss;
    ss << _id;
    stringstream ff;
    ff << _num_limbs;
    s = "(Name: " + _name + ", ID: " + ss.str() + ", Limb Count: "  + ff.str() + ")";
    return s;
}
// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {
long prev_id = 0;
pets.resize(n);
 for (size_t i = 0; i < n; i++) {
    long id = prev_id + 1 + rand() % 10;
    pets[i].set_id(id);
    pets[i].set_num_limbs(rand() % 9); // up to arachnids
    pets[i].set_name(make_a_name(name_len));
    prev_id = id;
  }

}
// ---------------------------------------------------------------------
string Pet::make_a_name(int len) {
    string vowel = "aeiou";
    string consonant = "bcdfghjklmnpqrstvwxyz";
    string name = "";
    string next; 
    int rnum;
    for (int i = 0; i < len; i++){
        if (i == 0) {
            rnum = rand() % 2;
            if (rnum == 0){
            name = name + consonant[rand() % consonant.length()];
            next = "vowel";
            }
            else {
            name = name + vowel[rand() % vowel.length()];
            next = "consonant";
            }
        }
        if (i >= 1) {
            if (next == "consonant") {
            name = name + consonant[rand() % consonant.length()];
            next = "vowel";
            }
            else {
            name = name + vowel[rand() % vowel.length()];
            next = "consonant";
            }
        }
    }
    return name;
}

// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2) {
    return pet1.get_id() == pet2.get_id() && pet2.get_num_limbs() == pet1.get_num_limbs() && pet1.get_name() == pet2.get_name();
}
bool operator!=(const Pet& pet1, const Pet& pet2) {
    if (!operator==(pet1, pet2))
    return true;
    else
    return false;
}
ostream& operator<<(ostream& os, const Pet& pet) {
    os << pet.to_string();
    return os;
}
