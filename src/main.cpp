#include <iostream>
#include <vector>

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

int main()
{
    //selection_sort_test();
    //fib_test(100);
    //qsort_test();
    return 0;
}
