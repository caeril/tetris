/* date = August 10th 2020 3:36 pm */

#ifndef TETRIS_H
#define TETRIS_H

unsigned long rando();

struct Pos {
    int X;
    int Y;
};

static int tetrinoCount = 7;


struct Sprite {
    int Blocks[16];
};



Sprite* InitSprites( );
void RotateSprite( Sprite* sprites, int index );


#endif //TETRIS_H
