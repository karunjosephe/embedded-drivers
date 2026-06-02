# Ring Buffer

A lightweight FIFO ring buffer implementation in C for embedded systems.

## Features

- Fixed-size buffer
- No dynamic memory allocation
- FIFO operation
- Overflow protection
- Underflow protection
- Circular indexing

## Files

- ringbuffer.c - Implementation
- ringbuffer.h - Public API
- test.c - Test application

## Example

```c
uint8_t storage[8];
RingBuffer_t rb;

RingBuffer_Init(&rb, storage, 8);

RingBuffer_Put(&rb, 'A');

uint8_t data;
RingBuffer_Get(&rb, &data);
```
