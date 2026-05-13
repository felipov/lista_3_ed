#include <iostream>
#include <string>
#include "Player.hpp"

Player::Player(int id, std::string name, int score, int timestamp) : id(id), name(name), score(score), timestamp(timestamp) {}

Player::~Player() {}

bool Player::operator >(Player player2) {
    return this->getScore() > player2.getScore();
}

bool Player::operator >=(Player player2) {
    return this->getScore() >= player2.getScore();
}

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