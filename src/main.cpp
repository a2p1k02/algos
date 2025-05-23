#include <iostream>
#include <vector>

#include "structures.hpp"

import algos;

void selection_sort_test()
{
    std::vector unsorted = {1, 304, 208, 16, 256, 512, 6, 725};

    for (const auto i : unsorted) {
        std::cout << i << std::endl;
    }

    const auto sorted = algos::selection::selection_sort(unsorted);

    std::cout << std::endl;
    for (const auto i : sorted) {
        std::cout << i << std::endl;
    }
}

void fib_test(const int n)
{
    std::cout << algos::fib(n) << "\n";
}

void qsort_test()
{
    std::vector unsorted = {1, 304, 208, 16, 256, 512, 6, 725};

    for (const auto i : unsorted) {
        std::cout << i << std::endl;
    }

    algos::quick_sort(unsorted);

    std::cout << std::endl;
    for (const auto i : unsorted) {
        std::cout << i << std::endl;
    }
}

void once_linked_list_test()
{
    structures::once_linked::linked_list<int> list;
    list.push_back(35);
    list.push_back(15);
    list.push_back(25);
    list.push_back(125);
    list.push_back(45);
    list.print();
    list.pop_front();
    list.pop_back();
    list.print();
}

void double_linked_list_test()
{
    structures::double_linked::linked_list<int> list;
    list.push_front(25);
    list.push_back(55);
    list.push_front(125);
    list.push_back(225);
    list.push_front(625);
    list.erase(3);
    list.print();
    list.insert(325, 4);
    list.print();
}

int main()
{
    //selection_sort_test();
    //fib_test(100);
    //qsort_test();
    //once_linked_list_test();
    double_linked_list_test();
    return 0;
}
