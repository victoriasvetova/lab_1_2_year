#pragma once

#include "DynamicArray.h"
#include "LinkedList.h"

template<typename T>
class Sequence {
public:


    virtual Sequence<T> *CreateZeroSequence(int count) = 0;

    virtual Sequence<T> *Clone() = 0;

    virtual T& GetFirst() = 0;

    virtual T& GetLast() = 0;

    virtual T& Get(int index) = 0;

    virtual void CountingSort() = 0;

    virtual void MergeSort(bool(*cmp)(const T&,const T&)) = 0;

    virtual void InsertSort(bool(*cmp)(const T&,const T&)) = 0;

    virtual int GetLength() = 0;

    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;




    virtual void Print() = 0;
};


