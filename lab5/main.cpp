#include <map>
#include "queue.hpp"

int main(){
    Queue<std::string> q;
    q.push(std::string("abc"));
    q.push(std::string("def"));
    std::cout << q.front() << ' ' << q.back() << '\n';
    return 0;
}