#include <iostream>

template<typename T>
class ContainerSeq
{
    public:
        ContainerSeq(): _size(0), _capacity(5) {
            T* data = new T[_capacity];
            _data = data;
        }
    
        ~ContainerSeq() {delete[] _data;}
    
        void push_back(const T& value) {
            if(_size >= _capacity)
            {
                addCapacity();
            }
            _data[_size] = value;
            _size++;
        }

        void push_front(const T& value)
        {
            if(_size >= _capacity)
            {
                addCapacity();
            }

            for(size_t i = _size; i > 0; i--)
                {
                    _data[i] = _data[i - 1];    
                }
                _data[0] = value;
                ++_size;
                }

        void pop_back()
        {
            erase(GetSize() - 1);
        }

        void pop_front()
        {
            erase(0);
        }

        void insert(size_t index, const T& value)
        {
            if(index > _size || index < 0)
                {
                    throw std::out_of_range("Index out of range");
                }

            if(_size >= _capacity)
            {
                addCapacity();
            }
            // move positions starting from index to 1
            for(size_t i = _size; i > index; i--)
            {
                _data[i] = _data[i - 1];
            }
            _data[index] = value;
            _size++;
        }
    
    // GetSize
        size_t GetSize() const
        {
            return _size;
        }        
    // index operator []
        const T& operator[](int index) const
        {
            if(index >= _size)
            {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }
    // erase by index
        void erase(int index)
        {
            if(index >= _size || index < 0)
            {
                throw std::out_of_range("Index out of range");
            }

        for (size_t i = index; i < _size; ++i) 
        {
            _data[i] = _data[i + 1];
        }
        _size--;
        }
    // move constructor
        ContainerSeq(ContainerSeq&& other) noexcept {
            if(this != &other)
            {
                _data = nullptr;
                _data = other._data;
                _size = other._size;
                _capacity = other._capacity;
                other._size = 0;
                other._capacity = 0;
            }
        }
    //mode assignment operator
        ContainerSeq& operator=(ContainerSeq&& other) noexcept {
            if(this != &other)
            {
                _data = nullptr;
                _data = other._data;
                _size = other._size;
                _capacity = other._capacity;
                other._size = 0;
                other._capacity = 0;               
            }
            return *this;
        }

    struct Iterator
    {
        public:
            Iterator(T* ptr): _ptr(ptr) {};
            
            T& operator*() const {return *_ptr;}

            T* operator->() {return _ptr;}

            Iterator& operator++() {
                _ptr++;
                return *this;
            }

            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            Iterator& operator--() {
                _ptr--;
                return *this;
            }

            bool operator==(const Iterator& other) const {return _ptr == other._ptr;}
            bool operator!=(const Iterator& other) const {return _ptr != other._ptr;}
            
        private:
            T* _ptr;
    };

        Iterator begin() {return Iterator(_data);}
        Iterator end() {return Iterator(_data + _size - 1);}

    private:
        T* _data;
        size_t _size;
        size_t _capacity;
        void addCapacity()
        {
            _capacity *= 2;
            T* newData = new T[_capacity];
            for(auto i = 0; i < _size; i++)
            {
                newData[i] = _data[i];
            }
            delete[] _data;
            _data = newData;
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const ContainerSeq<T>& cont)
    {
        for(auto i = 0; i < cont.GetSize(); i++)
        os << cont[i] << " ";
        return os;
    }