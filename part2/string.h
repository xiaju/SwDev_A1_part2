//lang::CwC
#pragma once

#include <assert.h>


//represents a string, or list of characters
class String : public Object {
public:
	//fields go here

	//default constructor
	String() : Object() {
	}

	//string literal consturctor (copy of parameter)
	String(const char* c) : Object() {
    }

	//character pointer consturctor (copy of parameter)
    String(char* c) : Object() {
    }

    //destructor
    virtual ~String() override {
    }
    
    //returns the current size/length of this String (i.e. how many chars is it made of?)
    size_t size() {
    }

    //concat the param's value to the end of this String
    String* concat(String* str) {
    }

    //concat the param to the end of this String
    String* concat(char* ch) {
    }

	//is this String the empty string?
    bool isEmpty() {
    }

    //returns the character at a specific index, if this index exists. 
    //othewise it is an invalid call to this function.
    char charAt(size_t index) {
    }

    //returns the index of the first occurrance of the given char within this String
    //should return a 'non-index' value if the character is not found
    int indexOf(char ch) {
    }

    //return a copy of this String
    String* clone() {
    }

    //is this String equal to the given parameter?
    //inherited from Object
    bool equals(Object* obj) override {
    }

    //generates a hash value for this String
    //inherited from Object
    size_t hash() override {
    }

    //compares strings based on alphabetical order
    //returns a negative number if this String is 'less than' parameter String 
    //returns 0 number if this String is 'equal to' parameter String
   	//returns a positive number if this String is 'greater than' parameter String
    int compare(String* str) { 
    }
};


