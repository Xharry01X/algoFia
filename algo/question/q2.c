// Compute the relative frequency of all letters A...Z in the ciphertext. You may
//  want to use a tool such as the open-source program CrypTool [50] for this task.
//  However, a paper and pencil approach is also still doable.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()  {
     const char* ciphertext = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb";

    int frequencies[26] = {0};
    int totalLetters = 0;

    // Count letter frequencies
    for (int i = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            frequencies[tolower(ciphertext[i]) - 'a']++;
            totalLetters++;
        }
    }

    // Print frequencies and percentages
    printf("Letter | Count | Percentage\n");
    printf("------------------------\n");
    for (int i = 0; i < 26; i++) {
        printf("%c      | %5d | %.2f%%\n", 
               'A' + i, 
               frequencies[i], 
               (float)frequencies[i] / totalLetters * 100);
    }
    printf("\nTotal letters: %d\n", totalLetters);

    return 0;
}

// Letter | Count | Percentage
// ------------------------
// A      |     5 | 0.77%
// B      |    68 | 10.53%
// C      |     5 | 0.77%
// D      |    23 | 3.56%
// E      |     5 | 0.77%
// F      |     1 | 0.15%
// G      |     1 | 0.15%
// H      |    23 | 3.56%
// I      |    41 | 6.35%
// J      |    48 | 7.43%
// K      |    49 | 7.59%
// L      |     8 | 1.24%
// M      |    62 | 9.60%
// N      |    17 | 2.63%
// O      |     7 | 1.08%
// P      |    30 | 4.64%
// Q      |     7 | 1.08%
// R      |    84 | 13.00%
// S      |    17 | 2.63%
// T      |    13 | 2.01%
// U      |    24 | 3.72%
// V      |    22 | 3.41%
// W      |    47 | 7.28%
// X      |    20 | 3.10%
// Y      |    19 | 2.94%
// Z      |     0 | 0.00%

// Total letters: 646