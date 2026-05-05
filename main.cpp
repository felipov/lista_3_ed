#include "matchmakingSystem.cpp"

int main() {
    Matchmaking* mm = new Matchmaking();
    Player* felipo = new Player(1, "felipo", 0, 0);
    Player* gabiela = new Player(2, "gabiela", 10, 1);

    mm->insert(*felipo);
    mm->insert(*gabiela);

    mm->printWaitingPlayers();

    int n;
    Player* group = mm->formGroup(2, 10, &n);

    std::cout << "fofoletes: " << group[0].getName() << " ama " << group[1].getName() << std::endl;

    return 0;
}