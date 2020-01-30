#pragma once
#ifndef ASSIGNMENT1_PART2_OBJECT_H
#define ASSIGNMENT1_PART2_OBJECT_H

#endif //ASSIGNMENT1_PART2_OBJECT_H
#include <stdlib.h>

class Object {
public:
    Object() {
      
    }

    virtual ~Object() {

    }

    virtual size_t hash() {
      return reinterpret_cast<size_t>(this);
    }

    virtual bool equals(Object* object) {
      this == object;
    }

    virtual void print() {
      
    }
};
