#ifndef SALAS_HPP
#define SALAS_HPP

#include <pthread.h>
#include <queue>


class Sala {
private:
    int countFila; // tracks the number of threads in the queue for this room
    int countSala; // tracks the number of threads currently inside the room
    int countAux; // tracks the number of threads currently inside the room

public:
    pthread_mutex_t mutex; // mutex for the room
    pthread_cond_t cond; // room empty condition variable

    std::queue<int> fila; // qeue of threads waiting to enter the room

    /**
     * Gets the count of threads in the queue.
     * @return the number of threads in the queue.
     */
    int get_countFila();

    /**
     * Gets the count of threads currently in the room.
     * @return the number of threads in the room.
     */
    int get_countSala();

    /**
     * Sets the count of threads in the queue.
     * @param count the new queue count value.
     */
    void set_countFila(int count);

    /**
     * Sets the count of threads in the room.
     * @param count the new room count value.
     */
    void set_countSala(int count);

    /**
     * Increments the queue count when a thread joins the queue.
     */
    void increment_countFila();

    /**
     * Increments the room count when a thread enters the room.
     */
    void increment_countSala();

    /**
     * Decrements the queue count when a thread leaves the queue.
     */
    void decrement_countFila();

    /**
     * Decrements the room count when a thread leaves the room.
     */
    void decrement_countSala();

    /**
     * Increments the room count when a thread enters the room.
     */
    void increment_countAux();

    /**
     * Decrements the room count when a thread leaves the room.
     */
    void decrement_countAux();

    /**
     * Gets the count of threads currently in the room.
     * @return the number of threads in the room.
     */
    int get_countAux();

    /**
     * Sets the count of threads in the room.
     * @param count the new room count value.
     */
    void set_countAux_zero();
};

#endif
