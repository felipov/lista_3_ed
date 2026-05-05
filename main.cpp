#include "matchmakingSystem.cpp"

int main() {
    Matchmaking* mm = new Matchmaking();
    Player* felipo = new Player(1, "felipo", 0, 0);
    Player* gabiela = new Player(2, "gabiela", 10, 1);

    Matchmaking->insert(felipo);


    return 0;
}