#include "./headers/hashmapLite.h"

int main() {
    initialize();

    put("hi", "bye");

    printf("%s\n", get("hi"));
    

    return 0;
}