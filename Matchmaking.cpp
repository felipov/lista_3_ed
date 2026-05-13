#include "matchmakingSystem.hpp"

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

        while (j >= 0 && players[j] > key) {
            players[j + 1] = players[j];
            j--;
        }
        players[j + 1] = key;
    }
}

Player* Matchmaking::mergeSort(Player* arr, int n) {
    Player* left = nullptr;
    Player* right = nullptr;
    if (n > 1) {
        int mid = n / 2;
        left = mergeSort(arr, mid);
        right = mergeSort(arr + mid, n - mid);
    } else return arr;

    Player* result = new Player[n];
    int itl = 0;
    int itr = 0;
    for (int index = 0; index < n; index++) {
        if (itl >= n / 2) {
            result[index] = right[itr++];
        }
        else if (itr >= n / 2 + (n % 2)) {
            result[index] = left[itl++];
        } else {
            if (left[itl] >= right[itr]) {
                result[index] = right[itr++];
            }
            else if (right[itr] > left[itl]) {
                result[index] = left[itl++];
            }
        }
    }
    delete[] left;
    delete[] right;
    return result;
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
    for (int i = 0; i < size; i++) {
        std::cout << players[i].getName() << std::endl;
    }
}