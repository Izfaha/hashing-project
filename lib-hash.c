#include <sodium.h>
#include <sodium/crypto_generichash.h>
#include <sodium/crypto_hash_sha256.h>
#include <stdio.h>
#include <string.h>

// Global variable

unsigned char hash[crypto_generichash_BYTES];
unsigned char sha256[crypto_hash_sha256_BYTES]; 
unsigned char sha512[crypto_hash_sha512_BYTES];

// Declare built-in function

void headerScript();
void hashHexadecimal(const char *input[]);

// Main function 

int main(){

    headerScript();

    // Initialize libsodium
    if (sodium_init() < 0) {
        printf("libsodium initialization failed!\n");
        return 0;
    }
    
    

    return 0;
}

//  built-in function

void headerScript() {
    printf("=============================================================================\n");
    printf("Hashing Script Using LibSodium in C Language\n");
    printf("=============================================================================\n");
}

void hashHexadecimal(const char *input[]){
    printf("Input your message you need to hash : "); scanf(input);

    /* size_t = an unsigned integer type used to represent the size of object in bytes 
        strlen() = calculate the lenght of a given string*/
    size_t input_len = strlen(input); 
    
    // 
    crypto_generichash(input, sizeof(input), (const unsigned char *)input, input_len, NULL, 0); 
}

