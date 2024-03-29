
#include <stdio.h>
int isNthBitSet (int c, int n) {
    static unsigned char mask[] = {128, 64, 32, 16, 8, 4, 2, 1};
    return ((c & mask[n]) != 0);
}
int main() {
    int index = 0;
    while (index < 65) {
        // Check if the third byte is zero
        if (isNthBitSet(index, 7) == 0)
            printf("byte == 0 for %d\n", index);
        else
            printf("byte != 0 for %d\n", index);
        index++;
    }
    return 0;
}
