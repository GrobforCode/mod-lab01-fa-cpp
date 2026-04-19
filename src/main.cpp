// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
     const char *testStr1 = "qwe4  gftt e 555gr rrgr  grhh ";
    std::cout << "faStr1: " << faStr1(testStr1) << std::endl;
    
    const char *testStr2 = "Hello world!";
    std::cout << "faStr2: " << faStr2(testStr2) << std::endl;
    
    const char *testStr3 = " six monkeys";
    std::cout << "faStr3: " << faStr3(testStr3) << std::endl;
    
    return 0;
}
