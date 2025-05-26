#include <iostream>
#include <vector>

#include "structures.hpp"
#include "algos.hpp"
#include "hash_table.hpp"

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

void hash_table_test()
{
    algos::hash_table<int, std::string> table;
    table.insert(1, "1");
    table.insert(2, "2");
    table.insert(3, "3");
    table.insert(4, "4");
    table.insert(5, "5");
    table.insert(6, "6");
    table.insert(7, "7");
    table.insert(8, "8");
    std::cout << table.get(5) << std::endl;
    std::cout << table.get(7) << std::endl;
    std::cout << table.get(8) << std::endl;
    std::cout << table.get(3) << std::endl;
}

int main()
{
    selection_sort_test();
    std::cout << std::endl;
    fib_test(10);
    std::cout << std::endl;
    qsort_test();
    std::cout << std::endl;
    once_linked_list_test();
    std::cout << std::endl;
    double_linked_list_test();
<<<<<<< HEAD
    hash_table_test();
=======
    std::cout << std::endl;
>>>>>>> 07ee2db52041b5123917447c833fcc9c051526a5
    return 0;
}
