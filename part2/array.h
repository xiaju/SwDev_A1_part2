#pragma once
//lang::CwC
#include "object.h"
#include "vector.h"
#include "string.h"

// Represents an array that stores elements of type int
class IntArray : public Object { 
  public:
    // Internal storage of ints
    int *ints;
    // Number of objects inside our list 
    size_t sz;
    // Capacity of our internal list
    size_t capacity;

    // Create an empty list of objects
    IntArray() : Object() {
      this->capacity = 2;
      this->sz = 0;
      this->ints = new int[2];
    }

    // convenience constructor
    IntArray(size_t size, int* vals) {
      this->ints = new int[2];
      this->capacity = 2;
      this->sz = 0;
      for (size_t i = 0; i < size; i++) {
        this->push_back(vals[i]);
      }
    }

    // destructor
    ~IntArray() {
      delete this->ints;
    }

    // Appends e to end of this list
    void push_back(int e) {
      expand();

      this->ints[this->size()] = e;
      this->sz++;
    }

    // Inserts e at index i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    void add(size_t i, int e) {
      this->checkBoundsPlusOne(i);
 
      this->expand();
     
      memmove(&this->ints[i + 1], 
             &this->ints[i], 
             sizeof(int) * (this->size() - i));
      ints[i] = e;
      this->sz++;     
    }

    // Inserts all of elements in c into this list at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    void add_all(size_t i, IntArray* c) {
      this->checkBoundsPlusOne(i);
      for (size_t elem = 0; elem < c->size(); elem++) {
        this->add(elem + i, c->get(elem));
      }
   }
  
    // Removes all of elements from this list 
    void clear() {
      this->sz = 0;
    }
  
    // Compares o with this list for equality
    bool equals(Object* o) {
      IntArray *s = dynamic_cast<IntArray*>(o);
      if (s == NULL) {
        return false;
      } else {
        for (int i = 0; i < s->size() && i < this->size(); i++) {
          if (!(s->get(i) == (this->get(i)))) {
            return false;
          }
        }
      }
      return this->size() == s->size();
    }
  
    // Returns the element at index
    int get(size_t index) {
      checkBoundsCur(index);
      return this->ints[index];
    }
  
    // Returns the hash code value for this list
    // https://stackoverflow.com/questions/2624192/good-hash-function-for-strings
    virtual size_t hash() {
      size_t hash = 31; 
      size_t ret = 1;
      for (size_t i = 0; i < this->size(); i++) {
        ret = ret * hash + this->get(i);
      }
    }
  
    // Returns the index of the first occurrence of o, or >size() if not there
    size_t index_of(int o) {
      for (int i = 0; i < this->size(); i++) {
        if (o == this->get(i)) {
          return i;
        }
      }
      return this->size() + 1;
    }
  
    // Removes the element at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    int remove(size_t i) {
      this->checkBoundsCur(i); 

      int tmp = this->ints[i];

      memmove(&this->ints[i], 
             &this->ints[i + 1], 
             sizeof(int) * (this->size() - i));
      this->sz--;

      return tmp;
    }
  
    // Replaces the element at i with e
    int set(size_t i, int e) {
      this->checkBoundsCur(i);
      int tmp = this->ints[i];
      this->ints[i] = e;
      return tmp;
    }
  
    // Return the number of elements in the collection
    size_t size() {
      return this->sz;
    }

    bool is_empty() {
      return this->sz == 0;
    }

    // checks if the internal list capacity can take the given number of elements
    // and increases the capacity if needed
    virtual void expand() {
      size_t num = 1;
      if (num + this->size() > capacity) {
        this->capacity = this->capacity * 2;

        int *tmp = new int[this->capacity];
        memcpy(tmp, this->ints, sizeof(int) * this->size());

        delete this->ints;
        this->ints = tmp;

        this->expand();
      }
    }

    // internal method to make sure bounds are between 0 and the list's size ok
    virtual void checkBoundsPlusOne(size_t i) {
      if (i > this->size() || i < 0) {
        fprintf(stderr, "indexOutOfBounds Exception");
        exit(1);
      }
    }

    // internal method to make sure bounds are between 0 and size - 1 are ok
    virtual void checkBoundsCur(size_t i) {
      if (i >= this->size() || i < 0) {
        fprintf(stderr, "indexOutOfBounds Exception");
        exit(1);
      }     
    }
};

// Represents an array that stores elements of type bool
class BoolArray : public Object { 
  public:
    // Internal storage of ints
    bool *bools;
    // Number of objects inside our list 
    size_t sz;
    // Capacity of our internal list
    size_t capacity;

    // Create an empty list of objects
    BoolArray() : Object() {
      this->capacity = 2;
      this->sz = 0;
      this->bools = new bool[2];
    }

