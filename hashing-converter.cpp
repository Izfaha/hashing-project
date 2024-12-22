/*
    coded by Fa'iz Maulana Habibi, email = rasberry006@gmail.com
    this project aims to convert text, num, and special character to hash
    with proper algoritm
*/

#include <iostream>
#include <string>
#include <functional>
#include <sodium.h>
using namespace std;

struct hashing{
    string textConverter;
    string hashConverter;
};

int main(){
    if(sodium_init() < 0) {
        return 1;
    } // Initialize libsodium

    // constant-time for equality
    int sodium_memcmp(const void * const b1_, const void * const b2_, size_t len);

}