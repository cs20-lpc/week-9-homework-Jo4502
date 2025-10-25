#ifndef QUEUEFACTORY_HPP
#define QUEUEFACTORY_HPP

#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

class QueueFactory {
public:
    template <typename T>
    static Queue<T>* GetQueue(int length = -1) {
        if (length <= 0)
            return new LinkedQueue<T>();
        else
            return new ArrayQueue<T>(length);
    }
};

#endif
