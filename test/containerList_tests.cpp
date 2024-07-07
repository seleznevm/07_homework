#include <iostream>
#include "containerList.hpp"
#include <gtest/gtest.h>

TEST(ContList, PushBack)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 10; i++)
    {
        cont.push_back(i);
    }
    //Assert
    cont.push_back(35);
    //Act
    ASSERT_EQ(cont[10], 35);
}

TEST(ContList, PushFront)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 10; i++)
    {
        cont.push_back(i);
    }
    //Assert
    cont.push_front(35);
    //Act
    ASSERT_EQ(cont[0], 35);
}

TEST(ContList, Insert)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
    {
        cont.push_back(i);
    }
    //Assert
    cont.insert(1, 35);
    //Act
    ASSERT_EQ(cont[1], 35);
}

TEST(ContList, Pop_back)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
    {
        cont.push_back(i);
    }
    //Act
    cont.pop_back();
    //Accert
    ASSERT_EQ(cont.GetSize(), 4);
    for(int i{0}; i < 4; i++)
    {
        ASSERT_EQ(cont[i], i);   
    }
}
TEST(ContList, Pop_front)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
        cont.push_back(i);
    //Act
    cont.pop_front();
    //Assert
    ASSERT_EQ(cont[0], 1);
}

TEST(ContList, GetSize)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
        cont.push_back(i);
    size_t containerSize{0};
    //Act
    containerSize = cont.GetSize();
    //Assert
    ASSERT_EQ(containerSize, 5);    
}

TEST(ContList, Erase)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
        cont.push_back(i);
    //Act
    cont.erase(0);
    //Assert
    ASSERT_EQ(cont[0], 1);    
}

TEST(ContList, Clear)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
        cont.push_back(i);
    //Act
    cont.clear();
    //Assert
    ASSERT_EQ(cont.GetSize(), 0);    
}

TEST(ContList, opeartorSqrBracket)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(int i{0}; i < 5; i++)
        cont.push_back(i);
    int cont2;
    //Act
    cont2 = cont[2];
    //Assert
    ASSERT_EQ(cont2, 2);    
}

TEST(ContList, sumOfCont)
{
    //Arrange
    ContList::ContainerList<int> cont;
    for(size_t i = 0; i < 5; i++)
        cont.push_back(i);
    int sum = 0;
    //Act
    for(size_t i = 0; i < 5; i++)
        sum = sum + cont[i];
    //Assert
    ASSERT_EQ(sum, 10);
}

TEST(ContList, copy)
{
    //Arrange
    ContList::ContainerList<int> cont1;
    for(size_t i = 0; i < 5; i++)
        cont1.push_back(i);    
    //Act
    ContList::ContainerList<int> cont2(cont1);
    //Assert
    for(size_t i = 0; i < 5; i++)
        {
            ASSERT_EQ(cont1[i], cont2[i]);
        }
}

TEST(ContList, move)
{
    //Arrange
    ContList::ContainerList<int> cont1;
    ContList::ContainerList<int> cont2;
    for(size_t i = 0; i < 5; i++)
        cont1.push_back(i);  
    //Act
    cont2 = std::move(cont1);
    //Assert
    ASSERT_EQ(cont1.GetSize(), 0);
    ASSERT_EQ(cont2.GetSize(), 5);
    for(size_t i = 0; i < 5; i++)
        ASSERT_EQ(cont2[i], i);
}
