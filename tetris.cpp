#include "tetris.h"
#include <stdio.h>


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

Tetrino* InitTetrinos( ) {
    
    printf( "Initializing Tetrinoes!\n");
    
    Tetrino* Tetrinos = new Tetrino[4];
    
    // OO
    // OO
    Tetrinos[0].Blocks[0] = Pos{ 0,0 };
    Tetrinos[0].Blocks[1] = Pos{ 0,1 };
    Tetrinos[0].Blocks[2] = Pos{ 1,0 };
    Tetrinos[0].Blocks[3] = Pos{ 1,1 };
    
    // OO
    //  OO
    Tetrinos[1].Blocks[0] = Pos{ 0,0 };
    Tetrinos[1].Blocks[1] = Pos{ 1,0 };
    Tetrinos[1].Blocks[2] = Pos{ 1,1 };
    Tetrinos[1].Blocks[3] = Pos{ 2,1 };
    
    //  OO
    // OO
    Tetrinos[2].Blocks[0] = Pos{ 1,0 };
    Tetrinos[2].Blocks[1] = Pos{ 0,1 };
    Tetrinos[2].Blocks[2] = Pos{ 2,0 };
    Tetrinos[2].Blocks[3] = Pos{ 1,1 };
    
    
    // O
    // OOO
    Tetrinos[3].Blocks[0] = { 0,0 };
    Tetrinos[3].Blocks[1] = { 0,1 };
    Tetrinos[3].Blocks[2] = { 1,1 };
    Tetrinos[3].Blocks[3] = { 2,1 };
    
    return Tetrinos;
}
