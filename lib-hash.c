#include "header.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

int main(){

    headerScript();

    // Initialize libsodium
    if (sodium_init() < 0) {
        printf("libsodium initialization failed!\n");
        return 0;
    }

    int opt;

    printf("Chose which hashing method you require to use.\n");
    printf("Opt your option (1-4) : ");
    if(scanf("%d", &opt) != 1) {
        printf("Invalid input!");
        return 1;
    }

    switch (opt)
    {
    case 1: hash_BLAKE2b(); break;
    case 2: hash_sha256(); break;
    case 3: hash_sha512(); break;
    case 4: printf("Script terminated!"); return 0;
    default: printf("Invalid option!"); return 1;
    }
    
    return 0;
}