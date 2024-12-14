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
        
    } // Initialize libsodium

    long hash_converter;
    struct hashing h_converter;
    cout << "The hash can be letter, number, or special cahracter.";
    cout << "Place the text here : "; cin >> h_converter.textConverter;
    hash_converter = sodium_base642bin(h_converter.textConverter);
    cout << "Your hashing text is : " << h_converter.hashConverter << endl;
}