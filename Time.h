#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "HelpFunctions.h"
#include <time.h>
#include <fstream>

//реализация сортировки слиянием для проверки работы алгоритмов на отсортированных данных
//=====================================================================================//
template<typename T>
void merge(T* a,int l,int r){
    int i = l;
    int mid = l + (r - l) / 2;
    int j = mid + 1;
    int pos = 0;
    T* b = new T[r - l + 1];
    while (i<=mid && j <= r){
        if(a[i] < a[j])
            b[pos++] = a[i++];
        else
            b[pos++] = a[j++];
    }
    while (i <= mid)
        b[pos++] = a[i++];
    while (j <= r)
        b[pos++] = a[j++];
    for (int i = l; i <= r; ++i) {
        a[i] = b[i - l];
    }
}

template<typename T>
void merge_sort(T* a,int l,int r){
    if(r <= l)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(a,l,mid);
    merge_sort(a,mid + 1,r);
    merge(a,l,r);
}
//=====================================================================================//

template<typename T>
void ArrayMergeSort(T max_value = 1000,int max_size = 100000){
    T data[max_size];
    for (int i = 0; i < max_size; ++i) {
        data[i] = rand() % max_value;
    }
    merge_sort(data,0,max_size);
    std::ofstream out;
    out.open("ArrayMergeSort.txt");
    for (int i = 1; i <= 10; ++i) {
        ArraySequence<T> a(data,i * 10000);
        unsigned int start = clock();
        a.MergeSort(cmp_);
        unsigned int finish = clock();
        out << finish - start << ' ';
    }
}
template<typename T>
void ArrayInsertSort(T max_value = 1000,int max_size = 100000){
    T data[max_size];
    for (int i = 0; i < max_size; ++i) {
        data[i] = rand() % max_value;
    }
    merge_sort(data,0,max_size);
    std::ofstream out;
    out.open("ArrayInsertSort.txt");
    for (int i = 1; i <= 10; ++i) {
        ArraySequence<T> a(data,i * 10000);
        unsigned int start = clock();
        a.InsertSort(cmp_);
        unsigned int finish = clock();
        out << finish - start << ' ';
    }
}

template<typename T>
void ArrayCountingSort(T max_value = 100000,int max_size = 100000){
    T data[max_size];
    for (int i = 0; i < max_size; ++i) {
        data[i] = rand() % max_value;
    }
    merge_sort(data,0,max_size);
    std::ofstream out;
    out.open("ArrayCountingSort.txt");
    for (int i = 1; i <= 10; ++i) {
        ArraySequence<T> a(data,i * 10000);
        unsigned int start = clock();
        a.CountingSort();
        unsigned int finish = clock();
        out << finish - start << ' ';
        std::cout << IsSorted(&a,cmp) << std::endl;
    }
}
//-----------------------------------------------------------------//
template<typename T>
void ListMergeSort(T max_value = 100000,int max_size = 100000){
    T data[max_size];
    for (int i = 0; i < max_size; ++i) {
        data[i] = rand() % max_value;
    }
    merge_sort(data,0,max_size);
    std::ofstream out;
    out.open("ListMergeSort.txt");
    for (int i = 1; i <= 10; ++i) {
        ArraySequence<T> a(data,i * 10000);
        unsigned int start = clock();
        a.MergeSort(cmp_);
        unsigned int finish = clock();
        out << finish - start << ' ';
    }
    std::cerr << "Merge is done\n";
}
template<typename T>
void ListInsertSort(T max_value = 100000,int max_size = 100000){
    T data[max_size];
    for (int i = 0; i < max_size; ++i) {
        data[i] = rand() % max_value;
    }
    merge_sort(data,0,max_size);
    std::ofstream out;
    out.open("ListInsertSort.txt");
    for (int i = 1; i <= 10; ++i) {
        ArraySequence<T> a(data,i * 10000);
        unsigned int start = clock();
        a.InsertSort(cmp_);
        unsigned int finish = clock();
        out << finish - start << ' ';
    }
    std::cerr << "Insert is done\n";
}

template<typename T>
void ListCountingSort(T max_value = 100000,int max_size = 100000){
    T data[max_size];
    for (int i = 0; i < max_size; ++i) {
        data[i] = rand() % max_value;
    }
    merge_sort(data,0,max_size);
    std::ofstream out;
    out.open("ListCountingSort.txt");
    for (int i = 1; i <= 10; ++i) {
        ArraySequence<T> a(data,i * 10000);
        unsigned int start = clock();
        a.CountingSort();
        unsigned int finish = clock();
        out << finish - start << ' ';
        std::cout << IsSorted(&a,cmp) << std::endl;
    }
    std::cerr << "Counting is done\n";
}