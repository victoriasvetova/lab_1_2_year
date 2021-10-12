#include "HelpFunctions.h"

template<typename T>
bool IsSorted(Sequence<T>* sequence,bool(*cmp)(const T&,const T&)){
    int size = sequence->GetLength();
    for (int i = 0; i < size - 1; ++i) {
        if(!cmp(sequence->Get(i),sequence->Get(i + 1)))
            return false;
    }
    return true;
}

void TestAll(){
    int m[10000];
    int max = 20;
    int size = 20;
    for (int i = 0; i < 10000; ++i) {
        m[i] = rand() % max;
    }
    bool flag = false;
    {
        LinkedListSequence<int> a(m,size);
        a.InsertSort(cmp_);
        flag = IsSorted(&a,cmp);
        if(!flag){
            std::cerr << "Terminate InsertSort LinkedListSequence";
            exit(0);
        }
    }

    {
        ArraySequence<int> a(m,size);
        a.InsertSort(cmp_);
        flag = IsSorted(&a,cmp);
        if(!flag){
            std::cerr << "Terminate InsertSort ArraySequence";
            exit(0);
        }
    }

    {
        LinkedListSequence<int> a(m,size);
        a.MergeSort(cmp);
        flag = IsSorted(&a,cmp);
        if(!flag){
            std::cerr << "Terminate MegreSort LinkedListSequence";
            exit(0);
        }
    }

    {
        ArraySequence<int> a(m,size);
        a.MergeSort(cmp);
        flag = IsSorted(&a,cmp);
        if(!flag){
            std::cerr << "Terminate MegreSort ArraySequence";
            exit(0);
        }
    }

    {
        LinkedListSequence<int> a(m,size);
        a.CountingSort();
        flag = IsSorted(&a,cmp);
        if(!flag){
            std::cerr << "Terminate CountingSort LinkedListSequence";
            exit(0);
        }
    }

    {
        ArraySequence<int> a(m,size);
        a.CountingSort();
        flag = IsSorted(&a,cmp);
        if(!flag){
            std::cerr << "Terminate CountingSort ArraySequence";
            exit(0);
        }
    }
    std::cerr << "All tests passed\n";

}