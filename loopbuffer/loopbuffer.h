#ifndef _LOOPBUFFER_
#define _LOOPBUFFER_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

#define BYTE char

typedef struct LoopBuffer {
    BYTE* buffer;
    unsigned length;
    unsigned readPos;
    unsigned writePos;
}LoopBuffer;

void init_buffer(*LoopBuffer L_buf, unsigned len);
void clean_buffer(*LoopBuffer L_buf);
unsigned buffer_data_size(*LoopBuffer L_buf);
unsigned buffer_free_size(*LoopBuffer L_buf);
int read_from_buffer(*LoopBuffer L_buf, BYTE* buf, unsigned len);
int write_from_buffer(*LoopBuffer *L_buf, BYTE* buf, unsigned len);

#endif /* end of include guard: _LOOPBUFFER_ *
