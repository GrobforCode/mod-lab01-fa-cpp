// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
unsigned int faStr1(const char *str) {
    State state = OUT;
    unsigned int count = 0;
    bool hasDigit = false;
    
    for (const char *p = str; *p; ++p) {
        if (state == OUT) {
            if (!std::isspace(static_cast<unsigned char>(*p))) {
                state = IN;
                hasDigit = false;
                if (std::isdigit(static_cast<unsigned char>(*p))) {
                    hasDigit = true;
                }
            }
        } else { // IN
            if (std::isspace(static_cast<unsigned char>(*p))) {
                if (!hasDigit) {
                    ++count;
                }
                state = OUT;
            } else {
                if (std::isdigit(static_cast<unsigned char>(*p))) {
                    hasDigit = true;
                }
            }
        }
    }
    if (state == IN && !hasDigit) {
        ++count;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    State state = OUT;
    unsigned int count = 0;
    bool valid = false;
    
    for (const char *p = str; *p; ++p) {
        unsigned char c = static_cast<unsigned char>(*p);
        if (state == OUT) {
            if (!std::isspace(c)) {
                state = IN;
                // Проверка первого символа: заглавная латинская буква
                if (c >= 'A' && c <= 'Z') {
                    valid = true;
                } else {
                    valid = false;
                }
            }
        } else { // IN
            if (std::isspace(c)) {
                if (valid) {
                    ++count;
                }
                state = OUT;
            } else {
                // Если слово уже невалидно, ничего не меняем
                if (valid) {
                    // Все последующие символы должны быть строчными латинскими
                    if (!(c >= 'a' && c <= 'z')) {
                        valid = false;
                    }
                }
            }
        }
    }
    if (state == IN && valid) {
        ++count;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    State state = OUT;
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    int currentLen = 0;
    
    for (const char *p = str; *p; ++p) {
        if (state == OUT) {
            if (!std::isspace(static_cast<unsigned char>(*p))) {
                state = IN;
                currentLen = 1;
            }
        } else { // IN
            if (std::isspace(static_cast<unsigned char>(*p))) {
                ++wordCount;
                totalLength += currentLen;
                state = OUT;
            } else {
                ++currentLen;
            }
        }
    }
    if (state == IN) {
        ++wordCount;
        totalLength += currentLen;
    }
    
    if (wordCount == 0) {
        return 0;
    }
    
    // Математическое округление: (totalLength + wordCount/2) / wordCount
    // Но для целочисленного округления к ближайшему целому:
    // прибавляем половину делителя перед делением
    return (totalLength * 10 / wordCount + 5) / 10;
}
