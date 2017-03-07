/*****************************************************************************\
Copyright (C) 2016-2017 Nyxxie <github.com/nyxxxie>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.
This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 51 Franklin
Street, Fifth Floor, Boston, MA  02110-1301, USA.
\*****************************************************************************/

#ifndef AMNESIA_H
#define AMNESIA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct amnesia_ctx_t amnesia_ctx_t;

typedef enum {
    AMNESIA_MODE_PTRACE = 0,
    AMNESIA_MODE_SYSCALL,
} amnesia_mode_t;

/* Init/free functions */
amnesia_ctx_t* amnesia_init(amnesia_ctx_t* ctx, int pid, amnesia_mode_t mode);
void amnesia_free(amnesia_ctx_t* ctx);

/* Introspective functions */
amnesia_mode_t amnesia_get_mode(amnesia_ctx_t* ctx);
int amnesia_get_pid(amnesia_ctx_t* ctx);

/* Read/write primitives */
int amnesia_read(amnesia_ctx_t* ctx, uintptr_t* address, size_t amt, uint8_t** data, size_t* data_len);
int amnesia_write(amnesia_ctx_t* ctx, uintptr_t* ptr, uint8_t* data, size_t data_len);

/* Process utils */
int amnesia_get_files();
int amnesia_get_file_start();

#ifdef __cplusplus
}
#endif

#endif //AMNESIA_H
