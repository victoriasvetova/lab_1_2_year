#include "Sequences.h"
#include <map>
template<typename T>
class ISorter{
public:
    virtual void Sort(bool(*cmp)(const T&,const T&),Sequence<T>* seq,int first = 0,int second = 0) = 0;
};

template<typename T>
class ICountingSort : public ISorter<T>{
public:
    void Sort(bool(*cmp)(const T&,const T&),Sequence<T>* seq,int first = 0,int second = 0) override{
        std::map<const T,int> count;//создаем словарь отображений из данных,имеющих тип нашей последовательности,в целые числа
        for (int i = 0; i < seq->GetLength(); ++i) {//подсчитываем с помощью словаря количество каждого встречающегося элемента в полседовательности
            ++count[seq->Get(i)];
        }

        int index = 0;//с помощью этого индекса мы перебираем и перезаписываем элементы исходной последовательности
        for(std::pair<const T,int>& item : count){//перезаписываем исходную последовательность с помощью словаря
            while(item.second != 0){
                seq->Get(index) = item.first;
                item.second--;
                index++;
            }
        }
    }
};

template<typename T>
class IMergeSort : public ISorter<T>{
public:
    void Sort(bool(*cmp)(const T&,const T&),Sequence<T>* seq,int first = 0,int second = 0) override{
        if(second <= first)
            return;
        int mid = first + (second-first)/2;
        merge_sort(cmp,seq,first,mid);
        merge_sort(cmp,seq,mid+1,second);
        merge(cmp,seq,first,second);
    }
};

template<typename T>
class IInsertSort : public ISorter<T>{
public:
    void Sort(bool(*cmp)(const T&,const T&),Sequence<T>* seq,int first = 0,int second = 0) override{
        for (int i = 1; i < seq->GetLength(); ++i) {
            int k = i;
            while(k > 0 && cmp(seq->Get(k - 1), seq->Get(k))){
                T tmp = seq->Get(k - 1);
                seq->Get(k - 1) = seq->Get(k);
                seq->Get(k) = tmp;
                k--;
            }
        }
    }
};