#include "tetris.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long rando(void) {          //period 2^96-1
    unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    
    return z;
}

inline void CopySprite( Sprite* sprites, int index, 
                       int b0, int b1, int b2, int b3, int b4,
                       int b5, int b6, int b7, int b8,
                       int b9, int ba, int bb, int bc,
                       int bd, int be, int bf ) {
    
    sprites[index].Blocks[0] = b0;
    sprites[index].Blocks[1] = b1;
    sprites[index].Blocks[2] = b2;
    sprites[index].Blocks[3] = b3;
    sprites[index].Blocks[4] = b4;
    sprites[index].Blocks[5] = b5;
    sprites[index].Blocks[6] = b6;
    sprites[index].Blocks[7] = b7;
    sprites[index].Blocks[8] = b8;
    sprites[index].Blocks[9] = b9;
    sprites[index].Blocks[10] = ba;
    sprites[index].Blocks[11] = bb;
    sprites[index].Blocks[12] = bc;
    sprites[index].Blocks[13] = bd;
    sprites[index].Blocks[14] = be;
    sprites[index].Blocks[15] = bf;
    
}

Sprite* InitSprites( ) {
    
    Sprite* sprites = new Sprite[tetrinoCount];
    
    CopySprite( sprites, 0,
               0, 0, 0, 0,
               0, 1, 1, 0,
               0, 1, 1, 0,
               0, 0, 0, 0  );
    
    CopySprite( sprites, 1,
               0, 0, 0, 0,
               1, 1, 0, 0,
               0, 1, 1, 0,
               0, 0, 0, 0  );
    
    CopySprite( sprites, 2,
               0, 0, 0, 0,
               0, 0, 1, 1,
               0, 1, 1, 0,
               0, 0, 0, 0  );
    
    CopySprite( sprites, 3,
               0, 0, 0, 0,
               0, 0, 0, 1,
               0, 1, 1, 1,
               0, 0, 0, 0  );
    
    CopySprite( sprites, 4,
               0, 0, 0, 0,
               1, 0, 0, 0,
               1, 1, 1, 0,
               0, 0, 0, 0  );
    
    
    CopySprite( sprites, 5,
               0, 0, 0, 0,
               0, 0, 1, 0,
               0, 1, 1, 1,
               0, 0, 0, 0  );
    
    
    CopySprite( sprites, 6,
               0, 0, 0, 0,
               0, 0, 0, 0,
               1, 1, 1, 1,
               0, 0, 0, 0  );
    
    return sprites;
}

void RotateSprite( Sprite* sprites, int index ) {
    
    Sprite ns;
    Sprite os = sprites[index];
    
    ns.Blocks[0] = os.Blocks[3];
    ns.Blocks[1] = os.Blocks[7];
    ns.Blocks[2] = os.Blocks[11];
    ns.Blocks[3] = os.Blocks[15];
    ns.Blocks[4] = os.Blocks[2];
    ns.Blocks[5] = os.Blocks[6];
    ns.Blocks[6] = os.Blocks[10];
    ns.Blocks[7] = os.Blocks[14];
    ns.Blocks[8] = os.Blocks[1];
    ns.Blocks[9] = os.Blocks[5];
    ns.Blocks[10] = os.Blocks[9];
    ns.Blocks[11] = os.Blocks[13];
    ns.Blocks[12] = os.Blocks[0];
    ns.Blocks[13] = os.Blocks[4];
    ns.Blocks[14] = os.Blocks[8];
    ns.Blocks[15] = os.Blocks[12];
    
    sprites[index] = ns;
}
