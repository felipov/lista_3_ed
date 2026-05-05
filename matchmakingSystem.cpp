#include "matchmakingSystem.hpp"

// Player

Player::Player(int id, std::string name, int score, int timestamp) : id(id), name(name), score(score), timestamp(timestamp) {}

std::string Player::getName() {
    return this->name;
}

int Player::getId() {
    return this->id;
}

int Player::getScore() {
    return this->score;
}

int Player::getTimestamp() {
    return this->timestamp;
}

// Matchmaking

bool Matchmaking::insert(Player player) {
    if (this->size == MAX_PLAYERS) return false;
    this->players[size++] = player;
    return true;
}

bool Matchmaking::removePlayer(int id) {
    for (int i = 0; i < size; i++) {
        if (this->players[i].getId() == id) {
            for (int j = i; j < size - 1; j++) {
                players[j] = players[j + 1];
            }
            return true;
        }
    }
    return false;
}

bool isScoreGreater(Player player1, Player player2) {
    return player1.getScore() > player2.getScore()
}

void Matchmaking::sortByScoreInsertion() {
    for (int i = 1; i < size; i++) {
        int j = i - 1;

        while (j >= 0 && isScoreGreater(players[j], players[i])) {
            players[j + 1] = players[j];
            j = j - 1;
        }
        players[j + 1] = players[i]
    }
}

Player* Matchmaking::getWaitingPlayers(int* n) {
    if (size == 0) {
        *n = 0;
        return nullptr;
    }

    Player* result = new Player[size];
    *n = size;

    for (int i = 0; i < size; i++) { 
        result[i] = players[i];
    }

    return result;
}

void Matchmaking::printWaitingPlayers() {
    for (int i = 0; i < size; i++) {
        std::cout << players[i].getName() << std::endl;
    }
}