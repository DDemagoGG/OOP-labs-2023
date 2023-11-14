#include "allocator.hpp"
#include <memory>

template <class T, class Allocator = std::allocator<T>>
class Queue{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
private:
    Allocator alloc;
    T* _data;
    size_t _size, _capacity;
public:
    Queue() : _data{nullptr}, _size{0}, _capacity{0} {}
    Queue(const Queue & other){
        _size = other._size;
        _capacity = other._capacity;
        _data = alloc.allocate(other._capacity);
        for (size_t i = 0; i < _size; i++){
            _data[i] = other._data[i];
        }
    }
    Queue(const std::initializer_list<T> &l){
        _size = l._size();
        _capacity = _size * 2;
        size_t i = 0;
        _data = alloc.allocate(_capacity);
        for(auto el : l){
            _data[i] = el;
        }
    }
    Queue(Queue && other){
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;
        other._size = 0;
        other._data = nullptr;
        other._capacity = 0;
    }
    ~Queue(){}
    value_type front(){
        return _data[0];
    } 
    value_type back(){
        return _data[_size - 1];
    }
    void pop(){
        _size--;
        for (size_t i = 0; i < _size; i++){
            _data[i] = _data[i + 1];
        }
    }
    void reserve(size_t n){
        if (n > _capacity){
            pointer new__data = alloc.allocate(n);
            if (_capacity != 0){
                for (size_t i = 0; i < _size; i++){
                    new__data[i] = _data[i];
                }
                alloc.deallocate(_data, _capacity);
            }
            _capacity = n;
            _data = new__data;
        }
    }
    void push(value_type n){
        if (_size + 1 >= _capacity){
            reserve((_capacity + 1) * 2);
        }
        _data[_size++] = n;
    }
    size_t size(){
        return _size;
    }
    int empty(){
        return (size == 0);
    }
};