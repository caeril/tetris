/* date = August 10th 2020 3:36 pm */

#ifndef TETRIS_H
#define TETRIS_H

unsigned long rando();

struct Pos {
    int X;
    int Y;
};

struct Tetrino {
    Pos Blocks[4];
};


static int tetrinoCount = 4;

Tetrino* InitTetrinos( );

#endif //TETRIS_H
