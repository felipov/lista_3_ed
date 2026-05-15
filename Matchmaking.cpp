#include "Matchmaking.hpp"

Matchmaking::Matchmaking() {
    this->size = 0;
}

Matchmaking::~Matchmaking() {}

bool Matchmaking::insert(Player player) {
    if (this->size >= MAX_PLAYERS) return false;
    this->players[size++] = player;
    return true;
}

bool Matchmaking::removePlayer(int id) {
    for (int i = 0; i < size; i++) {
        if (this->players[i].getId() == id) {
            for (int j = i; j < size - 1; j++) {
                players[j] = players[j + 1];
            }
            size--;
            return true;
        }
    }
    return false;
}

void Matchmaking::sortByScoreInsertion() {
    for (int i = 1; i < size; i++) {
        Player key = players[i];
        int j = i - 1;

        while (j >= 0 && (players[j].getScore() > key.getScore() || 
                        (players[j].getScore() == key.getScore() && 
                        players[j].getTimestamp() > key.getTimestamp()))) {
            players[j + 1] = players[j];
            j--;
        }
        players[j + 1] = key;
    }
}

Player* Matchmaking::merge(Player* players1, int n, Player* players2, int m) {
    Player* aux = new Player[m + n];

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (players1[i].getScore() < players2[j].getScore()) {
            aux[i + j] = players1[i];
            i++;
        } else if (players1[i].getScore() > players2[j].getScore()) {
            aux[i + j] = players2[j];
            j++;
        } else {
            if (players1[i].getTimestamp() <= players2[j].getTimestamp()) {
                aux[i + j] = players1[i];
                i++;
            } else {
                aux[i + j] = players2[j];
                j++;
            }
        }
    }

    while (i < n) {
        aux[i + j] = players1[i];
        i++;
    }

    while (j < m) {
        aux[i + j] = players2[j];
        j++;
    }

    return aux;
}

Player* Matchmaking::mergeSort(Player* arr, int n) {
    if (n == 1) {
        Player* single = new Player[1];
        single[0] = arr[0];
        return single;
    }

    int mid = n / 2;

    Player* left = mergeSort(arr, mid);
    Player* right = mergeSort(arr + mid, n - mid);

    Player* sorted = merge(left, mid, right, n - mid);

    delete[] left;
    delete[] right;

    return sorted;
}

void Matchmaking::sortByScoreMerge() {
    Player* result = mergeSort(players, size);
    for (int i = 0; i < size; i++) {
        players[i] = result[i];
    }

    delete[] result;
}

Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {
    for (int i = 0; i < size; i++) {
        int j = i;

        Player* result = new Player[groupSize];

        while (j < size && j - i < groupSize && players[j].getScore() - players[i].getScore() <= delta) {
            result[j - i] = players[j];
            j++;
        }

        if (j - i == groupSize) {
            for (int k = i; k < size - groupSize; k++) {
                players[k] = players[k + groupSize];
            }

            size -= groupSize;

            *n = groupSize;
            return result;
        }

        delete[] result;
    }

    *n = 0;
    return nullptr;
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
    std::cout << "Waiting Players" << std::endl;
    if (size == 0) {
        std::cout << "(empty)" << std::endl;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "[ " << players[i].getId() <<
         " | " << players[i].getName() << " | " <<
         players[i].getScore() << " | " <<
         players[i].getTimestamp() << " ]" << std::endl;
    }
    std::cout << std::endl;
}