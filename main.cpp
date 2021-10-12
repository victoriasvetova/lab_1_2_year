#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "SimpleTests.h"
#include "Time.h"

int main() {
    TestAll();

    std::cout << "Enter size of sequence :\n";
    int N;
    std::cin >> N;

    double data[N];
    char answer;
    Sequence<double> *tmp;

    std::cout << "Generate random nums ? (y / n)\n";
    std::cin >> answer;
    if (answer == 'y') {
        for (int i = 0; i < N; ++i) {
            data[i] = rand() % 1000;
        }
    } else {
        std::cout << "Enter " << N << " nums :\n";
        double tmp_num;
        for (int i = 0; i < N; ++i) {
            std::cin >> tmp_num;
            data[i] = tmp_num;
        }
    }

    std::cout << "Choose type of sequence :\n1 - ArraySequence\n2 - LinkedListSequence :\n";
    std::cin >> answer;
    if (answer == '1')
        tmp = new ArraySequence<double>(data, N);
    else
        tmp = new LinkedListSequence<double>(data, N);

    std::cout << "Choose type of sorting :\n1 - MergeSort\n2 - CountingSort\n3 - InsertSort :\n";
    std::cin >> answer;
    if(answer == '1'){
        tmp->MergeSort(cmp);
    }
    else{
        if(answer == '2'){
            tmp->CountingSort();
        }
        else{
            if(answer == '3')
                tmp->InsertSort(cmp_);
        }
    }
    std::cout << "Your sorted sequence :";
    tmp->Print();
    return 0;
}
