/* 
 * Collections of very simple algorithms
 * File:   shed.h
 * Author: GOro
 *
 * Created on 2013. szeptember 30., 14:49
 */

#ifndef SHED_H
#define	SHED_H

#include <string>
#include <algorithm>
#include <iterator>
#include <cstring>

namespace sandbox {
    // Generalized palindrome algorithm
    template<typename Iterator>
    inline bool isPalindrome(Iterator front, Iterator back) {
        for (; front < back; ++front, --back) {
            if (*front != *back) return false;
        }
        return true;
    }
    
    // Determine whether a string is a palindrome or not
    inline bool isPalindrome(std::string const& str) {
        return isPalindrome(str.begin(), str.end() - 1);
    } 

    // Determine whether a string is a palindrome or not
    inline bool isPalindrome(char const* str) {
        return isPalindrome(str, str + std::strlen(str) - 1);
    }

    inline bool isLittleEndian() {
        int i = 1;
        char* p = (char*) &i;  // every int is sizeof(int) piece of char
        return (*p & (char)1); // little endian if the first charish-'byte' equals 1
    }
    
    inline bool isBigEndian() {
        return !isLittleEndian();
    }
    
    // Swaps two object of the same type in place (only for intrinsic types!)
    // Just for demonstration purposes, use std::swap from algorithm
    template<typename T>
    inline void swap(T& a, T& b) {
    // The idea:
    // (a + b) - b = a
    // (a + b) - a = b
        
                    //        a         |        b
                    // ===================================
        a = a ^ b;  //      a ^ b       |        b
        b = a ^ b;  //      a ^ b       | (a ^ b) ^ b = a
        a = a ^ b;  // (a ^ b) ^ a = b  |        a
    }

    // Swaps objects
    template<typename Iterator>
    inline void swapInRange(Iterator front, Iterator back) {
        for (; front < back; ++front, --back)
            sandbox::swap(*front, *back);
    }
    
    // Reverse a string
    inline std::string& reverse(std::string& str) {
        sandbox::swapInRange(str.begin(), str.end() - 1);
        return str;
    }
    
    // Reverse a character array (C string)
    inline char* reverse(char* str) {
        sandbox::swapInRange(str, str + std::strlen(str));
        return str;
    }
    
    // Reverse the order of the words in a string
    inline std::string& reverseWords(std::string& str) {
        sandbox::reverse(str);
        std::string::iterator wordFront = str.begin(), wordEnd = str.begin();
        while (wordFront != str.end()) {
            if (*wordFront != ' ') {
                wordEnd = wordFront;
                while (wordEnd != str.end() && *wordEnd != ' ') ++wordEnd;
                sandbox::swapInRange(wordFront, wordEnd - 1);
                wordFront = wordEnd;
            } else {
                ++wordFront;
            }
        }
        return str;
    } 
}
#endif	/* SHED_H */

