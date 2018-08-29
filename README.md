# Decltype-Bug
Decltype Bug

https://coliru.stacked-crooked.com/a/443f03625728f00e

# Output

```
g++ -std=c++11 -O2 -Wall -pedantic -pthread main.cpp && ./a.out

main.cpp: In function 'int main()':
main.cpp:26:72: error: no matching function for call to 'HTestSet(TestClass&, void (BaseClass::*)(int), int&)'
     if(HTestSet(OBGEC_ON, &decltype(OBGEC_ON)::SET_CALL, test_vall_stor)){       \
                                                                        ^

main.cpp:18:1: note: in expansion of macro 'H_TEST_VALUE_GET_SET'
 H_TEST_VALUE_GET_SET(H_GET_VALUE(OBGEC_ON, VAL_NAME), \
 ^~~~~~~~~~~~~~~~~~~~

main.cpp:92:5: note: in expansion of macro 'H_TEST_VALUE'
     H_TEST_VALUE(woo, Green, 3);
     ^~~~~~~~~~~~

main.cpp:37:1: note: candidate: 'template<class Obj, class Vt, class Vt_2> bool HTestSet(Obj&, bool (Obj::*)(Vt), Vt_2)'
 HTestSet(Obj& o, bool(Obj::*f)(Vt), Vt_2 v)
 ^~~~~~~~

main.cpp:37:1: note:   template argument deduction/substitution failed:

main.cpp:26:72: note:   mismatched types 'bool' and 'void'
     if(HTestSet(OBGEC_ON, &decltype(OBGEC_ON)::SET_CALL, test_vall_stor)){       \
                                                                        ^

main.cpp:18:1: note: in expansion of macro 'H_TEST_VALUE_GET_SET'
 H_TEST_VALUE_GET_SET(H_GET_VALUE(OBGEC_ON, VAL_NAME), \
 ^~~~~~~~~~~~~~~~~~~~

main.cpp:92:5: note: in expansion of macro 'H_TEST_VALUE'
     H_TEST_VALUE(woo, Green, 3);
     ^~~~~~~~~~~~

main.cpp:44:1: note: candidate: 'template<class Obj, class Vt, class Vt_2> bool HTestSet(Obj&, void (Obj::*)(Vt), Vt_2)'
 HTestSet(Obj& o, void (Obj::*f)(Vt), Vt_2 v)
 ^~~~~~~~

main.cpp:44:1: note:   template argument deduction/substitution failed:

main.cpp:26:72: note:   deduced conflicting types for parameter 'Obj' ('TestClass' and 'BaseClass')
     if(HTestSet(OBGEC_ON, &decltype(OBGEC_ON)::SET_CALL, test_vall_stor)){       \
                                                                        ^
main.cpp:18:1: note: in expansion of macro 'H_TEST_VALUE_GET_SET'
 H_TEST_VALUE_GET_SET(H_GET_VALUE(OBGEC_ON, VAL_NAME), \
 ^~~~~~~~~~~~~~~~~~~~

main.cpp:92:5: note: in expansion of macro 'H_TEST_VALUE'
     H_TEST_VALUE(woo, Green, 3);
     ^~~~~~~~~~~~
```
