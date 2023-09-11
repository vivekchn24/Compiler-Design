#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    q0,
    q1,
    reject
} state;

bool validateString(const char* input) {
    state currentstate = q0;

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];

        switch (currentstate) {
            case q0:
                if (symbol == 'a') {
                    currentstate = q0;
                } else if (symbol == 'b') {
                    currentstate = q1;
                } else {
                    currentstate = reject;
                }
                break;
            case q1:
                if (symbol == 'b') {
                    currentstate = q1;
                } else {
                    currentstate = reject;
                }
                break;
            case reject:
                return false;
        }
    }
    return currentstate == q1;
}

int main() {
    char input[100];

    printf("Enter The String Using 'a' And 'b': "); // Corrected the format string
    scanf("%s", input); // Corrected the quotation marks

    bool isvalid = validateString(input);
    printf("'%s' is %s for the given regular expression.\n", input, isvalid ? "valid" : "invalid");
    return 0;
}
