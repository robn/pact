#ifdef __linux__
#include <sys/prctl.h>
#elif __FreeBSD__
#include <sys/procctl.h>
#endif
#include <sys/signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int do_ctl(int signo) {
#ifdef __linux__
    return prctl(PR_SET_PDEATHSIG, signo, 0, 0, 0);
#elif __FreeBSD__
    return procctl(P_PID, 0, PROC_PDEATHSIG_CTL, &signo);
#else
    # no platform support
    return -1
#endif
}

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
        signo = SIGTERM;
    if (do_ctl(signo) < 0) {
        perror("prctl");
        return 1;
    }
    return execvp(argv[cmd], &argv[cmd]);
}
