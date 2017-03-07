#include <stdio.h>
#include <sys/uio.h>
#include "amnesia.h"

int mode_syscall_read(amnesia_ctx_t* ctx, uintptr_t address, size_t amt, uint8_t** data, size_t* data_len)
{
    struct iovec local[1], remote[1];
    int expected, recieved;

    /* Alloc buffer if necessary */
    if (*data == NULL) {
        *data = (uint8_t*)malloc(*data_len);
        if (*data == NULL) {
            printf("Failed to alloc memory for read.\n");
            return -1;
        }
    }

    /* Init read info */
    local[0].iov_base = *data;
    local[0].iov_len = *data_len;
    remote[0].iov_base = (void*)address;
    remote[0].iov_len = *data_len;

    /* Perform read */
    expected = (int)(*data_len);
    recieved = process_vm_readv(ctx->pid, local, 1, remote, 1, NULL);
    if (recieved < 0) {
        perror("Failed to process_vm_readv: ");
        return -1;
    }
    else if (recieved != expected) {
        printf("Failed to read expected number of bytes [e:%i != r:%i]\n", expected, recieved);
        return -1;
    }

    return 0;
}

int mode_syscall_write(amnesia_ctx_t* ctx, uintptr_t address, uint8_t* data, size_t data_len)
{
    return -1;
}
