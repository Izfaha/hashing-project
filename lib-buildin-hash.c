#include "header.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

void headerScript(void) {
    printf("=============================================================================\n");
    printf("||Hashing Script Using LibSodium in C Language.\t\t\t\t    #\n");
    printf("||by Izfaha.\n");
    printf("||This project is for learning purpose.\n");
    printf("=============================================================================\n\n");
    printf("Hashing Method :\n");
    printf("1. BLAKE2b\n");
    printf("2. SHA256\n");
    printf("3. SHA512\n");
    printf("4. Exit\n");
}

void hash_BLAKE2b(void){
    // Local buffer for input with safe size limit
    const unsigned char inputMsg[1024];

    printf("Input your message you need to hash : "); 
    if(scanf("%1024s", inputMsg) != 1) {
        printf("Error reading input!\n");
        return;
    }

    /* size_t = an unsigned integer type used to represent the size of object in bytes 
        strlen() = calculate the lenght of a given string*/
    size_t input_len = strlen((const unsigned char *)inputMsg); 
    
    // Hashing variable (local scope)
    unsigned char blake2b_hash[crypto_generichash_BYTES];

    // The inputMsg will be hashed via crypto_generichash
    crypto_generichash(blake2b_hash, sizeof(blake2b_hash), inputMsg, input_len, NULL, 0); 

    // Print the hash
    printf("\nBLAKE2b Hash : ");
    for(size_t i; i < sizeof blake2b_hash; i++) {
        printf("%02x", blake2b_hash[i]);
    }
    printf("\n");
}

void hash_sha256(void) {
    const unsigned char inputMsg[1024];

    printf("Input your message you need to hash : ");
    if(scanf("%1024s", inputMsg) != 1) {
        printf("Error reading input!\n");
        return;
    }

    size_t input_len = strlen((const unsigned char *)inputMsg);

    unsigned char sha256_hash[crypto_hash_sha256_BYTES];

    printf("\nSHA256 Hash : ");
    for(size_t i = 0; i < sizeof(sha256_hash); i++) {
        printf("%02x", sha256_hash[i]);
    }
    printf("\n");
}

void hash_sha512(void) {
    const unsigned char inputMsg[1024];

    printf("Input your message you need to hash : ");
    if(scanf("%1024s", inputMsg) != 1) {
        printf("Error reading input!\n");
        return;
    }

    size_t input_len = strlen((const unsigned char *)inputMsg);

    unsigned char sha512_hash[crypto_hash_sha512_BYTES];

    printf("\nSHA256 Hash : ");
    for(size_t i = 0; i < sizeof(sha512_hash); i++) {
        printf("%02x", sha512_hash[i]);
    }
    printf("\n");
}