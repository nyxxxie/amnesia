#include <amnesia.h>

struct amnesia_ctx_t {
    int pid;
    amnesia_mode_t mode;
};

int open_process(amnesia_ctx_t* ctx, int pid, amnesia_mode_t mode)
{

}

/**
 * Initializes an amnesia ctx.
 *
 * @param ctx amnesia_ctx_t context to operate on.
 * @param pid Process id.
 * @param mode Mode to use to perform memory operations.
 * @return Pointer to an amnesia_ctx_t context.
 */
amnesia_ctx_t* amnesia_init(amnesia_ctx_t* ctx, int pid, amnesia_mode_t mode)
{
    return NULL;
}

/**
 * Read data to the remote process.
 *
 * @param ctx amnesia_ctx_t context to operate on.
 * @param address Address to read from.
 * @param amt Amount of data to read.
 * @param data Data that was read from process.
 * @param data_len Amount of data that was read.
 * @return Returns value < 0 on error, otherwise 0 on success.
 */
int amnesia_read(amnesia_ctx_t* ctx, uintptr_t* address, size_t amt, uint8_t** data, size_t* data_len)
{
    return -1;
}

/**
 * Writes data to the remote process.
 *
 * @param ctx amnesia_ctx_t context to operate on.
 * @param address Address to write to.
 * @param data Data to write to the given address.
 * @param data_len Amount of data to write.
 * @return Returns value < 0 on error, otherwise 0 on success.
 */
int amnesia_write(amnesia_ctx_t* ctx, uintptr_t* address, uint8_t* data, size_t data_len)
{
    return -1;
}

/**
 * Closes an amnesia ctx.
 *
 * @param ctx amnesia_ctx_t to clean up.
 */
void amnesia_free(amnesia_ctx_t* ctx)
{

}
