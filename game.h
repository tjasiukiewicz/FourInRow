#pragma once

struct Game;

struct Game * game_init(void);
void game_run(struct Game * game);