    // convenience constructor
    BoolArray(size_t size, bool* vals) {
      this->bools = new bool[2];
      this->capacity = 2;
      this->sz = 0;
      for (size_t i = 0; i < size; i++) {
        this->push_back(vals[i]);
      }
    }

    // destructor
    ~BoolArray() {
      delete this->bools;
    }

    // Appends e to end of this list
    void push_back(bool e) {
      expand();

      this->bools[this->size()] = e;
      this->sz++;
    }

    // Inserts e at index i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    void add(size_t i, bool e) {
      this->checkBoundsPlusOne(i);
 
      this->expand();
     
      memmove(&this->bools[i + 1], 
             &this->bools[i], 
             sizeof(bool) * (this->size() - i));
      bools[i] = e;
      this->sz++;     
    }

    // Inserts all of elements in c into this list at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    void add_all(size_t i, BoolArray* c) {
      this->checkBoundsPlusOne(i);
      for (size_t elem = 0; elem < c->size(); elem++) {
        this->add(elem + i, c->get(elem));
      }
   }
  
    // Removes all of elements from this list 
    void clear() {
      this->sz = 0;
    }
  
    // Compares o with this list for equality
    bool equals(Object* o) {
      BoolArray *s = dynamic_cast<BoolArray*>(o);
      if (s == NULL) {
        return false;
      } else {
        for (int i = 0; i < s->size() && i < this->size(); i++) {
          if (!(s->get(i) == (this->get(i)))) {
            return false;
          }
        }
      }
      return this->size() == s->size();
    }
  
    // Returns the element at index
    bool get(size_t index) {
      checkBoundsCur(index);
      return this->bools[index];
    }
  
    // Returns the hash code value for this list
    // https://stackoverflow.com/questions/2624192/good-hash-function-for-strings
    virtual size_t hash() {
      size_t hash = 31; 
      size_t ret = 1;
      for (size_t i = 0; i < this->size(); i++) {
        ret = ret * hash + this->get(i);
      }
    }
  
    // Returns the index of the first occurrence of o, or >size() if not there
    size_t index_of(bool o) {
      for (int i = 0; i < this->size(); i++) {
        if (o == this->get(i)) {
          return i;
        }
      }
      return this->size() + 1;
    }
  
    // Removes the element at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    bool remove(size_t i) {
      this->checkBoundsCur(i); 

      bool tmp = this->bools[i];

      memmove(&this->bools[i], 
             &this->bools[i + 1], 
             sizeof(bool) * (this->size() - i));
      this->sz--;

      return tmp;
    }
  
    // Replaces the element at i with e
    bool set(size_t i, bool e) {
      this->checkBoundsCur(i);
      bool tmp = this->bools[i];
      this->bools[i] = e;
      return tmp;
    }
  
    // Return the number of elements in the collection
    size_t size() {
      return this->sz;
    }

    bool is_empty() {
      return this->sz == 0;
    }

    // checks if the internal list capacity can take the given number of elements
    // and increases the capacity if needed
    virtual void expand() {
      size_t num = 1;
      if (num + this->size() > capacity) {
        this->capacity = this->capacity * 2;

        bool *tmp = new bool[this->capacity];
        memcpy(tmp, this->bools, sizeof(bool) * this->size());

        delete this->bools;
        this->bools = tmp;

        this->expand();
      }
    }

    // internal method to make sure bounds are between 0 and the list's size ok
    virtual void checkBoundsPlusOne(size_t i) {
      if (i > this->size() || i < 0) {
        fprintf(stderr, "indexOutOfBounds Exception");
        exit(1);
      }
    }

    // internal method to make sure bounds are between 0 and size - 1 are ok
    virtual void checkBoundsCur(size_t i) {
      if (i >= this->size() || i < 0) {
        fprintf(stderr, "indexOutOfBounds Exception");
        exit(1);
      }     
    }
};

/// Represents an array that stores elements of type float
class FloatArray : public Object { 
  public:
    // Internal storage of ints
    float *floats;
    // Number of objects inside our list 
    size_t sz;
    // Capacity of our internal list
    size_t capacity;

    // Create an empty list of objects
    FloatArray() : Object() {
      this->capacity = 2;
      this->sz = 0;
      this->floats = new float[2];
    }

    // convenience constructor
    FloatArray(size_t size, bool* vals) {
      this->floats = new float[2];
      this->capacity = 2;
      this->sz = 0;
      for (size_t i = 0; i < size; i++) {
        this->push_back(vals[i]);
      }
    }

    // destructor
    ~FloatArray() {
      delete this->floats;
    }

    // Appends e to end of this list
    void push_back(float e) {
      expand();

      this->floats[this->size()] = e;
      this->sz++;
    }

    // Inserts e at index i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    void add(size_t i, float e) {
      this->checkBoundsPlusOne(i);
 
      this->expand();
     
