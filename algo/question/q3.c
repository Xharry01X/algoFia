#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decrypt(char *text, int shift) {
    int i;
    char c;
    
    for(i = 0; text[i] != '\0'; i++) {
        c = text[i];
        
        if(isalpha(c)) {
            // Determine if uppercase or lowercase
            char base = islower(c) ? 'a' : 'A';
            
            // Shift backward by 15 positions (mod 26 to wrap around)
            c = ((c - base - shift + 26) % 26) + base;
            
            text[i] = c;
        }
        // Non-alphabetic characters remain unchanged
    }
}

int main() {
    char ciphertext[] = "xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpit ghlxiwiwtxgqadds";
    int shift = 15;  // We know the shift is 15
    
    printf("Ciphertext: %s\n", ciphertext);
    
    decrypt(ciphertext, shift);
    
    printf("Decrypted: %s\n", ciphertext);
    
    return 0;
}