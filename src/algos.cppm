export module algos;

#include <algorithm>
#include <vector>

namespace algos
{
    namespace selection
    {
        int find_smallest(const std::vector<int>& array)
        {
            int smallest = array[0];

            for (const auto i : array) {
                if (smallest > i) {
                    smallest = i;
                }
            }

            return smallest;
        }

        export auto selection_sort(std::vector<int>& array)
        {
            std::vector<int> sorted_array;

            for (auto i : array) {
                auto smallest = find_smallest(array);
                sorted_array.push_back(smallest);
                array.erase(std::ranges::find(array, smallest));
            }

            return sorted_array;
        }
    }

    export void quick_sort(std::vector<int>& array, const int left = 0, int right = -1)
    {
        if (right == -1) right = array.size() - 1;
        if (left >= right) return;

        int start = left, end = right;
        const int pivot = array[(left + right) / 2];

        do {
            while (array[start] < pivot) start++;
            while (array[end] > pivot) end--;

            if (start <= end) {
                std::swap(array[start++], array[end--]);
            }
        } while (start <= end);

        quick_sort(array, left, end);
        quick_sort(array, start, right);
    }

    export unsigned int fib(const int n)
    {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
}