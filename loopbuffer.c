#include "loopbuffer.h"

void init_buffer(*LoopBuffer L_buf, unsigned len) {
    L_buf->buffer = (BYTE*)malloc(len);
    assert(L_buf->buffer != NULL);
    L_buf->length = len;
    L_buf->readPos = 0;
    L_buf->writePos = 0;
}

void clean_buffer(*LoopBuffer L_buf) {
    if (!L_buf->buffer) {
        free(L_buf->buffer);
        L_buf->buffer = NULL;
    }
    free(L_buf);
    *L_buf = NULL;
}


unsigned buffer_data_size(*LoopBuffer L_buf){
    if (!L_buf)
        return 0;
    if (L_buf->readPos > L_buf->writePos)
        return L_buf->length - (L_buf->writePos - L_buf->readPos);
    else
        return L_buf->readPos - L_buf->writePos;
}

unsigned buffer_free_size(*LoopBuffer L_buf) {
    if (!L_buf)
        return 0;
    if (L_buf->readPos > L_buf->writePos)
        return L_buf->readPos - L_buf->writePos;
    else
        return L_buf->length - (L_buf->writePos - L_buf->readPos);
}

int read_from_buffer(*LoopBuffer L_buf, BYTE* buf, unsigned len) {
    if (!L_buf && !buf)
        return 0;
    unsigned l =  L_buf->length;
    unsigned r = L_buf->readPos;
    unsigned w = L_Buf->writePos;
    if (w > r) {
        if ((r + len) > w)
            return -1;
        memcpy(buf, L_buf->buffer, len);
    } else {
        if ((r + len - l) > w)
            return -1;
        memcpy(buf, L_buf->buffer + r, l - r);
        memcpy(buf + l - r, L_buf->buffer, len - (l - r));
    }
    L_buf->readPos = (r + len) % l;
}

int write_from_buffer(*LoopBuffer *L_buf, BYTE* buf, unsigned len) {
    if (!L_buf && !buf)
        return 0;
    unsigned l =  L_buf->length;
    unsigned r = L_buf->readPos;
    unsigned w = L_Buf->writePos;
    if (w + len < l) {
        memcpy(L_buf->buffer + w, buf, len);
    } else {
        memcpy(L_buf->buffer + w, buf, l - w);
        memcpy(L_buf->buffer, buf + l - w, len - (l - w));
    }
    L_buf->writePos = (w + len) % l;
    return 1;
}
