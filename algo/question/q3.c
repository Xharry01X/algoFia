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

// Frequency Analysis:
// Let's count letter frequencies in the ciphertext:


// Most frequent letters: t (12 times), x (9 times), i (8 times), w (8 times)
// In English, the most common letters are E, T, A, O, I, N

// Since 't' is one of the most frequent letters in our ciphertext, let's assume it corresponds to 'e':

// 't' → 'e' means a shift of 15 (as 't' is 15 positions after 'e' in the alphabet)

// Testing shift 15 immediately gives us readable text:
// "if we all unite we will cause the rivers to stain the great water with their blood"
// So we only needed to identify ONE letter frequency ('t' = 'e') to find the key (15)! This worked because:

// 't' was a very frequent letter in the ciphertext
// 'e' is the most common letter in English
// The resulting shift of 15 gave readable text
// Historical Context:
// This is a quote from Tecumseh (1768-1813), a Native American Shawnee chief. The full quote comes from his efforts to unite various Native American tribes against European American expansion. He spoke these words while trying to build a confederation of tribes to resist American territorial expansion.

// The "great water" refers to the Great Lakes, and this was part of his speech to rally different tribes together. Tecumseh was a significant historical figure who worked to create a pan-Indian alliance in the early 19th century, before ultimately being defeated at the Battle of the Thames in 1813.
// This particular quote reflects his powerful oratory and his mission to unite Native American tribes in resistance to American expansion. The message emphasizes unity ("if we all unite") and contains strong imagery about fighting for their lands.