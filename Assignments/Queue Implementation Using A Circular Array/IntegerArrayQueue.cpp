#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value)
{
    //printArrayQueue();
    if ((back + 2)%size == front%size)
    {
        return false;
    }
    else
    {
        back = (back + 1) % size;
        array[back] = value;
    }
    return true;
}

//this doesnt have the full functionality implemented of returning 0 if there is no value to return 
int IntegerArrayQueue::dequeue()
{
    //printArrayQueue();
    int value = array[front];
    array[front] = 0;
    front = (front + 1) % size;
    return value;
}