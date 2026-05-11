#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

#include <iostream>

const int MAX_PLAYERS = 100000;

class Player {
private:
    int id;
    std::string name;
    int score;
    int timestamp;

public:

    Player() = default;
    Player(int id, std::string name, int score, int timestamp);
    ~Player() = default;

    bool operator >(Player player2);
    bool operator >=(Player player2);

    int getId();
    std::string getName();
    int getScore();
    int getTimestamp();
};

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