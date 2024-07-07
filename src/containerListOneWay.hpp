#include <iostream>

namespace ListOneWay {

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
class ContainerListOneWay{
    public: 
    ContainerListOneWay(): size(0), head(nullptr), tail(nullptr) {};

    ~ContainerListOneWay() {
        Node<T>* current = head;
        while(current != nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

    }

    int GetSize() {return this->size;}

    const T& operator[](int index) const
    {
        if(index > size || index < 0)
        {
            throw std::out_of_range("The index is out of range\n");
        }
        Node<T>* current = head; // add check head existence?
        for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
        return current->data;
    }

    void push_back(const T& value)
    {
        Node<T>* new_node = new Node<T>;
        new_node->data = value;
        new_node->next = nullptr;
        if(size == 0)
        {
            head = new_node;
        }
        else{
            Node<T>* current = head;
            while(current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = new_node;
        }
        size++;
    }

    void push_front(const T& value)
    {
        Node<T>* new_node = new Node<T>;
        new_node->data = value;
        new_node->next = head;
        head = new_node;
        size++;
    }

    void insert(int index, const T& value)
    {
        if(index > size || index < 0)
        {
            throw std::out_of_range("The index is out of range\n");
        }       
        Node<T>* new_node = new Node<T>;
        new_node->data = value;
        if(index == 0)
            {
                new_node->next = head;
                head = new_node;
            }   
        else {
            Node<T>* current = head;
            for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
        size++;
    }

    void erase(int index)
    {
        if(index > size || index < 0)
        {
            throw std::out_of_range("The index is out of range\n");
        }        
        if(index == 0)
        {
            Node<T>* temp = head;
            head = temp->next;
            delete temp;
        }
        else{
        Node<T>* current = head;
        for(int i = 0; i < index; i++)
        {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        }
        size--;
    }
    
    private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
    size_t capacity;
};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, ContainerListOneWay<T>& cont)
    {
        for(auto i = 0; i < cont.ContainerListOneWay<T>::GetSize(); i++)
        {
            os << cont[i] << " ";
        }
        return os;
    }
}