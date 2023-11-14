#include <iostream>
#include <array>


template <class T>
class Allocator{
public:
    static constexpr size_t max_count = 500000;
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
    template< class U >
    struct rebind{
        typedef Allocator<U> other;
    };
private:
    char * used_blocks;
    std::array<void *, max_count> free_blocks;
    size_t free_count;
public:
    Allocator(){
        used_blocks = (char *)malloc(sizeof(value_type) * max_count);
        for(size_t i = 0; i < max_count; i++){
            free_blocks[i] = used_blocks + i * sizeof(value_type);
        }
        free_count = max_count;
    }
    ~Allocator(){
        delete used_blocks;
        used_blocks = nullptr;
    }
    pointer allocate(size_t n){
        pointer res = nullptr;
        if (free_count >= n){
            res = (pointer)free_blocks[free_count - n];
            free_count -= n;
        }
        return res;
    }
    void deallocate(pointer p, size_t n){
        size_t p_size = sizeof(*p) / sizeof(value_type);
        if (n == p_size){
            free_blocks[free_count] = p;
            p = nullptr;
            free_count += n;
        }
    }
    template <typename U, typename... Args>
    void construct(U *p, Args &&...args){
        new (p) U(std::forward<Args>(args)...);
    }
    void destroy(pointer p){
        p->~T();
    }
};