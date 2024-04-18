#include "Student.h"
#include "Book.h"

#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H

namespace seneca
{
    template<typename T, typename U>
    struct  Pair
    {
        T first;

        U second;
    };

    template<typename T, typename U>
    void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size)
    {

        Pair<T, U>* temp = new Pair<T, U>[size + 1];

        for (int k = 0; pArray && k < size; k++) {

            temp[k] = pArray[k];

        }

        temp[size].first = first;

        temp[size].second = second;

        delete[] pArray;

        pArray = temp;

        size++;
    }
 
    template<typename T, typename U>
    Pair<T, U>*  matches(T* arr1, U* arr2, int size1, int size2, int& full_size)
    {
        Pair<T, U>* pt = nullptr;

        full_size = 0;

        for (int i = 0; i < size1; i++)
        {

            for (int j = 0; j < size2; j++)
            {

                if (arr1[i] == arr2[j])
                {

                    addDynamicPairElement(pt, arr1[i], arr2[j], full_size);

                } 

            }
        }

        return pt;
    }

    template<typename T>
    void releaseMem(T* arr)
    {
        if (arr)
        {

            delete[] arr;

        }
    }

}
#endif
