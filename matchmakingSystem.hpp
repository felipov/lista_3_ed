#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

#include <iostream>
#include <string>
#include "Player.hpp"

const int MAX_PLAYERS = 100000;

class Matchmaking {
private:

    Player players[MAX_PLAYERS];
    int size;

public:

    Matchmaking() = default;
    ~Matchmaking() = default;

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    Player* mergeSort(Player* arr, int n);
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    // Outros métodos auxiliares, se necessário
};

#endif