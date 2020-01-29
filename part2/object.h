#pragma once
//lang::CwC
#include <stdlib.h> //Used for size_t which is ok according to TA (piazza post)

// Represents the top of the object hierarchy.                                                  
class Object {
	public:
	 	Object();
	 	virtual ~Object(); //destructor virtual to support subclasses   

	 	/* Returns the object's hash value. 
		 * Objects that are equal have the same hash. 
		 * Objects that are not equal may have the same hash. Should be implemented by subclasses
		 */
		virtual size_t hash();
		virtual bool equals(Object* other); // check equality between this object and other
};

