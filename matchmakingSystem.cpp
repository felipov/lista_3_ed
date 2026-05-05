#include "matchmakingSystem.hpp"

// Player

Player::Player(int id, std::string name, int score, int timestamp) : id(id) name(name), score(score), timestamp(timestamp) {}

std::string Player::getName() return name;

int Player::getID() return id;

int Player::getName() return name;

int Player::getTimestamp() return timestamp;

// Matchmaking

bool Matchmaking::insert(Player player) {
    if (size == MAX_PLAYERS) return false;
    this->players[++size] = player;
    return true;
}

bool Matchmaking::removePlayer(int id) {
    for (int i = 0; i < size; i++) {
        if (this->players[i].id == player) {
            delete player;
            return true;
        }
    }
    return false;
}

void Matchmaking::sortByScoreInsertion() {
    int maxScore = 0;
    for (int i = 1; i < size; i++) {
        maxScore = players[i].score;
        for (int j = i; j < size; j++) {
            if (players[j].score > maxScore) maxScore = players[j].score; 
        }
    }
}