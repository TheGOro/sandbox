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

namespace sandbox {
    inline bool isPalindrome(std::string const&);
    inline bool isPalindrome(char const*);
    inline bool isLittleEndian() {
        int i = 1;
        char* p = (char*) &i;
        return (*p & (char)1);
    }
    
    inline bool isBigEndian() {
        return !isLittleEndian();
    }

    inline std::string& reverse(std::string&);
    inline std::string& reverseWords(std::string&);
    
    // Swaps two value of the same type in place
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
}
#endif	/* SHED_H */

