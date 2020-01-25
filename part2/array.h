#pragma once
//lang::CwC
#include "object.h"

// Represents an array that stores elements of a similar, generic type <T> at the array's indexes.
template <class T>
class Array : public Object { 
	public:

		Array(); //default constructor
		Array(size_t size, T* vals); //convenience constructor, initializes new Array with all elements given
		~Array(); //destructor

		void push_back(T e); // Appends e to end
		void add(size_t i, T e); // Inserts e at i
		void add_all(size_t i, Array* c); // Inserts all of elements in c into this list at i
		void clear(); // Removes all of elements from this list
		bool equals(Object* o); // Compares o with this list for equality.
		T get(size_t index); // Returns the element at index
		size_t hash(); // Returns the hash code value for this list.
		size_t index_of(Object* o); // Returns the index of the first occurrence of o, or >size() if not there
		T remove(size_t i); //Removes the element at i, returns the removed element 
		T set(size_t i, T e); // Replaces the element at i with e
		size_t size(); // Return the number of elements in the collection
		bool is_empty(); // Is this array empty (0 elements stored)?
		void print(); // Print this object including the elements it stores
};