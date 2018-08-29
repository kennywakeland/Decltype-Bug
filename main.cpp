//
// Created by kenny on 8/29/18.
//

#include <iostream>
#include <string>
#include <vector>


#define H_STR_HELPER(x) #x
#define H_STR(x) H_STR_HELPER(x)

#define H_GET_VALUE(OBGEC_ON, VAL_NAME) OBGEC_ON.get##VAL_NAME
#define H_SET_VALUE_ONE(OBGEC_ON, VAL_NAME) set##VAL_NAME

#define H_TEST_VALUE(OBGEC_ON, VAL_NAME, TEST_VALL) \
H_TEST_VALUE_GET_SET(H_GET_VALUE(OBGEC_ON, VAL_NAME), \
                     H_SET_VALUE_ONE(OBGEC_ON, VAL_NAME), \
                     OBGEC_ON, VAL_NAME, TEST_VALL)


#define H_TEST_VALUE_GET_SET(GET_CALL, SET_CALL, OBGEC_ON, VAL_NAME, TEST_VALL) \
{                                                              \
    auto test_vall_stor = TEST_VALL;                           \
    if(HTestSet(OBGEC_ON, &decltype(OBGEC_ON)::SET_CALL, test_vall_stor)){       \
        if( GET_CALL() == test_vall_stor){       \
           testFail("The Erorr equal " #SET_CALL " -- " H_STR(test_vall_stor) " ."); \
        }                                                      \
    }else{                                                     \
        testFail("The equal " #SET_CALL " is not working on " H_STR(test_vall_stor) " .");  \
    }                                                          \
}

template<class Obj, typename Vt, typename Vt_2>
inline bool
HTestSet(Obj& o, bool(Obj::*f)(Vt), Vt_2 v)
{
    return (o.*f)(v);
}

template<class Obj, typename Vt, typename Vt_2>
inline bool
HTestSet(Obj& o, void (Obj::*f)(Vt), Vt_2 v)
{
    (o.*f)(v);
    return true;
}

void testFail(std::string /*o*/) {}

class BaseClass
{
public:

    virtual int getRed() const = 0;
    virtual void setRed(int red) = 0;

    virtual int getBlue() const = 0;
    virtual bool setBlue(int blue) = 0;

    int getGreen() const { return g; }
    void setGreen(int green) { g = green; }

private:
    int g = 0;
};

class TestClass: public BaseClass
{
public:
    int getRed() const override { return r; }
    void setRed(int red) override { r = red; }

    int getBlue() const override { return r; }
    bool setBlue(int blue) override { b = blue; return true; }

private:
    int r = 0;
    int b = 0;
};


int main()
{
    TestClass woo;
    void (TestClass::*f)(int);
    f = &TestClass::setGreen;
    (woo.*f)(3);

    H_TEST_VALUE(woo, Red, 3);
    //H_TEST_VALUE(woo, Green, 3);
    H_TEST_VALUE(woo, Blue, 3);

}
