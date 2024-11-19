#ifndef TRAJETO_HPP
#define TRAJETO_HPP

class Trajeto {
private:
    int idSala; // The ID of the room
    int tempo; // The time the thread spends in this room

public:
    /**
     * Constructor for the Trajeto class
     * @param idSala The ID of the room
     * @param tempo The time to spend in the room
     */
    Trajeto(int idSala, int tempo);

    /**
     * Gets the room ID
     * @return The ID of the room
     */
    int get_idSala();

    /**
     * Gets the time spent in the room
     * @return The time in the room
     */
    int get_tempo();

    /**
     * Sets the room ID
     * @param id The new room ID
    */
    void set_idSala(int id);

    /**
     * Sets the time to spend in the room
     * @param tempo The new time
     */
    void set_tempo(int tempo);
};

#endif
