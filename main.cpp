#include "raylib.h"
#include <unistd.h>
#include <stdio.h>
#include "tetris.h"

struct PlayField {
    int Width;
    int Height;
    unsigned int* Boxes;
};


int main(void) {
    
    // Initialization
    
    const int screenWidth = 480;
    const int screenHeight = 640;
    
    const int blocksize = 20;
    const int padding = 3;
    
    const int boardX = 50;
    const int boardY = 50;
    const int borderWidth = 8;
    
    
    
    
    PlayField field;
    field.Width = 10;
    field.Height = 20;
    field.Boxes = new unsigned int[field.Width*field.Height];
    
    
    Tetrino* Tetrinos = InitTetrinos();
    
    InitWindow(screenWidth, screenHeight, "caeril's tetris clone");
    
    SetTargetFPS(60);
    
    
    int tetrinoIndex = rando()%tetrinoCount;
    unsigned int frames = 0;
    int speed = 6;
    int framesPerDrop = 80/speed;
    
    int tetrinoX = 4;
    int tetrinoY = 0;
    
    
    
    while (!WindowShouldClose()) {
        
        frames++;
        if( frames % framesPerDrop == 0 ) {
            tetrinoY++;
        }
        
        if( tetrinoY > 19 ) {
            tetrinoY = 0;
            tetrinoIndex = rando()%tetrinoCount;
        }
        
        
        // Update
        
        for( int i=0; i<(field.Width*field.Height); i++ ) {
            field.Boxes[i] = 0;
        }
        
        // Draw
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // draw playing board border
        
        Rectangle border;
        border.x = boardX;
        border.y = boardY;
        border.width = field.Width*(blocksize+padding)+padding+borderWidth;
        border.height = field.Height*(blocksize+padding)+padding+borderWidth;
        
        // select a tetrino
        
        Tetrino tetrino = Tetrinos[tetrinoIndex];
        
        for( int i=0; i<4; i++ ) {
            
            int x = tetrinoX + tetrino.Blocks[i].X;
            int y = tetrinoY + tetrino.Blocks[i].Y;
            
            field.Boxes[y*field.Width+x] = 1;
        }
        
        DrawRectangleLinesEx( border, borderWidth, GREEN );
        {
            for( int x=0; x<field.Width; x++ ) {
                for( int y=0; y<field.Height; y++ ) {
                    Color color = SKYBLUE;
                    
                    unsigned int boxValue = field.Boxes[y*field.Width+x];
                    if( boxValue > 0 ) {
                        color = BLUE;
                    }
                    
                    DrawRectangle( x*(blocksize+padding)+boardX+borderWidth, 
                                  y*(blocksize+padding)+boardY+borderWidth, 
                                  blocksize, blocksize, color);
                    
                }
                
            }
            
        }
        
        EndDrawing();
        
    }
    
    // De-Initialization
    
    CloseWindow();
    
	return 0;
}
