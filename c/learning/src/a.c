#include <stdio.h>
#include <stdlib.h>

struct example
{
    int x, y;
    char s[50];
};

int main()
{
    struct example e;

    e.x = 1;
    e.y = 2;
    printf("%d", e.x + e.y);

    strcpy(e.s, "This sucks");
    printf("%s", e.s);

    return 0;
}
