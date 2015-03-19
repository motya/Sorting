#include <iostream>
#include <algorithm>
#include <vector>

int main(int,char**)
{
    int array[] = {1,3456, 45, 2145,25,5784, 37, 06};
    std::vector<int> elements(array, array+sizeof array / sizeof(array[0]));

    std::cout << "Input: " << std::endl;
    for(std::vector<int>::iterator
        it = elements.begin(); it != elements.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::make_heap(elements.begin(), elements.end());

    std::cout << "Conversion to heap: " << std::endl;
    for(std::vector<int>::iterator
        it = elements.begin(); it != elements.end(); ++it) {
        std::cout << *it << std::endl;
    }

    int buffer = 0;
    const size_t length = elements.size();
    size_t restLength = length;

    while (restLength > 1) {
        std::make_heap(elements.begin(), elements.begin() + restLength);
        buffer = *(elements.begin() + restLength-1);
        *(elements.begin() + restLength-1) = elements.front();
        elements.front() = buffer;
        restLength--;
    }

    std::cout << "Sorting: " << std::endl;
    for(std::vector<int>::iterator
        it = elements.begin(); it != elements.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
