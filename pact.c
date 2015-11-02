#include <sys/prctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if(argc < 2)
        return 1;
    int cmd = 1;
    int signo = 0;
    if (*argv[1] == '-') {
        signo = atoi(argv[1] + 1);
        if (argc < 3)
            return 1;
        cmd = 2;
    }
    if (!signo)
        signo = 15;
    if (prctl(PR_SET_PDEATHSIG, signo, 0, 0, 0) < 0) {
        perror("prctl");
        return 1;
    }
    return execvp(argv[cmd], &argv[cmd]);
}
