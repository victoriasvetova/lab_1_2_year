#pragma once
#include "Sequences.h"

template<typename T>
class LinkedListSequence : public Sequence<T> {
public:

    LinkedListSequence() : data() {}

    LinkedListSequence<T> *Clone() override { return new LinkedListSequence<T>(); }

    LinkedListSequence<T> *CreateZeroSequence(int count) override {
        return new LinkedListSequence<T>(count);
    }

    LinkedListSequence(T *items, int count) : data(items, count) {}

    LinkedListSequence(int count) : data(count) {}


    int GetLength() {
        return data.GetLength();
    }

    T &GetFirst() {
        return data.GetFirst();
    }

    T &GetLast() {
        return data.GetLast();
    }


    T &Get(int index) {
        return data.Get(index);
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {
        data.InsertAt(item, index);
    }

    void removeAt(int index) {
        data.removeAt(index);
    }

    void Print() {
        data.Print();
    }

    void CountingSort() override {
        ICountingSort<T> obj;
        obj.Sort(nullptr,this);
    }

    void MergeSort(bool(*cmp)(const T&,const T&)) override {
        IMergeSort<T> obj;
        obj.Sort(cmp,this, 0, this->GetLength() - 1);
    }

    void InsertSort(bool(*cmp)(const T&,const T&)) override {
        IInsertSort<T> obj;
        obj.Sort(cmp,this);
    }

private:
    LinkedList<T> data;
};
