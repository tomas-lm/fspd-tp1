#include <iostream>
#include "threads.hpp"
#include "salas.hpp"
#include "utils.hpp"
#include "passa_tempo.hpp"
#include "trajeto.hpp"

using namespace std;

vector<Sala> salas;

int main() {
    int S, T;

    // Read the number of rooms (S) and threads (T) from input
    cin >> S >> T;

    // Create a vector to store information about each thread
    vector<Thread> threadsInfo(T);

    // Resize the 'salas' vector to accommodate all rooms (1-indexed, so +1)
    salas.resize(S + 1);

    // Initialize mutexes and condition variables for each room
    for (int i = 1; i <= S; ++i) {
        pthread_mutex_init(&salas[i].mutex, nullptr); // Initialize room mutex
        pthread_cond_init(&salas[i].cond, nullptr); // For signaling when a room is empty
        salas[i].set_countFila(0); // Set queue count to 0
        salas[i].set_countSala(0); // Set active threads in room to 0
    }

    // Read data for each thread
    for (int i = 0; i < T; i++) {
        Thread& data_t = threadsInfo[i]; // Get reference to current thread data
        int id, tempoInicial, numeroSalas;
        std::cin >> id >> tempoInicial >> numeroSalas; // Thread ID, initial time, and number of rooms

        data_t.set_id(id); // Set thread ID
        data_t.set_tempoInicial(tempoInicial); // Set its initial wait time
        data_t.set_numeroSalas(numeroSalas); // Set how many rooms this thread will visit

        // Read the trajectory for this thread (room IDs and time spent in each room)
        for (int j = 0; j < data_t.get_numeroSalas(); j++) {
            int id_sala, time_sala;
            cin >> id_sala >> time_sala;
            data_t.add_trajectory(id_sala, time_sala); // Add room and time to its trajectory
        }
    }

    // Create a vector to hold the actual thread objects
    vector<pthread_t> threads(T);

    // Create each thread
    for (int i = 0; i < T; ++i) {
        Thread* data = &threadsInfo[i]; // Pointer to thread info
        int ret = pthread_create(&threads[i], nullptr, threadFunction, (void*)data); // Create the thread

        // Check if thread creation was successful
        if (ret != 0) {
            std::cerr << "Error creating thread " << data->get_id() << std::endl;
            exit(EXIT_FAILURE); // Abort if thread creation fails
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < T; ++i) {
        pthread_join(threads[i], nullptr); // Join the thread to ensure it finishes before continuing
    }

    // Clean up all mutexes and condition variables
    for (int i = 1; i <= S; ++i) {
        pthread_mutex_destroy(&salas[i].mutex); // Destroy room mutex
        pthread_cond_destroy(&salas[i].cond); // Destroy 'empty room' condition variable
    }
}