      memmove(&this->floats[i + 1], 
              &this->floats[i], 
             sizeof(float) * (this->size() - i));
      floats[i] = e;
      this->sz++;     
    }

    // Inserts all of elements in c into this list at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    void add_all(size_t i, FloatArray* c) {
      this->checkBoundsPlusOne(i);
      for (size_t elem = 0; elem < c->size(); elem++) {
        this->add(elem + i, c->get(elem));
      }
   }
  
    // Removes all of elements from this list 
    void clear() {
      this->sz = 0;
    }
  
    // Compares o with this list for equality
    bool equals(Object* o) {
      FloatArray *s = dynamic_cast<FloatArray*>(o);
      if (s == NULL) {
        return false;
      } else {
        for (int i = 0; i < s->size() && i < this->size(); i++) {
          if (!(s->get(i) == (this->get(i)))) {
            return false;
          }
        }
      }
      return this->size() == s->size();
    }
  
    // Returns the element at index
    bool get(size_t index) {
      checkBoundsCur(index);
      return this->floats[index];
    }
  
    // Returns the hash code value for this list
    // https://stackoverflow.com/questions/2624192/good-hash-function-for-strings
    virtual size_t hash() {
      size_t hash = 31; 
      size_t ret = 1;
      for (size_t i = 0; i < this->size(); i++) {
        ret = ret * hash + this->get(i);
      }
    }
  
    // Returns the index of the first occurrence of o, or >size() if not there
    size_t index_of(float o) {
      for (int i = 0; i < this->size(); i++) {
        if (o == this->get(i)) {
          return i;
        }
      }
      return this->size() + 1;
    }
  
    // Removes the element at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    float remove(size_t i) {
      this->checkBoundsCur(i); 

      float tmp = this->floats[i];

      memmove(&this->floats[i], 
             &this->floats[i + 1], 
             sizeof(float) * (this->size() - i));
      this->sz--;

      return tmp;
    }
  
    // Replaces the element at i with e
    float set(size_t i, float e) {
      this->checkBoundsCur(i);
      float tmp = this->floats[i];
      this->floats[i] = e;
      return tmp;
   }
  
    // Return the number of elements in the collection
    size_t size() {
      return this->sz;
    }

    bool is_empty() {
      return this->sz == 0;
    }

    // checks if the internal list capacity can take the given number of elements
    // and increases the capacity if needed
    virtual void expand() {
      size_t num = 1;
      if (num + this->size() > capacity) {
        this->capacity = this->capacity * 2;

        float *tmp = new float[this->capacity];
        memcpy(tmp, this->floats, sizeof(float) * this->size());

        delete this->floats;
        this->floats = tmp;

        this->expand();
      }
    }

    // internal method to make sure bounds are between 0 and the list's size ok
    virtual void checkBoundsPlusOne(size_t i) {
      if (i > this->size() || i < 0) {
        fprintf(stderr, "indexOutOfBounds Exception");
        exit(1);
      }
    }

    // internal method to make sure bounds are between 0 and size - 1 are ok
    virtual void checkBoundsCur(size_t i) {
      if (i >= this->size() || i < 0) {
        fprintf(stderr, "indexOutOfBounds Exception");
        exit(1);
      }     
    }
};

// Represents an array that stores elements of type string
class StringArray : public Object { 
	public:
    Vector* v_;

		StringArray() {
      this->v_ = new Vector();
    }
		StringArray(size_t size, char** vals) {
      for (size_t i = 0; i < size; i++) {
        this->v_->push_back(new String(vals[i]));
      }
    }
		
		~StringArray() {
      size_t size = this->v_->size();
      for (size_t i = 0; i < size; i++) {
        delete this->v_->remove(0);
      }
    }

		void push_back(char* e) {
      this->v_->push_back(new String(e));
    }
		void add(size_t i, char* e) {
      this->v_->add(i, new String(e));
    }
		void add_all(size_t i, StringArray* c) {
      this->v_->add_all(i, c->v_);
    }
		void clear() {
      this->v_->clear();
    }
		virtual bool equals(Object* o) {
      StringArray *s = dynamic_cast<StringArray*>(o);
      return s->v_->equals(this->v_);
    }
		String* get(size_t index) {
      return static_cast<String*>(this->v_->get(index));
    }
		virtual size_t hash() {
      return this->v_->hash();
    }
		size_t index_of(char* o) {
      String tmp = String(o);
      return this->v_->index_of(&tmp);
    }
		String* remove(size_t i) {
      return static_cast<String*>(this->v_->remove(i));
    }
		String* set(size_t i, char* e) {
      Object* tmp = this->v_->get(i);
      String* ret = static_cast<String*>(this->v_->set(i, new String(e)));
      delete tmp;
      return ret;
    }
		size_t size() {
      return this->v_->size();
    }
		bool is_empty() {
      return this->v_->size() == 0;
    }
		void print() {

    }
};

