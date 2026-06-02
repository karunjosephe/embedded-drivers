# Ring Buffer

A lightweight FIFO ring buffer implementation for embedded systems.

## Features

- Fixed-size buffer
- No dynamic memory allocation
- Overflow protection
- Underflow protection
- Circular indexing

## Example

```c
uint8_t storage[8];
RingBuffer_t rb;

RingBuffer_Init(&rb, storage, 8);

RingBuffer_Put(&rb, 'A');
RingBuffer_Put(&rb, 'B');

uint8_t data;
RingBuffer_Get(&rb, &data);