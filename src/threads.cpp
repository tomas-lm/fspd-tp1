#include "threads.hpp"
#include "trajeto.hpp"

// Sets the ID for the thread
void Thread::set_id(int id) {
    this->id = id;
}

// Sets the initial time
void Thread::set_tempoInicial(int tempo) {
    this->tempoInicial = tempo;
}

// Sets the number of rooms
void Thread::set_numeroSalas(int numeroSalas) {
    this->numeroSalas = numeroSalas;
}

// Returns the ID of the thread
int Thread::get_id() {
    return id;
}

// Returns the initial time
int Thread::get_tempoInicial() {
    return tempoInicial;
}

// Returns the number of rooms
int Thread::get_numeroSalas() {
    return numeroSalas;
}

// Adds a new trajectory to the thread's list of trajectories
void Thread::add_trajectory(int idSala, int tempo) {  // Function renamed and used directly
    trajetoria.push_back(Trajeto(idSala, tempo));     // Adds a Trajeto object to the vector
}
