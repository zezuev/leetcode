#include <math.h>


int length_of_longest_substring(char *s) {
    int freq[128] = {0};
    int start = 0;
    int end = 0;
    int max = 0;

    while (s[end] != '\0') {
        if (++freq[s[end]] < 2) {
            max = fmax(max, end - start + 1);
        } else {
            while (freq[s[end]] > 1) {
                --freq[s[start++]];
            }
        }
        end++;
    }
    return max;
}