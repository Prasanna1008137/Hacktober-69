#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char * s) {
    int len = strlen(s);
    if (len % 2 != 0) return false;  // odd length cannot be valid

    char *stack = (char *)malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(') {
            stack[++top] = ')';  // push expected closing bracket
        } else if (c == '[') {
            stack[++top] = ']';
        } else if (c == '{') {
            stack[++top] = '}';
        } else {
            // if stack empty or top doesn't match current char
            if (top == -1 || stack[top] != c) {
                free(stack);
                return false;
            }
            top--;  // pop the matching closing bracket
        }
    }
    
    bool valid = (top == -1);  // stack should be empty if valid
    free(stack);
    return valid;
}
