#include <sodium.h>
#include <iostream>

int main() {
    if (sodium_init() < 0) {
        std::cerr << "Failed to initialize libsodium!" << std::endl;
        return 1;
    }

    unsigned char key[crypto_secretbox_KEYBYTES];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    unsigned char message[] = "Hello, libsodium!";
    unsigned char ciphertext[crypto_secretbox_MACBYTES + sizeof(message)];
    unsigned char decrypted[sizeof(message)];

    // Generate a random key and nonce
    randombytes_buf(key, sizeof(key));
    randombytes_buf(nonce, sizeof(nonce));

    // Encrypt the message
    crypto_secretbox_easy(ciphertext, message, sizeof(message), nonce, key);

    // Decrypt the message
    if (crypto_secretbox_open_easy(decrypted, ciphertext, sizeof(ciphertext), nonce, key) != 0) {
        std::cerr << "Decryption failed!" << std::endl;
        return 1;
    }

    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
