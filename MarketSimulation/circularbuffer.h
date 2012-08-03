#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

class CircularBuffer
{
public:
    CircularBuffer();
    CircularBuffer(unsigned int newSize);

    void setReservedSize(unsigned int newSize);
    void insertItem(double item);
    unsigned int getSize();

    double const *getData();

private:
    unsigned int reservedSize;
    unsigned int size;
    double*      data;
};

#endif // CIRCULARBUFFER_H
