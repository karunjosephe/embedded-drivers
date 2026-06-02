#include "ringbuffer.h"
#include <stdio.h>

uint8_t storage[8];
RingBuffer_t grb;

int main(void)
{
    uint8_t data;

    RingBuffer_Init(&grb, storage, 8);

    RingBuffer_Put(&grb, 'A');
    RingBuffer_Put(&grb, 'B');
    RingBuffer_Put(&grb, 'C');

    RingBuffer_Get(&grb, &data);
    RingBuffer_Get(&grb, &data);

    RingBuffer_Put(&grb, 'D');
    RingBuffer_Put(&grb, 'E');
    RingBuffer_Put(&grb, 'F');
    RingBuffer_Put(&grb, 'G');
    RingBuffer_Put(&grb, 'H');
    RingBuffer_Put(&grb, 'I');
    RingBuffer_Put(&grb, 'J');

    while(RingBuffer_Get(&grb, &data))
    {
        printf("%c ", data);
    }

    printf("\n");

    return 0;
}