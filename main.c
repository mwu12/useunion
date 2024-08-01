#include <stdio.h>
#include <string.h>

// internal members are sharing the same memory space.
// it is crucial to handle the write and read on any of data.
// writing value to integer i will overwite the beginning memory of str[20].
union Data {
    int i;
    float f;
    char str[30];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %.2f\n", data.f);

    // Copying string into char array
    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);

    data.i = 0x3939;  // 0x39 is ANSI character 9, so I give 99 ANSI characters.
    printf("data.i : %d\n", data.i);
    printf("data.str : %s\n", data.str); // it will be 99, not "99Programming"

    return 0;
}

