#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

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

#endif