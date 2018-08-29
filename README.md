# Decltype-Bug
Decltype Bug

~/Main.cpp:25:72: error: no matching function for call to ‘HTestSet(TestClass&, void (BaseClass::*)(int), int&)’
     if(HTestSet(OBGEC_ON, &decltype(OBGEC_ON)::SET_CALL, test_vall_stor)){       \
