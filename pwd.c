#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int pwd_main() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("pwd");
        return 1;
    }
    printf("%s\n", cwd);
    return 0;
}
