// Student ID: 20558765
// TODO - Type in your student ID after the colon above.
// String_List.h
//
#ifndef String_List_h
#define String_List_h
#include <iostream>
#include <sstream>
// Important implementation note: With the exception of to_string(),
// find*() and clear(), all list methods below should operate in a constant amount
// of time regardless of the size of the String_List instance.
//
// The semantics of _prev_to_current is such that it always points to the
// node *BEFORE* the current one. This makes the manipulations easy because
// we can only look forward (and not back) in singly linked lists.
//
// I've included some method header comments below where there's likely to
// be confusion.
//
class String_List {
private:
struct Node {
std::string data;
Node *next;
Node(std::string s = "") : data(s), next(nullptr) {}
};
Node *_head, *_tail, *_prev_to_current;
size_t _size;
public:
String_List() {
    _head = new Node("_SENTINEL_");
    _head->next = NULL;
    _tail = _head;
    _prev_to_current = _head;
    _size = 0;
}
~String_List() {
    delete _head;
}
String_List *insert_at_current(std::string s) {
    Node* _temp = new Node(s);
    _temp->next = _prev_to_current->next;
    _prev_to_current->next = _temp;
    _size += 1;
    return this;
}
String_List *push_back(std::string s) {
    Node* _temp = new Node(s);
    _temp->next = _tail->next;
    _tail->next = _temp;
    _tail = _temp;
    _size += 1;
    return this;
}
String_List *push_front(std::string s) {
    Node* _temp = new Node(s);
    if (_head->next == NULL)
        _tail = _temp;
    _temp->next = _head->next;
    _head->next = _temp;
    _size += 1;
    return this;
}
String_List *advance_current() {
    if (_prev_to_current == _tail)
        _prev_to_current = _tail;
    else
    _prev_to_current = _prev_to_current->next;
    return this;
}
std::string get_current() const {
    if (_prev_to_current != _tail)
        return _prev_to_current->next->data;
    else
    return _head->data;
}
String_List *remove_at_current() {
    Node* save = _prev_to_current->next;
    _prev_to_current->next = _prev_to_current->next->next;
    delete save;
    _size --;
    return this;
}
size_t get_size() const {
    return _size;
}
String_List *rewind() {
    _prev_to_current = _head;
    return this;
}
void clear() {
    Node* _temp = _head->next;
    Node* _del;
    while (_temp != NULL){
        _del = _temp;
        _temp = _temp->next;
        delete _del;
    }
    _prev_to_current = _head;
    _tail = _head;
    _head->next = NULL;
    _size = 0;
}
// Find a specific item. Does NOT change cursor.
//
// The following returns a reference to the target string if found. But what will
// you do if you didn't find the requested string? Using sentinel markers is
// one way to handle that situation. Usually there's only one copy of the
// sentinel that's global. We will use a local one so it's cleaner with a
// little more risk (what's the risk?)
//
std::string& find_item(std::string s) const {
    Node* _temp = _head->next;
    while (_temp != NULL){
        if (_temp->data == s)
            return _temp->data;
        _temp = _temp->next;
    }
    return _head->data;
}
// Print up to max_lines lines starting at _prev_to_current->next. If the caller
// wants to print from the beginning of the list, they should rewind() it first.
//
std::string to_string() const {
    Node* _temp = _head->next;
    int i = 0;
    std::string s = "";
    std::stringstream ss;
    ss << get_size();
    s = "# String_List - " + ss.str() + " entries total. Starting at cursor:\n";
    while (i < 25 && _temp != NULL){
        i++;
        s += _temp->data + "\n";
        _temp = _temp->next;
    }
    if (get_size() > 25)
        s += "...\n";
    return s;
}
friend class Tests; // Don't remove this line
};
#endif /* String_List_h */

