#include <iostream>
#include "containerSeq.hpp"
#include "containerList.hpp"
#include "containerListOneWay.hpp"

void workWithContainerSeq();
void workWithContainerList();
void workWithContainerListOneWay();

int main()
{
    std::cout << "\nSEQUENTIAL CONTAINER:\n";
    workWithContainerSeq();
    std::cout << "\nONE WAY LINKED CONTAINER:\n";
    workWithContainerListOneWay();
    std::cout << "\nDOUBLE-LINKED CONTAINER:\n";
    workWithContainerList();
    return 0;
}




void workWithContainerSeq() {
    ContainerSeq<int> contSeq;
    for(int i{0}; i < 10; i++)
    {
        contSeq.push_back(i);
    }
    std::cout << "Created a sequentional container with values:\n";
    std::cout << contSeq << std::endl;
    std::cout << "Size of container: " << contSeq.GetSize() << std::endl;
    contSeq.erase(2);
    // 0 1 3 4 5 6 7 8 9
    contSeq.erase(3);
    // 0 1 3 5 6 7 8 9
    contSeq.erase(4);
    // 0 1 3 5 7 8 9
    std::cout << "Delete 3,5 and 7 element.\n Now the container contain of: " << contSeq << std::endl;
    contSeq.push_front(10);
    std::cout << "Add 10 to the front of the container, now container has: " << contSeq << std::endl;
    contSeq.insert(4, 20);
    std::cout << "Add 20 into the middle of the container, now container has: " << contSeq << std::endl;
    contSeq.push_back(30);
    std::cout << "Add 30 at the end of container, now it consists of: " << contSeq << std::endl;
    contSeq.pop_back();
    std::cout << "Pop_back(), now container has: " << contSeq << std::endl;
}

void workWithContainerListOneWay() {
    ListOneWay::ContainerListOneWay<int> contList;
    for(int i{0}; i < 10; i++)
    {
        contList.push_back(i);
    }
    std::cout << "Created a one way list container with values:\n";
    std::cout << contList << std::endl;
    std::cout << "Size of container: " << contList.GetSize() << std::endl;
    contList.erase(2);
    // 0 1 3 4 5 6 7 8 9
    contList.erase(3);
    // 0 1 3 5 6 7 8 9
    contList.erase(4);
    // 0 1 3 5 7 8 9
    std::cout << "Delete 3,5 and 7 element.\nNow the container contain of: " << contList << std::endl;
    contList.push_front(10);
    std::cout << "Add 10 to the front of the container, now container has: " << contList << std::endl;
    contList.insert(4, 20);
    std::cout << "Add 20 into the middle of the container, now container has: " << contList << std::endl;
    contList.push_back(30);
    std::cout << "Add 30 at the end of container, now it consists of: " << contList << std::endl;
}

void workWithContainerList()
{
    ContList::ContainerList<int> contList;
for(int i{0}; i < 10; i++)
    {
        contList.push_back(i);
    }
    std::cout << "Created a sequentional container with values:\n";
    std::cout << contList << std::endl;
    std::cout << "Size of container: " << contList.GetSize() << std::endl;
    contList.erase(2);
    // 0 1 3 4 5 6 7 8 9
    contList.erase(3);
    // 0 1 3 5 6 7 8 9
    contList.erase(4);
    // 0 1 3 5 7 8 9
    std::cout << "Delete 3,5 and 7 element.\n Now the container contain of: " << contList << std::endl;
    contList.push_front(10);
    std::cout << "Add 10 to the front of the container, now container has: " << contList << std::endl;
    contList.insert(4, 20);
    std::cout << "Add 20 into the middle of the container, now container has: " << contList << std::endl;
    contList.push_back(30);
    std::cout << "Add 30 at the end of container, now it consists of: " << contList << std::endl;
    contList.pop_back();
    std::cout << "pop_back function, now container consist of: " << contList << std::endl;
    contList.pop_front();
    std::cout << "pop_front function, now container consist of: " << contList << std::endl;
}
