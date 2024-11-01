// Character Shifting Mechanism
// When we encrypt "Hello World" with a shift of 3, each letter moves 3 positions forward in the alphabet:


// 'H' (ASCII 72) → 'K' (shifted 3 positions)
// 'e' (ASCII 101) → 'h' (shifted 3 positions)
// 'l' (ASCII 108) → 'o' (shifted 3 positions)


// The Encryption Formula

// cCopytext[i] = ((text[i] - base + shift) % 26) + base
// Let's break this down step by step:

// base is either 'A' (65) or 'a' (97) depending on case
// Subtract the base to get a 0-25 range number
// Add the shift value
// Use modulo 26 to wrap around the alphabet
// Add back the base to get the new letter

// Example for 'H':

// 'H' = 72
// base 'A' = 65
// 72 - 65 = 7 (position in alphabet)
// 7 + 3 (shift) = 10
// 10 % 26 = 10
// 10 + 65 = 75 ('K')


// Decryption Process
// Decryption is essentially the reverse:

// cCopytext[i] = ((text[i] - base - shift + 26) % 26) + base

// Note the added + 26 to ensure positive values
// Subtracting the shift instead of adding
// The + 26 and % 26 ensure we wrap correctly around the alphabet


// Why 26 - shift for Decryption?


// 26 is the number of letters in the alphabet
// Subtracting the original shift from 26 gives the "reverse" shift
// Example: If you shift 3 forward to encrypt, you shift 23 backward to decrypt


// Preserving Case and Ignoring Non-Alphabetic Characters


// The isalpha() check ensures only letters are shifted
// Spaces, punctuation remain unchanged
// Uppercase and lowercase are handled separately

// Let me illustrate the step-by-step encryption of "Hello World" with shift 3:
// H → K
// e → h
// l → o
// l → o
// o → r
// (space stays a space)
// W → Z
// o → r
// r → u
// l → o
// d → g
// Decryption simply reverses this process by shifting backward.
// The % 26 (modulo 26) is crucial because it ensures we wrap around the alphabet. When we go past 'Z' or 'z', we circle back to the beginning.
















#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void shift_cipher(char *text, int shift, int encrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            if (encrypt) {
                // Encryption shifts forward
                text[i] = ((text[i] - base + shift) % 26) + base;
            } else {
                // Decryption shifts backward
                text[i] = ((text[i] - base - shift + 26) % 26) + base;
            }
        }
    }
}

int main() {
    char original_text[MAX_LENGTH];
    char encrypted_text[MAX_LENGTH];
    int shift;

    // Get input text
    printf("Enter text to encrypt: ");
    fgets(original_text, sizeof(original_text), stdin);
    original_text[strcspn(original_text, "\n")] = 0;  // Remove newline

    // Get shift value
    printf("Enter shift value (0-25): ");
    scanf("%d", &shift);

    // Validate shift
    if (shift < 0 || shift > 25) {
        printf("Invalid shift. Please use a value between 0 and 25.\n");
        return 1;
    }

    // Copy original text to encrypted text
    strcpy(encrypted_text, original_text);

    // Perform encryption
    shift_cipher(encrypted_text, shift, 1);

    // Print encryption results
    printf("\n--- Encryption Results ---\n");
    printf("Original Text: %s\n", original_text);
    printf("Encrypted Text: %s\n", encrypted_text);
    printf("Shift Value: %d\n", shift);
    printf("Decryption Shift: %d\n", 26 - shift);

    // Demonstrate decryption
    shift_cipher(encrypted_text, 26 - shift, 0);
    printf("\n--- Decryption Verification ---\n");
    printf("Decrypted Text: %s\n", encrypted_text);

    return 0;
}