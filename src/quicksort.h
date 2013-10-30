/* 
 * Quick Sort
 * 
 * Simple implementation for demonstration purpose.
 * For production, use STL sort, it's at least two times faster.
 */

#ifndef QUICKSORT_H
#define	QUICKSORT_H

#include <vector>
#include <iterator>
#include "shed.h"
#include <iostream>

namespace sandbox {
    template<typename Iterator>
    inline void printOut(Iterator front, Iterator back);
    
    template<typename Iterator>
    inline void quickSort(Iterator front, Iterator back) {
        if (front >= back) return;
        Iterator front_margin(front);
        Iterator back_margin(back);
        Iterator target = front;
        while (front < back) {
            if (*front > *back) {
                swap(*front, *back); // in production use STL algorithm's std::swap
                if (target == front) {
                    target = back;
                    ++front;
                } else {
                    target = front;
                    --back;
                }
            } else {
                if (target == front) --back;
                else ++front;
            }
        }
        quickSort(front_margin, target - 1);
        quickSort(target + 1, back_margin);
    }

    template<typename T>
    inline std::vector<T>& quickSort(std::vector<T>& sortable) {
        quickSort(sortable.begin(), sortable.end() - 1);
        return sortable;
    }

    template<typename Iterator>
    void printOut(Iterator front, Iterator back) {
        for (; front <= back; std::cout << *front << " ", ++front);
        std::cout << std::endl;
    }
}

#endif	/* QUICKSORT_H */

