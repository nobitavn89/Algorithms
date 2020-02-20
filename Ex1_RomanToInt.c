//
//  RomanToInteger
//  https://leetcode.com/problems/roman-to-integer/
//
//

#include <stdio.h>

#define ERROR_CODE (-1)

//convert single roman char to integer
//return (-1) if input an invalid char
int convertSymbolToInt (char roman) {
    switch (roman) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return ERROR_CODE;
    }
}

int romanToInt(char * s){
    int result = 0;
    char* iterate_s = s;
    
    //iterate string and calculate the result
    while ((*iterate_s) != '\0') {
        char currentChar = (*iterate_s);
        int currentVal   = convertSymbolToInt(currentChar);
        if (currentVal == ERROR_CODE) {
            return ERROR_CODE;
        }
        
        char nextChar = (*(iterate_s + 1));
        //if char is I, X, C, we have to check substraction
        if ((currentChar == 'I' && (nextChar == 'V' || nextChar == 'X'))
             || ( currentChar == 'X' && (nextChar == 'L' || nextChar == 'C'))
             || ( currentChar == 'C' && (nextChar == 'D' || nextChar == 'M'))) {
            result += (convertSymbolToInt(nextChar) - currentVal);
            iterate_s++;
        } else {
            result += currentVal;
        }
        iterate_s++;
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    printf("Convert III: %d \n", romanToInt("III"));
    printf("Convert III: %d \n", romanToInt("IV"));
    printf("Convert III: %d \n", romanToInt("IX"));
    printf("Convert III: %d \n", romanToInt("LVIII"));
    printf("Convert III: %d \n", romanToInt("MCMXCIV"));
    return 1;
}
