/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <ncurses.h>
#include <game/RenderingSystem.h>
#include <game/PlayerEntity.h>
#include "game/Game.h"

void Game::SetupGraphics() {
    initscr();
    raw();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}
void Game::SetupECS() {
    engine = new ECS::Engine();
    engine->GetSystemManager()->CreateAndGet<RenderingSystem>();

    engine->GetEntityManager()->CreateAndGet<PlayerEntity>();
    // TODO: add all systems, components, entities
    // By the way, we can load them from config files!
}
void Game::Loop() {
    engine->Loop();
}
void Game::Teardown() {
    endwin();
}
void Game::Start() {
    SetupGraphics();
    SetupECS();
    Loop();
    Teardown();
}