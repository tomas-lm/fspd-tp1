#ifndef THREADS_HPP
#define THREADS_HPP

#include <pthread.h>
#include <vector>
#include <iostream>
#include "trajeto.hpp"

// The Thread class represents a thread
class Thread {
private:
    int id; // The unique ID for this thread
    int tempoInicial; // How long the thread waits before starting
    int numeroSalas; // Number of rooms this thread will visit

public:
    /**
     * Adds a room and the time the thread will spend in it to the thread's trajectory
     * @param idSala The ID of the room
     * @param tempo The time to spend in the room
     */
    void add_trajectory(int idSala, int tempo);

    /**
     * Sets the ID of the thread
     * @param id The thread's unique ID
     */
    void set_id(int id);

    /**
     * Sets the initial waiting time for the thread
     * @param tempo The initial waiting time
     */
    void set_tempoInicial(int tempo);

    /**
     * Sets the number of rooms the tread will visit
     * @param numeroSalas The number of rooms
     */
    void set_numeroSalas(int numeroSalas);

    /**
     * Gets the thread's ID
     * @return The ID of the thread
     */
    int get_id();

    /**
     * Gets the initial waiting time for the thread
     * @return The initial waiting time
     */
    int get_tempoInicial();

    /**
     * Gets the number of rooms the thread will visit
     * @return The number of rooms
     */
    int get_numeroSalas();

    std::vector<Trajeto> trajetoria; // A list of rooms (and times) the thread will pass through
};

#endif
