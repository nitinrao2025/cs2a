// Student ID: 20558765
// TODO - Replace the number above with your actual student ID
//
#ifndef Stacks_h
#define Stacks_h
#include <vector>
#include <sstream>
class Stack_Int {
private:
std::vector<int> _data;
public:
// No explicit constructor or destructor
size_t size() const {
    return _data.size();
}
bool is_empty() const {
    if (_data.empty())
    return true;
    else
    return false;
}
void push(int val) {
    _data.push_back(val);
}
int top(bool& success) const {
    if (_data.empty()){
    success = false;
    return 0;
    }
    else {
        success = true;
        return _data[_data.size()-1];
    }
}
bool pop() {
    if(_data.empty())
        return false;
    else {
        _data.pop_back();
        return true;
    }
    
}
bool pop(int& val) {
    if(_data.empty())
        return false;
    else {
        val = _data[_data.size()-1];
        _data.pop_back();
        return true;
    }
}
std::string to_string() const {
    std::string s;
    std::stringstream ss;
    ss << _data.size();
    s = "Stack (" + ss.str() + " elements):\n";
    for (size_t i = _data.size()-1; i > _data.size()-11; i--){
        ss.str("");
        ss << _data[i];
        s += ss.str() + "\n";
    }
    s += "...\n";
    s += "Elements, if listed above, are in increasing order of age.";
    return s;
}
// Don't remove the following line
friend class Tests;
};
class Stack_String {
private:
std::vector<std::string> _data;
public:
// No explicit constructor or destructor
size_t size() const {
    return _data.size();
}
bool is_empty() const {
    if (_data.empty())
    return true;
    else
    return false;
}
void push(std::string val) {
    _data.push_back(val);
}
std::string top(bool& success) const {
    if (_data.empty()){
    success = false;
    return 0;
    }
    else {
        success = true;
        return _data[_data.size()-1];
    }
}
bool pop() {
    if(_data.empty())
        return false;
    else {
        _data.pop_back();
        return true;
    }
    
}
bool pop(std::string& val) {
    if(_data.empty())
        return false;
    else {
        val = _data[_data.size()-1];
        _data.pop_back();
        return true;
    }
}
std::string to_string() const {
    std::string s;
    std::stringstream ss;
    ss << _data.size();
    s = "Stack (" + ss.str() + " elements):\n";
    for (size_t i = _data.size()-1; i > _data.size()-11; i--){
        s += _data[i] + "\n";
    }
    s += "...\n";
    s += "Elements, if listed above, are in increasing order of age.";
    return s;
}
// Don't remove the following line
friend class Tests;
};
#endif /* Stacks_h */
