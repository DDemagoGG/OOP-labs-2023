#include "Five.hpp"

Five::Five() : size{0}, num{nullptr}{   
}

unsigned char* Five::getNumber() const{
    return  num;
}

int Five::getSize() const{
    return size;
}

Five::Five(const std::string& num){
    this->num = new unsigned char[num.size()];
    size = num.size();
    size_t i = num.size() - 1;
    for (unsigned char c : num) {
        if ((0 > (c - '0')) or ((c - '0') >= 5)) throw std::logic_error("number must be quinary");
        this->num[i] = c;
        i--;
    }
}

void Five::print() const{
    if (size > 0){
        for (int i = size - 1; i >= 0; i--){
            std::cout << num[i];
        }
    }
}

Five::Five(const std::initializer_list<unsigned char> &l){
    num = new unsigned char[l.size()];
    size_t i = l.size() - 1;
    size = 0;
    for (unsigned char c : l){
        if ((0 > (c - '0')) or ((c - '0') >= 5)){
            throw std::logic_error("number must be quinary");
        }
        num[i--] = c;
        size++;
    }
}

Five::~Five(){
    if (size > 0){
        delete[] num;
        num = nullptr;
        size = 0;
    }
}

Five::Five(const Five& other){
    size = 0;
    num = new unsigned char[other.size];
    for (int i = 0; i < other.size; i++){
        num[i] = other.num[i];
        size++;
    }
}

Five& Five::operator=(const Five& other){ 
    if (&other != this){
        delete[] num;
        size = other.size;
        num = new unsigned char[size];
        for (int i = 0; i < size; i++){
            num[i] = other.num[i];
        } 
    }
    return *this;
}

Five Five::operator+(const Five& other) const{
    int len = std::max(other.size, size) + 1;
    std::string res(len, '0');
    int buf = 0;
    for (int i = 0; i < len; i++){
        if (i >= size){
            if (i >= other.size){
                res[i] = buf + '0';
                break;
            }
            buf += other.num[i] - '0';
        } else if(i >= other.size){
            buf += num[i] - '0';
        } else{
            buf += (other.num[i] - '0') + ( num[i] - '0');
        }
        res[i] = (buf % 5) + '0';
        buf /= 5;
    }
    if (res[len - 1] == '0'){
        res.erase(len - 1, 1);
    }
    std::reverse(res.begin(), res.end());
    return Five{res};
}

int Five::operator==(const Five& other) const{
    int flag = 1;
    if (other.size == size){
        for (int i = 0; i < size; i++){
            if (other.num[i] != num[i]){
                flag = 0;
                break;
            }
        }
    } else{
        flag = 0;
    }
    if (flag){
        return 1;
    }
    return 0;
}

int Five::operator<(const Five& other) const{
    if (*this != other){
        if (size < other.size){
            return 1;
        } else if (size > other.size){
            return 0;
        } else{
            for (int i = size - 1; i >= 0; i--){
                if (num[i] < other.num[i]){
                    return 1;
                } else if (num[i] > other.num[i]){
                    return 0;
                }
            }
        }
    }
    return 0;
}

int Five::operator>(const Five& other) const{
    if ((*this < other) or (*this == other)){
        return 0;
    }
    return 1;
}

int Five::operator != (const Five& other) const{
    if (*this == other){
        return 0;
    }
    return 1;
}

Five Five::operator-(const Five& other) const{
    if (*this < other){
        throw std::logic_error("result can't be negative");
    } else if (*this == other){
        return Five{'0'};
    }
    std::string res(size, '0');
    int buf = 0;
    for (int i = 0; i < size; i++){
        if (i >= other.size){
            buf += num[i] - '0';
        } else{
            buf += num[i] - '0' - (other.num[i] - '0');
        }
        if (buf < 0){
            res[i] = (buf + 5) + '0';
            buf = -1;
        } else{
            res[i] = buf + '0';
            buf = 0;
        }
    }
    while (res[res.size() - 1] == '0'){
        res.erase(res.size() - 1, 1);
    }
    std::reverse(res.begin(), res.end());
    return Five{res};
}   

int Five::operator >= (const Five& other) const{
    if (*this < other){
        return 0;
    }
    return 1;
}

int Five::operator <= (const Five& other) const{
    if (*this > other){
        return 0;
    }
    return 1;
}
