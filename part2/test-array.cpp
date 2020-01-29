#include "object.h"  // Your file with the CwC declaration of Object
#include "array.h"  // Your file with the String class
 
void FAIL() {   exit(1);    }
void OK(const char* m) { /** print m */ }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }
 
void test1() {
  Array<int> * s = new Array<int>();
  Array<int> * t = new Array<int>();
  Array<int> * u = new Array<int>();
  u.push_back(5);
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));

  s.push_back(5);
  t_true(s->hash() == u->hash());

  OK("1");
}
 
void test2() {
  Array<String> * s = new Array<String>();
  s.add(0, "Hello");
  Array<String> * t = new Array<String>();
  t.add(0, "Hello");
  Array<String> * u = s->add_all(t);
  t_true(s->get(0)->equals("Hello"));
  t_true(s->equals(t));
  t_false(s->equals(u));
  t_true(u->size() == 2);
  OK("2");
}
 
void test3() {
  Array<String> * s = new Array<String>();
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
    Object * obj = new Object();
    Object * obj2 = obj;
    Object * obj3 = new Object();
    t_true(obj->equals(obj2));
    t_true(obj2->equals(obj));
    t_false(obj3->equals(obj2));
    t_true(obj2->hash() == obj->hash());
    OK("4");
}
 
int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}