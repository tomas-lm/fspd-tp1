#ifndef UTILS_HPP
#define UTILS_HPP

#include <pthread.h>
#include <vector>
#include <iostream>
#include "passa_tempo.hpp"
#include "salas.hpp"
#include "threads.hpp"
#include "trajeto.hpp"

// A global vector of Sala objects representing all the rooms
extern std::vector<Sala> salas;

/**
 * The main function executed by each thread.
 * Handles the thread's journey through the specified rooms.
 * @param arg Pointer to a Thread object containing the thread's details.
 * @return Always returns nullptr (standard for pthread functions).
 */
void* threadFunction(void* arg);

/**
 * Handles the logic for a thread to enter a room.
 * Waits if the room is full or if there are not enough threads to form a trio.
 * @param idSala The ID of the room the thread wants to join.
 * @param t_id The thread's ID.
 */
void joinRoom(int idSala, int t_id, int previous_room);

/**
 * Handles the logic for a thread to leave a room.
 * Notifies waiting threads if the room becomes empty.
 * @param idSala The ID of the room the thread is leaving.
 * @param t_id The thread's ID.
 */
void leaveRoom(int idSala, int t_id);

#endif
