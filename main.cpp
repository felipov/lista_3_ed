#include <iostream>
#include <string>
#include <chrono>
#include "Player.hpp"
#include "Matchmaking.hpp"

// Testes do sistema
void systemTests() {
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

    // Escolha: true para insertion sort, false para merge sort
    bool decision_sort = false;
    if (decision_sort == false) {
        system.sortByScoreInsertion();
    } else {
        system.sortByScoreMerge();
    }

    system.printWaitingPlayers();

    int n1;

    Player* grupo1 = system.formGroup(3, 30, &n1);
    std::cout << "n1 = " << n1 << std::endl;
    system.printWaitingPlayers();

    int n2;
    Player* grupo2 = system.formGroup(3, 30, &n2);
    std::cout << "n2 = " << n2 << std::endl;
    system.printWaitingPlayers();

    int n3;
    Player* result = system.getWaitingPlayers(&n3);
    std::cout << "n3 = " << n3 << std::endl;
    delete[] result;

    system.printWaitingPlayers();
    
    system.removePlayer(1);
    system.printWaitingPlayers();

    system.removePlayer(5);
    system.removePlayer(6);
    system.printWaitingPlayers();

    system.printGroup(grupo1, n1);
    system.printGroup(grupo2, n2);

    if (grupo1 != nullptr) {
        delete[] grupo1;
    }
    if (grupo2 != nullptr) {
        delete[] grupo2;
    }
}

// Testes de desempenho

// Semente padrão para gerar os testes

const unsigned long long seed = 894734576498576;

// Funções para geração dos testes

int pseudoaleatory(unsigned long long& seed) {
    const unsigned long long a = 1664525;
    const unsigned long long c = 1013904223;
    const unsigned long long m = 4294967296;

    seed = (a * seed + c) % m;

    return (seed % 3001);
}

Player* newPlayers(int size, int n, unsigned long long seed) {
    Player* data = new Player[size];

    for (int i = 0; i < size; i++) {
        std::string name = std::to_string(n);
        int score = pseudoaleatory(seed);
        Player player(n , name, score, n);
        data[i] = player;
        n++;
    }
    return data;
}

auto insertionSortTests(int n) {
    Matchmaking system_test;
    Player* data = newPlayers(n, 1, seed);

    for (int i = 0; i < n; i++) {
        system_test.insert(data[i]);
    }

    delete[] data;

    auto start = std::chrono::high_resolution_clock::now();
    system_test.sortByScoreInsertion();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = end - start;

    auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    return durationMs;
}

auto mergeSortTests(int n) {
    Matchmaking system_test;
    Player* data = newPlayers(n, 1, seed);

    for (int i = 0; i < n; i++) {
        system_test.insert(data[i]);
    }

    delete[] data;

    auto start = std::chrono::high_resolution_clock::now();
    system_test.sortByScoreMerge();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = end - start;

    auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    return durationMs;
}

// Implementação dos testes

void performanceTests(int n) {
    auto sum_insertion = 0;
    auto sum_merge = 0;
    for (int i = 0; i < 10; i++) {
        auto temp_insert = insertionSortTests(n);
        sum_insertion += temp_insert;
    }

    for (int i = 0; i < 10; i++) {
        auto temp_merge = mergeSortTests(n);
        sum_merge += temp_merge;
    }

    auto mean_insertion = sum_insertion / 10;
    auto mean_merge = sum_merge / 10;

    std::cout << "Tempo médio gasto pelo Insertion Sort: " << mean_insertion << " ms." << std::endl;
    std::cout << "Tempo médio gasto pelo Merge Sort: " << mean_merge << " ms." << std::endl;
    std::cout << std::endl;
}

void runPerformanceTests() {
    performanceTests(1000);
    performanceTests(5000);
    performanceTests(10000);
    performanceTests(25000);
    performanceTests(50000);
    performanceTests(100000);
}

int main() {

    // Escolha o teste que deseja gerar: true para o sistema, false para os testes de desempenho
    bool system = false;

    if (system == true) {
        systemTests();
    } else {
        runPerformanceTests();
    }

}