#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SALT_LENGTH 12
#define MIN_OUTPUT_LENGTH 32
#define DELIMITER '|'

// Custom character set for encoding
const char encoding_chars[] = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

// Function to generate a random salt
char* generate_salt() {
    char* salt = (char*)malloc(SALT_LENGTH + 1);
    for(int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = encoding_chars[rand() % (sizeof(encoding_chars) - 1)];
    }
    salt[SALT_LENGTH] = '\0';
    return salt;
}

// Function to perform XOR operation
void xor_encrypt(char* data, const char* key, int data_len) {
    int key_len = strlen(key);
    for(int i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

// Function to encode the string
char* encode_string(const char* input, const char* salt) {
    int input_len = strlen(input);
    int total_len = input_len + SALT_LENGTH;
    
    // Ensure minimum length
    if(total_len < MIN_OUTPUT_LENGTH) {
        total_len = MIN_OUTPUT_LENGTH;
    }
    
    // Create buffer for the message
    char* buffer = (char*)malloc(total_len + 2);  // +1 for delimiter, +1 for null
    
    // Copy input and add delimiter
    strcpy(buffer, input);
    buffer[input_len] = DELIMITER;
    
    // Add salt after delimiter
    strcpy(buffer + input_len + 1, salt);
    
    // XOR encrypt
    xor_encrypt(buffer, salt, total_len);
    
    // Convert to encoded format
    char* encoded = (char*)malloc(total_len * 2 + 1);
    for(int i = 0; i < total_len; i++) {
        encoded[i*2] = encoding_chars[(unsigned char)buffer[i] >> 4];
        encoded[i*2+1] = encoding_chars[(unsigned char)buffer[i] & 0x0F];
    }
    encoded[total_len * 2] = '\0';
    
    free(buffer);
    return encoded;
}

// Function to decode the string
char* decode_string(const char* encoded, const char* salt) {
    int encoded_len = strlen(encoded);
    int decoded_len = encoded_len / 2;
    
    // Decode from encoded format
    char* decoded = (char*)malloc(decoded_len + 1);
    for(int i = 0; i < decoded_len; i++) {
        char high = strchr(encoding_chars, encoded[i*2]) - encoding_chars;
        char low = strchr(encoding_chars, encoded[i*2+1]) - encoding_chars;
        decoded[i] = (high << 4) | low;
    }
    
    // XOR decrypt
    xor_encrypt(decoded, salt, decoded_len);
    
    // Find delimiter and extract original message
    char* delimiter_pos = strchr(decoded, DELIMITER);
    if(delimiter_pos) {
        int msg_len = delimiter_pos - decoded;
        char* result = (char*)malloc(msg_len + 1);
        strncpy(result, decoded, msg_len);
        result[msg_len] = '\0';
        free(decoded);
        return result;
    }
    
    free(decoded);
    return strdup("Error: Invalid encoded string");
}

int main() {
    srand(time(NULL));
    char input[1000];
    printf("Enter a string to encode: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    char* salt = generate_salt();
    printf("Generated salt: %s\n", salt);
    
    char* encoded = encode_string(input, salt);
    printf("Encoded string: %s\n", encoded);
    
    char* decoded = decode_string(encoded, salt);
    printf("Decoded string: %s\n", decoded);
    
    free(salt);
    free(encoded);
    free(decoded);
    
    return 0;
}