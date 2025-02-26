#include <sodium.h>
#include <sodium/crypto_generichash.h>
#include <sodium/crypto_hash_sha256.h>
#include <stdio.h>
#include <string.h>

// Global variable

const unsigned char *inputMsg;

unsigned char hash[crypto_generichash_BYTES];
unsigned char sha256[crypto_hash_sha256_BYTES]; 
unsigned char sha512[crypto_hash_sha512_BYTES];

// Declare built-in function

void headerScript();
void hashHexadecimal();

// Main function 

int main(){

    headerScript();

    // Initialize libsodium
    if (sodium_init() < 0) {
        printf("libsodium initialization failed!\n");
        return 0;
    }

    hashHexadecimal(inputMsg);


    return 0;
}

//  built-in function

void headerScript() {
    printf("=============================================================================\n");
    printf("Hashing Script Using LibSodium in C Language\n");
    printf("=============================================================================\n");
}

void hashHexadecimal(const unsigned char *inputMsg){
    printf("Input your message you need to hash : "); scanf("%s", inputMsg);

    /* size_t = an unsigned integer type used to represent the size of object in bytes 
        strlen() = calculate the lenght of a given string*/
    size_t input_len = strlen(inputMsg); 
    
    // The inputMsg will be hashed via crypto_generichash
    crypto_generichash(hash, sizeof(hash), inputMsg, input_len, NULL, 0); 

    // Print the hash
    printf("Hash : ");
    for(size_t i; i < sizeof hash; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

