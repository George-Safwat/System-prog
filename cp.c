#include <stdio.h>
#include <stdlib.h>

int cp_main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: cp <source> <destination>\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror("cp: cannot open source file");
        return 1;
    }

    FILE *dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        perror("cp: cannot open destination file");
        fclose(src);
        return 1;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        if (fwrite(buffer, 1, bytes, dest) != bytes) {
            perror("cp: write error");
            fclose(src);
            fclose(dest);
            return 1;
        }
    }

    if (ferror(src)) {
        perror("cp: read error");
    }

    fclose(src);
    fclose(dest);
    return 0;
}
