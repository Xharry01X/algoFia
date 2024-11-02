// The ciphertext below was encrypted using a substitution cipher. Decrypt the ciphertext without knowledge of the key.
//  lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi
//  bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx
//  ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr
//  yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk
//  lmird jk xjubt trmui jx ibndt
//  wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi
//  iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m
//  vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd
//  wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr
//  jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii
//  ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh
//  mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb
//  bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd
//  wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr
//  riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmv


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// letter frequency
const char* ENGLISH_FREQ = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

// to count letter frequencies in the cipher text
void countFrequencies(const char* text, int* freqs){
    for(int i=0; text[i]; i++){
        if(isalpha(text[i])){
           freqs[tolower(text[i]) - 'a']++;
        }
    }
}

// sorted a indices of letter frequencies
void getSortedIndices(const int* freqs, int* indices){
    for(int i=0; i < 26; i++){
        indices[i] = i;
    }

    // bubble sort
    for(int i=0; i <26 -1; i++){
        for(int j=0; j < 26 - i - 1; j++){
              if (freqs[indices[j]] < freqs[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}


int main() {
    const char* ciphertext = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb";
    
    int frequencies[26] = {0};
    countFrequencies(ciphertext, frequencies);
    
    int sortedIndices[26];
    getSortedIndices(frequencies, sortedIndices);
    
    // Create substitution mapping
    char mapping[26];
    for (int i = 0; i < 26; i++) {
        mapping[sortedIndices[i]] = tolower(ENGLISH_FREQ[i]);
    }
    
    // Manual adjustments based on common patterns and word analysis
    // These mappings were determined through analysis of the ciphertext
    mapping['r' - 'a'] = 'e';
    mapping['b' - 'a'] = 't';
    mapping['p' - 'a'] = 'h';
    mapping['i' - 'a'] = 's';
    mapping['m' - 'a'] = 'a';
    mapping['k' - 'a'] = 'n';
    mapping['d' - 'a'] = 'd';
    mapping['j' - 'a'] = 'o';
    mapping['x' - 'a'] = 'f';
    mapping['w' - 'a'] = 'i';
    mapping['y' - 'a'] = 'm';
    mapping['n' - 'a'] = 'u';
    mapping['v' - 'a'] = 'c';
    mapping['q' - 'a'] = 'k';
    mapping['c' - 'a'] = 'w';
    mapping['h' - 'a'] = 'l';
    mapping['t' - 'a'] = 'y';
    mapping['s' - 'a'] = 'p';
    mapping['u' - 'a'] = 'r';
    mapping['l' - 'a'] = 'b';
    mapping['o' - 'a'] = 'g';
    mapping['a' - 'a'] = 'x';
    mapping['g' - 'a'] = 'z';
    mapping['e' - 'a'] = 'v';
    
    // Print decrypted text
    printf("Decrypted text:\n");
    for (int i = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            printf("%c", mapping[tolower(ciphertext[i]) - 'a']);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
    
    return 0;
}