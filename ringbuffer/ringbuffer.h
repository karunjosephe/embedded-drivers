#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint8_t *buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t size;
    uint16_t count;
} RingBuffer_t;

/* Function prototypes */
void RingBuffer_Init(RingBuffer_t *rb, uint8_t *storage, uint16_t size);
bool RingBuffer_IsEmpty(RingBuffer_t *rb);
bool RingBuffer_IsFull(RingBuffer_t *rb);
uint16_t RingBuffer_GetCount(RingBuffer_t *rb);
bool RingBuffer_Put(RingBuffer_t *rb, uint8_t data);
bool RingBuffer_Get(RingBuffer_t *rb, uint8_t *data);

#endif /* RINGBUFFER_H */