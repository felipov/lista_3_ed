#include <iostream>
#include <string>
#include <chrono>
#include "Player.hpp"
#include "Matchmaking.hpp"

int main() {
    // Inicialização do sistema e dos jogadores
    Matchmaking system;
    Player p1(1, "João", 980, 1);
    Player p2(2, "Maria", 1080, 2);
    Player p3(3, "Maurício", 1110, 3);
    Player p4(4, "Joana", 1110, 4);
    Player p5(5, "Túlio", 820, 5);
    Player p6(6, "Arnaldo", 1110, 6);

    // Funcionamento do sistema
    system.insert(p1);
    system.insert(p2);
    system.insert(p3);
    system.insert(p4);
    system.insert(p5);
    system.insert(p6);

    system.printWaitingPlayers();

    bool decision_sort = false;
    if (decision_sort == false) {
        system.sortByScoreInsertion();
    } else {
        system.sortByScoreMerge();
    }

    system.printWaitingPlayers();

    int n1 = 0;

    system.formGroup(3, 30, &n1);
    std::cout << "n1 = " << n1 << std::endl;
    system.printWaitingPlayers();

    int n2 = 0;
    system.formGroup(3, 30, &n2);
    std::cout << "n2 = " << n2 << std::endl;
    system.printWaitingPlayers();

    int n3 = 0;
    Player* result;
    result = system.getWaitingPlayers(&n3);
    std::cout << "n3 = " << n3 << std::endl;
    delete[] result;

    system.printWaitingPlayers();
}