#include <stdint.h>
#include <stdbool.h>
#include "ringbuffer.h"

/* Function implementations */

/* Initialize the ring buffer */
void RingBuffer_Init(RingBuffer_t *rb, uint8_t *storage, uint16_t size){
    rb->buffer = storage;
    rb->size   = size;
    rb->head   = 0;
    rb->tail   = 0;
    rb->count  = 0;
}
/* Check if the ring buffer is empty */
bool RingBuffer_IsEmpty(RingBuffer_t *rb){
    return rb->count==0;
}
/* Check if the ring buffer is full */
bool RingBuffer_IsFull(RingBuffer_t *rb){
    return rb->count == rb->size;
}
/* Get the number of elements in the ring buffer */
uint16_t RingBuffer_GetCount(RingBuffer_t *rb){
    return rb->count;
}
/* Put an element into the ring buffer */
bool RingBuffer_Put(RingBuffer_t *rb, uint8_t data){
    if(rb == NULL){
        return false;
    }
    /* Overflow protection */
    if(RingBuffer_IsFull(rb)){
        return false;
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head+1)%rb->size;
    rb->count++;
    return true;
}
/* Get an element from the ring buffer */
bool RingBuffer_Get(RingBuffer_t *rb, uint8_t *data){
    if(rb == NULL){
        return false;
    }
    if(data == NULL){
        return false;
    }
    /* Underflow protection */
    if(RingBuffer_IsEmpty(rb)){
        return false;
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail+1)%rb->size;
    rb->count--;
    return true;
}
