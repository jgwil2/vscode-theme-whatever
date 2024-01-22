#include <stdio.h>

#define MAX_NESTING_DEPTH 1000
#define IN_COMMENT 0
#define IN_QUOTED_STRING 1

get_state(int current_state, char previous, char c);

int main()
{
    int c;
    int state;
    int stack[MAX_NESTING_DEPTH];
    int stack_ptr = 0;

    while ((c = getchar()) != EOF)
    {
        if (stack_ptr > MAX_NESTING_DEPTH)
        {
            printf("Max nesting depth exceeded: %d", MAX_NESTING_DEPTH);
            return 1;
        }

        if (c == '(' || c == '[' || c == '{')
        {
            stack[stack_ptr++] = c;
        }

        if (c == ')' && stack[--stack_ptr] != '(')
        {
            printf("Error detected: %c\n", c);
            return 1;
        }

        if (c == ']' && stack[--stack_ptr] != '[')
        {
            printf("Error detected: %c\n", c);
            return 1;
        }

        if (c == '}' && stack[--stack_ptr] != '{')
        {
            printf("Error detected: %c\n", c);
            return 1;
        }
    }

    if (stack_ptr > 0)
    {
        printf("Error detected: %c\n", stack[stack_ptr]);
        return 1;
    }
}
