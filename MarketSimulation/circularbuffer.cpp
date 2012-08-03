#include "circularbuffer.h"

#include <cstdlib>

CircularBuffer::CircularBuffer()
{
    data = 0;
    reservedSize = 0;
    size = 0;
}

CircularBuffer::CircularBuffer(unsigned int newSize)
{
    data = 0;
    reservedSize = 0;
    size = 0;

    setReservedSize(newSize);
}

void CircularBuffer::setReservedSize(unsigned int newSize)
{
    // If the buffer already has data, clear it
    if (data != 0) {
        free((void *) data);
    }
    size = 0;

    if (newSize == 0) {
        data = 0;
        reservedSize = 0;
    } else {
        data = (double *) calloc(newSize, sizeof(double));
        reservedSize = newSize;
    }
}

void CircularBuffer::insertItem(double item)
{
    if (reservedSize == 0) {
        // Fail; no way to insert an item into a buffer of 0 size
        exit(EXIT_FAILURE);
    } else {
        // Throw the item on
        data[size % reservedSize] = item;
        size++;
    }
}

unsigned int CircularBuffer::getSize()
{
    if (size < reservedSize) {
        return size;
    } else {
        return reservedSize;
    }
}

const double *CircularBuffer::getData()
{
    return data;
}
