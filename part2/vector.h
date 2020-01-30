#pragma once
#include "object.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// A list of strings
class Vector : public Object {
  public:
    // Internal storage of objects
    Object **objects;
    // Number of objects inside our list 
    size_t sz;
    // Capacity of our internal list
    size_t capacity;

    // Create an empty list of objects
    Vector() : Object() {
      this->capacity = 2;
      this->sz = 0;
      this->objects = new Object*[2];
    }

    // Clean up vector
    virtual ~Vector() {
      delete this->objects;
    }

    // Appends e to end of this list
    virtual void push_back(Object* e) {
      expand();

      this->objects[this->size()] = e;
      this->sz++;
    }

    // Inserts e at index i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    virtual void add(size_t i, Object* e) {
      this->checkBoundsPlusOne(i);
 
      this->expand();
     
      memmove(&this->objects[i + 1], 
             &this->objects[i], 
             sizeof(Object*) * (this->size() - i));
      objects[i] = e;
      this->sz++;     
    }

    // Inserts all of elements in c into this list at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    virtual void add_all(size_t i, Vector* c) {
      this->checkBoundsPlusOne(i);
      for (size_t elem = 0; elem < c->size(); elem++) {
        this->add(elem + i, c->get(elem));
      }
   }
  
    // Removes all of elements from this list 
    virtual void clear() {
      this->sz = 0;
    }
  
    // Compares o with this list for equality
    virtual bool equals(Object* o) {
      Vector *s = dynamic_cast<Vector*>(o);
      if (s == NULL) {
        return false;
      } else {
        for (int i = 0; i < s->size() && i < this->size(); i++) {
          if (!(s->get(i)->equals(this->get(i)))) {
            return false;
          }
        }
      }
      return this->size() == s->size();
    }
  
    // Returns the element at index
    virtual Object* get(size_t index) {
      if (index < this->size() && index >= 0) {
        return this->objects[index];
      } else {
        return NULL;
      }
    }
  
    // Returns the hash code value for this list
    // https://stackoverflow.com/questions/2624192/good-hash-function-for-strings
    virtual size_t hash() {
      size_t hash = 31; 
      size_t ret = 1;
      for (size_t i = 0; i < this->size(); i++) {
        ret = ret * hash + this->get(i)->hash();
      }
    }
  
    // Returns the index of the first occurrence of o, or >size() if not there
    virtual size_t index_of(Object* o) {
      Vector *s = dynamic_cast<Vector*>(o);
      for (int i = 0; i < this->size(); i++) {
        if (s->equals(this->get(i))) {
          return i;
        }
      }
      return this->size() + 1;
    }
  
    // Removes the element at i
    // Error if user attempts to add to a negative index
    // or index greater than the size of the list
    virtual Object* remove(size_t i) {
      this->checkBoundsCur(i); 

      Object* tmp = this->objects[i];

      memmove(&this->objects[i], 
             &this->objects[i + 1], 
             sizeof(Object*) * (this->size() - i));
      this->sz--;

      return tmp;
    }
  
    // Replaces the element at i with e
    virtual Object* set(size_t i, Object* e) {
      this->checkBoundsCur(i);

      return this->objects[i] = e;
    }
  
    // Return the number of elements in the collection
    virtual size_t size() {
      return this->sz;
    }

    // checks if the internal list capacity can take the given number of elements
    // and increases the capacity if needed
    virtual void expand() {
      size_t num = 1;
      if (num + this->size() > capacity) {
        this->capacity = this->capacity * 2;

        Object **tmp = new Object*[this->capacity];
        memcpy(tmp, this->objects, sizeof(Object*) * this->size());

        delete this->objects;
        this->objects = tmp;

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
