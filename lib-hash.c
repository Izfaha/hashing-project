#include <sodium.h>
#include <sodium/crypto_generichash.h>
#include <sodium/crypto_hash_sha256.h>
#include <stdio.h>

// Global variable

unsigned char hash[crypto_generichash_BYTES];
unsigned char hex[crypto_hash_sha256_BYTES]; 

// Declare built-in function

void headerScript();

int main(){

    headerScript();

    // Initialize libsodium
    if (sodium_init() < 0) {
        printf("libsodium initialization failed!\n");
        return 0;
    }
    
    

    return 0;
}

// Library for main function

void headerScript() {
    printf("Cryptography Project");
}

void hashHexadecimal(char inputMsg[]){

}

