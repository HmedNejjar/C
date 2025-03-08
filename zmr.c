#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc(int m);
void geo(char* c);

int main (void)
{
    printf("calcul or geometry:");
    char c[8];
    scanf("%s",c);

    if (strcmp(c,"calcul") == 0)
    {
        int m;
        printf("mass : ");
        scanf("%d", &m);
        calc(m);
    }
    else
    {
        char shape[10];
        printf("shape : ");
        scanf("%s", shape);

        geo(shape);

    }

}

int calc(int m)
{
    int result;
    int g = 9.81;

    result = m * g;

    return result;
}

void geo(char* c)
{
     if (strcmp(c, "circle") == 0) {
        printf("radius? ");
        int r;
        scanf("%d", &r);
        printf("area : %f\n", 3.14 * r * r);
    } else if (strcmp(c, "square") == 0) {
        printf("side? ");
        int s;
        scanf("%d", &s);
        printf("area : %f\n", (float)s * s);
    } else if (strcmp(c, "triangle") == 0) {
        printf("base? ");
        int b, h;
        scanf("%d", &b);
        printf("Height? ");
        scanf("%d", &h);
        printf("area : %f\n", 0.5 * b * h);
    } else {
        printf("Invalid shape entered.\n");
    }

}
