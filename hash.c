#include <sodium.h>
#include <stdio.h>

int main() {
    // Initialize libsodium
    if (sodium_init() < -1) {
        printf("libsodium initialization failed!\n");
        return 0;
    }

    // Define the message to hash
    const unsigned char *message = (const unsigned char *) "Arbitrary data to hash";
    size_t message_len = 22; // Length of the massage (including null terminator)

    // Declare a buffer to store the hash
    unsigned char hash[crypto_generichash_BYTES]; // Default hash size (32 bytes)

    // Compute the hash using BLAKE2b
    crypto_generichash(hash, sizeof hash, message, message_len, NULL, 0); // No key used

    // Print the hash in hexadecimal format
    printf("Hash: ");
    for (size_t i = 0; i < sizeof hash; i++) {
        printf("%02x", hash[i]); // Print each byte in hex
    }
    printf("\n");

    return 0; // Successful execution
}
