#include "object.h"  // Your file with the CwC declaration of Object
#include "array.h"  // Your file with the String class
#include <iostream>
 
void FAIL() {   std::cout << "fail" << std::endl;    }
void OK(const char* m) { /** print m */ }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }
 
void test1() {
  IntArray * s = new IntArray();
  IntArray * t = new IntArray();
  IntArray * u = new IntArray();
  
  u->push_back(5);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s->push_back(5);
  
  t_true(s->hash() == u->hash());
  t_true(s->equals(u));
  
  s->add(0, 4); 
  
  t_true(s->get(0) == 4); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->get(0) == 4); 
  t_true(s->get(1) == 5); 
  t_true(s->remove(1) == 5); 
  t_true(u->set(0, 7) == 5); 
 
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  u->push_back(-25);

  t_true(u->get(0) == -25);

  OK("1");
}
/* 
void test2() {
  BoolArray * s = new BoolArray();
  BoolArray * t = new BoolArray();
  BoolArray * u = new BoolArray();
  
  u.push_back(1);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s.push_back(1);
  
  t_true(s->hash() == u->hash());
  t_true(s->equal() == u->equal());
  
  s->add(0, 0); 
  
  t_true(s->get(0) == 0); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(0) == 0); 
  t_true(s->index_of(1) == 1); 
  t_true(s->remove(1) == 1); 
  t_true(u->set(0, 0) == 1); 
  t_true(u->get(0) == 0);
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  t->clear(); 

  t->add(0, 5); 

  t_true(t->size() == 0);

  t->add(0, -1); 

  t_true(t->size() == 0);


  OK("2");
}
 
void test3() {
  StringArray * s = new StringArray();
  s.add(0, "Test");
  String test = s.remove(0);
  s.add(0, "Test2"); 
  s.push_back("Test3");
  String replaced = s.replace(1, "replaced");
  s.clear();
  t_true(test->equals("Test"));
  t_true(replaced->equals("Test3"));
  t_true(s->is_empty());
  t_true(s->size() == 0);
  OK("3");
}

void test4() {
  StringArray * s = new StringArray();
  StringArray * t = new StringArray();
  StringArray * u = new StringArray();
  
  u.push_back("hello");
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s.add(0,"hello");
  
  t_true(s->hash() == u->hash());
  t_true(s->equal() == u->equal());
  
  s->add(0, "hi"); 
  
  t_true(s->get(0) == "hi"); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(0)->equals("hi")); 
  t_true(s->index_of(1)->equals("hello")); 
  t_true(s->remove(1)->equals("hello")); 
  t_true(u->set(0, "hi")->equals("hello")); 
  t_true(u->get(0)->equals("hi"));
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  t->clear(); 

  t->add(0, "5"); 

  t_true(t->size() == 1);

  OK("4");
}
 
void test5() {
  FloatArray * s = new FloatArray();
  FloatArray * t = new FloatArray();
  FloatArray * u = new FloatArray();
  
  u.push_back(5.7);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s.push_back(5.7);
  
  t_true(s->hash() == u->hash());
  t_true(s->equal() == u->equal());
  
  s->add(0, 4.2); 
  
  t_true(s->get(0) == 4.2); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(0) == 4.2); 
  t_true(s->index_of(1) == 5.7); 
  t_true(s->remove(1) == 5.7); 
  t_true(u->set(0, 16) == 5.7); 
  t_true(u->get(0) == 16.0);
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  u->push_back(-17.4)

  t_true(u->index_of(0) == -17.4);

  OK("5");
}

void test6() {
 String * s = new String("Hello");
 String * t = new String("World");
 String * u = s->concat(t);
 t_true(s->equals(s));
 t_false(s->equals(t));
 t_false(s->equals(u));

 t_true(u->size() == 10); 
 t_true(s->charAt(2) == s->charAt(3));
 t_true(s->charAt(0) == 'H'); 
 t_true(s->charAt(3) == t->charAt(3));

 
 String * tsetett = new String();
 t_true(tsetett->isEmpty()); 
 t_true(tsetett->size() == 0); 
 tsetett = tsetett->concat(u);
 t_true(tsetett->size() == 10); 
 t_true(tsetett->equals(u)); 
 t_false(tsetett->isEmpty()); 

 String * test = s->clone();
 t_true(test->equals(s)); 
 t_true(test->hash() == s->hash()); 

 t_true(test->compare(s) == 0);
 t_true(test->compare(t) < 0);
 t_true(u->compare(s) > 0);
 t_false(u->compare(tsetett) == 0);

 OK("6")
}
*/ 
int main() {
  test1();
//  test2();
//  test3();
//  test4();
//  test5();
//  test6();
  return 0;
}
