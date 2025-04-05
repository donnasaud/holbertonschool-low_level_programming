#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char *username;
    int len, total, i;
    char key[7];
    char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

    if (argc != 2)
    {
        printf("Usage: %s username\n", argv[0]);
        return (1);
    }

    username = argv[1];
    len = strlen(username);

    key[0] = charset[(len ^ 59) & 63];

    total = 0;
    for (i = 0; i < len; i++)
        total += username[i];
    key[1] = charset[(total ^ 79) & 63];

    total = 1;
    for (i = 0; i < len; i++)
        total *= username[i];
    key[2] = charset[(total ^ 85) & 63];

    srand(username[0] ^ 14);
    key[3] = charset[rand() & 63];

    total = 0;
    for (i = 0; i < len; i++)
    {
        if (username[i] > total)
            total = username[i];
    }
    srand(total ^ 229);
    key[4] = charset[rand() & 63];

    total = 0;
    for (i = 0; i < len; i++)
        total += username[i] * username[i];
    key[5] = charset[(total ^ 239) & 63];

    key[6] = '\0';
    printf("%s\n", key);
    return (0);
}


