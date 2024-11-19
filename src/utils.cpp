#include "utils.hpp"
#include <iostream>

bool verbose = false;

void* threadFunction(void* arg) {
    Thread* data = static_cast<Thread*>(arg);
    int thread_id = data->get_id();

    // wait for the initial time before starting
    passa_tempo(thread_id, 0, data->get_tempoInicial());

    int previous_room = -1;

    for (size_t i = 0; i < data->trajetoria.size(); ++i) {
        int room_id = data->trajetoria[i].get_idSala();
        int time_in_room = data->trajetoria[i].get_tempo();

        // enter the room
        // std::cout << thread_id << " indo para sala " << room_id << "\n"; 
        joinRoom(room_id, thread_id, previous_room);
        previous_room = room_id;

        // spend time in the room
        passa_tempo(thread_id, room_id, time_in_room);
    }

    leaveRoom(previous_room, thread_id);

    // exit the thread
    pthread_exit(nullptr);
}

void joinRoom(int id_sala, int t_id, int previous_room) {
    // lock the mutex
    pthread_mutex_lock(&salas[id_sala].mutex);

    salas[id_sala].increment_countFila();

    while(salas[id_sala].get_countSala() > 0 || salas[id_sala].get_countFila() < 3){
        // std::cout << t_id << ": " << salas[id_sala].get_countSala() << " and fila " << salas[id_sala].get_countFila() << "\n"; 
        pthread_cond_wait(&salas[id_sala].cond, &salas[id_sala].mutex);
    }

    if (salas[id_sala].get_countSala() == 0){
        // notify the threads that the room is empty
        for(int i = 0; i < 2; i++){
            pthread_cond_signal(&salas[id_sala].cond);
        }
    }
    
    // leave previous room
    if (previous_room != -1){
        leaveRoom(previous_room, t_id);
    }

    salas[id_sala].increment_countAux();

    // once 3 threads are ready, set the room as full and notify waiting thread
    if (salas[id_sala].get_countAux() == 3){
        salas[id_sala].set_countSala(3);
        for(int i = 0; i < 3; i++){
            salas[id_sala].decrement_countFila();
        }
        salas[id_sala].set_countAux_zero();
    }

    // unlock the mutex to allow other threads to access the room
    pthread_mutex_unlock(&salas[id_sala].mutex);
}


void leaveRoom(int id_sala, int t_id) {
    // lock the mutex
    pthread_mutex_lock(&salas[id_sala].mutex);

    salas[id_sala].decrement_countSala();

    if (salas[id_sala].get_countSala() == 0) {
        // If all 3 threads have exited, signal the next batch
        pthread_cond_broadcast(&salas[id_sala].cond);
    }

    // unlock the mutex to allow other threads to access the room
    pthread_mutex_unlock(&salas[id_sala].mutex);
}
