#include "Ui.h"

Ui& Ui::get()
{
    static Ui instance;
    return instance;
}

void Ui::drawPlayerData()
{
    return get().IdrawPlayerData();
}

Ui::Ui()
{
}

void Ui::IdrawPlayerData()
{
    Player& player = LevelLoader::get().getDataPlayer();
    std::string healtThext = "HP: ";
    healtThext += std::to_string(player.getHealth());
    DrawText(healtThext.c_str(), 100, 10, 20, BLACK);
}
