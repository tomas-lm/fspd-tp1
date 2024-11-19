#include "trajeto.hpp"

Trajeto::Trajeto(int idSala, int tempo) : idSala(idSala), tempo(tempo) {
}

int Trajeto::get_idSala() {
    return idSala;
}

int Trajeto::get_tempo() {
    return tempo;
}

void Trajeto::set_idSala(int id) {
    idSala = id;
}

void Trajeto::set_tempo(int tempo) {
    this->tempo = tempo;
}
