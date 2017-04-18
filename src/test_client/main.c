#include <stdio.h>
#include <sys/uio.h>

int main(int argc, char* argv[])
{
    struct iovec local[1];
    struct iovec remote[1];
    char buf1[10];
    int i;
    ssize_t nread;
    pid_t pid = 32398;             /* PID of remote process */

    local[0].iov_base = buf1;
    local[0].iov_len = 10;
    remote[0].iov_base = (void *)0x00400000;
    remote[0].iov_len = 10;

    nread = process_vm_readv(pid, local, 1, remote, 1, NULL);
    if (nread != 10) {
        printf("Read wrong amount! [%i]\n", nread);
        perror("\terror: ");
        return 1;
    }

    for (i=0; i<sizeof(buf1); i++) {
        printf("%0x", buf1[i]);
    }
    printf("\n");

    return 0;
}
