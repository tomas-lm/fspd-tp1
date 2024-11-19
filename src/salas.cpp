#include "salas.hpp"

int Sala::get_countFila() {
    return countFila;
}

int Sala::get_countSala() {
    return countSala;
}

void Sala::set_countFila(int count) {
    countFila = count;
}

void Sala::set_countSala(int count) {
    countSala = count;
}

void Sala::increment_countFila() {
    countFila++;
}

void Sala::increment_countSala() {
    countSala++;
}

void Sala::decrement_countFila() {
    countFila--;
}

void Sala::decrement_countSala() {
    countSala--;
}

void Sala::increment_countAux() {
    countAux++;
}

void Sala::decrement_countAux() {
    countAux--;
}

int Sala::get_countAux() {
    return countAux;
}

void Sala::set_countAux_zero() {
    countAux = 0;
}
