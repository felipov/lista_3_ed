#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

#include <iostream>

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
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    // Outros métodos auxiliares, se necessário
};

#endif