
#include <iostream>
#include <vector>

#include "raylib.h"
#include "Player.h"
#include "raymath.h"
#include "AnimationList.h"
#include "Entity.h"
#include "Tile.h"
#include "Collisions.h"
#include "Level.h"
#include "LevelLoader.h"


//#include "LevelLoader.h"

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1

void getCoor() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        std::cout << "X: " << GetMousePosition().x << "Y: " << GetMousePosition().y << std::endl;
    }
}


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - texture rectangle");
    int one = 1;
    int two = 2;

    Level level1(one);
    LevelLoader& test = LevelLoader::get();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        getCoor();

        if (IsKeyPressed(KEY_A)) {
            level1.loadLevel(two);
        }

         // Draw
         //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        level1.drawLevel();

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Texture unloading
    level1.unloadData();
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
