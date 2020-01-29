CwC API
We have created method signatures of an Array data structure that will be used within the company.

We have also included tests that verify the correctness of the API (if the methods and classes were
implemented properly). 

The array stores elements of a similar, generic type <T> at the array's indices. The API offers multiple functions to facilitate the usage of an Array. Functionality should include:
    - Appending elements (to the end and at a specified index)
    - Adding all elements from another array to the current array 
    - Clearing all the elements in the array 
    - Confirming the equality of two arrays 
    - Returning the value stored at a specified index 
    - Returning the hash code value of the array 
    - Returninging the index of a specified object in the array 
    - Removing an element at a specified index 
    - Replacing an element at a specified index with a specified object 
    - Identifying the size of the array 
    - Identifying whether or not the array is empty 
    - Printing all elements in the array 


We included an object class that serves as the parent class for the array. Its functionality includes object equality checks and hash computation. Object equality is defined by comparing memory addresses. Hash computation returns the object's hash value such that objects that are equal have the same hash. Objects that are not equal may have the same hash. These functions are virtual and should be implemented by the child classes (e.g Array).
