#pragma once

struct BoardDisplayer;


struct BoardDisplayer * board_displayer_init(void);
void board_displayer_visit(int * tab);
void board_displayer_print(void);
