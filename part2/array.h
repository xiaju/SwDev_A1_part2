#pragma once
//lang::CwC
#include "object.h"

// Represents an array that stores elements of type int
class IntArray : public Object { 
	public:

		IntArray(); //default constructor
		IntArray(size_t size, int* vals); //convenience constructor, initializes new Array with all elements given
		
		~IntArray(); //destructor

		void push_back(int e); // Appends e to end
		void add(size_t i, int e); // Inserts e at i
		void add_all(size_t i, IntArray* c); // Inserts all of elements in c into this list at i
		void clear(); // Removes all of elements from this list
		virtual bool equals(Object* o); // Compares o with this list for equality.
		int get(size_t index); // Returns the element at index
		virtual size_t hash(); // Returns the hash code value for this list.
		size_t index_of(int o); // Returns the index of the first occurrence of o, or >size() if not there
		int remove(size_t i); //Removes the element at i, returns the removed element 
		int set(size_t i, int e); // Replaces the element at i with e
		size_t size(); // Return the number of elements in the collection
		bool is_empty(); // Is this array empty (0 elements stored)?
		void print(); // Print this object including the elements it stores
};

// Represents an array that stores elements of type bool
class BoolArray : public Object { 
	public:

		BoolArray(); //default constructor
		BoolArray(size_t size, int* vals); //convenience constructor, initializes new Array with all elements given
		
		~BoolArray(); //destructor

		void push_back(int e); // Appends e to end
		void add(size_t i, int e); // Inserts e at i
		void add_all(size_t i, BoolArray* c); // Inserts all of elements in c into this list at i
		void clear(); // Removes all of elements from this list
		virtual bool equals(Object* o); // Compares o with this list for equality.
		int get(size_t index); // Returns the element at index
		virtual size_t hash(); // Returns the hash code value for this list.
		size_t index_of(int o); // Returns the index of the first occurrence of o, or >size() if not there
		int remove(size_t i); //Removes the element at i, returns the removed element 
		int set(size_t i, int e); // Replaces the element at i with e
		size_t size(); // Return the number of elements in the collection
		bool is_empty(); // Is this array empty (0 elements stored)?
		void print(); // Print this object including the elements it stores
};

// Represents an array that stores elements of type float
class FloatArray : public Object { 
	public:

		FloatArray(); //default constructor
		FloatArray(size_t size, float* vals); //convenience constructor, initializes new Array with all elements given
		
		~FloatArray(); //destructor

		void push_back(float e); // Appends e to end
		void add(size_t i, float e); // Inserts e at i
		void add_all(size_t i, FloatArray* c); // Inserts all of elements in c into this list at i
		void clear(); // Removes all of elements from this list
		virtual bool equals(Object* o); // Compares o with this list for equality.
		float get(size_t index); // Returns the element at index
		virtual size_t hash(); // Returns the hash code value for this list.
		size_t index_of(float o); // Returns the index of the first occurrence of o, or >size() if not there
		float remove(size_t i); //Removes the element at i, returns the removed element 
		float set(size_t i, float e); // Replaces the element at i with e
		size_t size(); // Return the number of elements in the collection
		bool is_empty(); // Is this array empty (0 elements stored)?
		void print(); // Print this object including the elements it stores
};

// Represents an array that stores elements of type string
class StringArray : public Object { 
	public:

		StringArray(); //default constructor
		StringArray(size_t size, char** vals); //convenience constructor, initializes new Array with all elements given
		
		~StringArray(); //destructor

		void push_back(char* e); // Appends e to end
		void add(size_t i, char* e); // Inserts e at i
		void add_all(size_t i, StringArray* c); // Inserts all of elements in c into this list at i
		void clear(); // Removes all of elements from this list
		virtual bool equals(Object* o); // Compares o with this list for equality.
		String* get(size_t index); // Returns the element at index
		virtual size_t hash(); // Returns the hash code value for this list.
		size_t index_of(char* o); // Returns the index of the first occurrence of o, or >size() if not there
		String* remove(size_t i); //Removes the element at i, returns the removed element 
		String* set(size_t i, char* e); // Replaces the element at i with e
		size_t size(); // Return the number of elements in the collection
		bool is_empty(); // Is this array empty (0 elements stored)?
		void print(); // Print this object including the elements it stores
};




