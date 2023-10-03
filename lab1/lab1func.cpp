#include "lab1header.hpp"

string result(string input){
    for(int i = 0; i < input.size(); i++){
        if (input[i] == 'a'){
            input[i] = 'b';
        } else if (input[i] == 'b'){
            input[i] = 'a';
        }
    }
    return input;
}
