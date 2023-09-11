#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isDelimiter(char ch) {
    char delimiters[] = " ,;<>=[]{}";
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (ch == delimiters[i])
            return true;
    }
    return false;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool isValidIdentifier(char* str) {
    if (str[0] >= '0' && str[0] <= '9')
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }
    return true;
}

bool isKeyword(char* str) {
    char* keywords[] = {"if", "else", "do", "while", "int", "float", "double", "static", "void", "goto"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return true;
    }
    return false;
}

char* subString(char* str, int left, int right) {
    int len = right - left + 1;
    char* subStr = (char*)malloc(len + 1);
    strncpy(subStr, str + left, len);
    subStr[len] = '\0';
    return subStr;
}

void parse(char* str) {
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right) {
        if (isDelimiter(str[right])) {
            if (left == right) {
                if (isOperator(str[right]))
                    printf("'%c' IS AN OPERATOR\n", str[right]);
            } else {
                char* subStr = subString(str, left, right - 1);
                if (isKeyword(subStr))
                    printf("'%s' IS A KEYWORD\n", subStr);
                else if (isValidIdentifier(subStr))
                    printf("'%s' IS A VALID IDENTIFIER\n", subStr);
                else
                    printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
                free(subStr);
            }
            left = right + 1;
        }
        right++;
    }
}

int main() {
    char str[100] = "int a = a + 1c";
    parse(str);
    return 0;
}
