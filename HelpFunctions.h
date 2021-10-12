#pragma once
#include "Sequences.h"

template<typename T>
bool cmp(const T& a,const T& b){
    return a <= b;
}
template<typename T>
bool cmp_(const T& a,const T& b){
    return a > b;
}

template<typename T>
Sequence<T>* AllocateMemory(Sequence<T>* tmp){
    return tmp->Clone();
}

template<typename T>
void merge(bool(*cmp)(const T&,const T&),Sequence<T>* seq,int l,int r){
    int i = l;
    int mid = l + (r - l) / 2;
    int j = mid + 1;
    int pos = 0;
    Sequence<T>* res = AllocateMemory(seq);
    res = res->CreateZeroSequence(r - l + 1);
    while(i <= mid && j <= r){
        if(cmp(seq->Get(i) , seq->Get(j)))
            res->Get(pos++) = seq->Get(i++);
        else
            res->Get(pos++) = seq->Get(j++);
    }
    while(i <= mid)
        res->Get(pos++) = seq->Get(i++);
    while(j <= r)
        res->Get(pos++) = seq->Get(j++);
    for (int i = l; i <= r; ++i) {
        seq->Get(i) = res->Get(i - l);
    }
}

template<typename T>
void merge_sort(bool(*cmp)(const T&,const T&),Sequence<T>* seq,int l,int r){
    if(r <= l)
        return;
    int mid = l + (r-l)/2;
    merge_sort(cmp,seq,l,mid);
    merge_sort(cmp,seq,mid+1,r);
    merge(cmp,seq,l,r);
}
