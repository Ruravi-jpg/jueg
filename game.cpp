
#include <iostream>
#include <vector>

#include "raylib.h"
#include "Player.h"
#include "raymath.h"
#include "AnimationList.h"
#include "Entity.h"
#include "Tile.h"
#include "Collisions.h"

#include <iostream>

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1

void getCoor() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        std::cout << "X: " << GetMousePosition().x << "Y: " << GetMousePosition().y << std::endl;
    }
}


void initGame(Player& player, Collisions& collision, Entity& enemy);
void initGame(Collisions& collision, std::vector<Entity>& entitys);
void loadPlayer(Player& player);
void loadPlayer(Entity& player);
void loadEnemy(Entity& enemy);
int loadMenu();
void loadLevel1(Player& player, Collisions& collision, Entity& enemy);
void loadLevel1(Collisions& collision, std::vector<Entity>& entitys);
void loadLevel2(Player& player, Collisions& collision);
void drawLevel(Player& player, Collisions& collision, Entity& enemy);
void drawLevel(Collisions& collision, std::vector<Entity>& entitys);

void input(Entity& player);


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - texture rectangle");

    Player player;
    Entity enemy, enemy2, enemy3;
    Collisions coll;

    std::vector<Entity> entities;
    entities.push_back(player);
    entities.push_back(enemy);
    entities.push_back(enemy2);
    entities.push_back(enemy3);

    int level;

    //initGame(player, coll, enemy);
    initGame(coll, entities);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        getCoor();

         // Draw
         //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);


        //drawLevel(player, coll, enemy);
        drawLevel(coll, entities);
  
        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}


void initGame(Player& player, Collisions& collision, Entity& enemy) {

    loadPlayer(player);
    loadEnemy(enemy);

    int level = 1;
    

    switch (level)
    {
    case 0 :
        loadMenu();
        break;
    case 1:
        loadLevel1(player, collision, enemy);
        break;
    case 2:
        loadLevel2(player, collision);
    default:
        break;
    }

}

void initGame(Collisions& collision, std::vector<Entity>& entitys)
{
    loadPlayer(entitys[0]);
    loadEnemy(entitys[1]);
    loadEnemy(entitys[2]);
    loadEnemy(entitys[3]);

    int level = 1;


    switch (level)
    {
    case 0:
        loadMenu();
        break;
    case 1:
        loadLevel1(collision,entitys);
        break;
    case 2:
        //loadLevel2(player, collision);
    default:
        break;
    }
}

void loadPlayer(Player& player)
{
    Texture2D Walk = LoadTexture("Textures/PlayerTexture/Walk.png");        // Texture loading
    Texture2D Idle = LoadTexture("Textures/PlayerTexture/Idle.png");
    Texture2D Jump = LoadTexture("Textures/PlayerTexture/Jump.png");

    AnimationSt walk(Walk, 3, 1, 8);

    AnimationSt idle(Idle, 4, 1, 6);

    AnimationSt jump(Jump, 1, 1, 8);

    std::vector<AnimationSt> lista;

    lista.push_back(walk);
    lista.push_back(idle);
    lista.push_back(jump);

    AnimationList list(lista);

    

    player.setList(list);

}

void loadPlayer(Entity& player)
{
    Texture2D Walk = LoadTexture("Textures/PlayerTexture/Walk.png");        // Texture loading
    Texture2D Idle = LoadTexture("Textures/PlayerTexture/Idle.png");
    Texture2D Jump = LoadTexture("Textures/PlayerTexture/Jump.png");

    AnimationSt walk(Walk, 3, 1, 8);

    AnimationSt idle(Idle, 4, 1, 6);

    AnimationSt jump(Jump, 1, 1, 8);

    std::vector<AnimationSt> lista;

    lista.push_back(walk);
    lista.push_back(idle);
    lista.push_back(jump);

    AnimationList list(lista);



    player.setList(list);
}

void loadEnemy(Entity& enemy)
{
    Texture2D Walk = LoadTexture("Textures/EnemyTextures/Walk.png");
    Texture2D Idle = LoadTexture("Textures/EnemyTextures/Idle.png");
    Texture2D Jump = LoadTexture("Textures/EnemyTextures/Jump.png");

    AnimationSt walk(Walk, 3, 1, 8);

    AnimationSt idle(Idle, 4, 1, 6);

    AnimationSt jump(Jump, 1, 1, 8);

    std::vector<AnimationSt> lista;

    lista.push_back(walk);
    lista.push_back(idle);
    lista.push_back(jump);

    AnimationList list(lista);

    enemy.setList(list);
}

int loadMenu()
{
    DrawText("Hola", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RED);

    if (IsKeyPressed(KEY_A)) {
        return 1;
    }
}

void loadLevel1(Player& player, Collisions& collision, Entity& enemy) {

    Vector2 position = { 470.0f, 260.0f };
    player.setPos(position);

    Vector2 positionEn = { 350, 260 };
    enemy.setPos(positionEn);

    Rectangle rdos = { 0, 400, 1000, 200 };
    Rectangle rtres = { 300, 200, 400, 10 };
    Rectangle rcuatro = { 250, 300, 100, 10 };
    Rectangle rcinco = { 650, 300, 100, 10 };

    Tile dos = { rdos, 1, LIGHTGRAY };
    Tile tres = { rtres, 1, LIGHTGRAY };
    Tile cuatro = { rcuatro, 1, LIGHTGRAY };
    Tile cinco = { rcinco, 1, LIGHTGRAY };

    std::vector<Tile> tiles;

    tiles.push_back(dos);
    tiles.push_back(tres);
    tiles.push_back(cuatro);
    tiles.push_back(cinco);

    //Collisions coll(tiles, player);

   

    collision.setPlayer(player);
    collision.setTiles(tiles);
}

void loadLevel1(Collisions& collision, std::vector<Entity>& entitys)
{
    Vector2 position = { 470.0f, 260.0f };
    entitys[0].setPos(position);

    Vector2 positionEn = { 350, 160 };
    entitys[1].setPos(positionEn);

    Vector2 positionEn2 = { 150, 260 };
    entitys[2].setPos(positionEn2);

    Vector2 positionEn3 = { 280, 260 };
    entitys[3].setPos(positionEn3);

    Rectangle rdos = { 0, 400, 1000, 200 };
    Rectangle rtres = { 300, 200, 400, 10 };
    Rectangle rcuatro = { 250, 300, 100, 10 };
    Rectangle rcinco = { 650, 300, 100, 10 };

    Tile dos = { rdos, 1, LIGHTGRAY };
    Tile tres = { rtres, 1, LIGHTGRAY };
    Tile cuatro = { rcuatro, 1, LIGHTGRAY };
    Tile cinco = { rcinco, 1, LIGHTGRAY };

    std::vector<Tile> tiles;

    tiles.push_back(dos);
    tiles.push_back(tres);
    tiles.push_back(cuatro);
    tiles.push_back(cinco);

    //Collisions coll(tiles, player);



    //collision.setPlayer(player);
    collision.setEntities(entitys);
    collision.setTiles(tiles);
}

void loadLevel2(Player& player, Collisions& collision)
{
  
    Vector2 position = { 470.0f, 260.0f };

    player.setPos(position);


    Rectangle rdos = { 0, 400, 1000, 200 };
  //  Rectangle rtres = { 300, 200, 400, 10 };
  //  Rectangle rcuatro = { 250, 300, 100, 10 };
  //  Rectangle rcinco = { 650, 300, 100, 10 };

    Tile dos = { rdos, 1, LIGHTGRAY };
   // Tile tres = { rtres, 1, LIGHTGRAY };
   //Tile cuatro = { rcuatro, 1, LIGHTGRAY };
    //Tile cinco = { rcinco, 1, LIGHTGRAY };

    std::vector<Tile> tiles;

    tiles.push_back(dos);
   // tiles.push_back(tres);
   // tiles.push_back(cuatro);
   // tiles.push_back(cinco);

    //Collisions coll(tiles, player);

    collision.setPlayer(player);
    collision.setTiles(tiles);
}

void drawLevel(Player& player, Collisions& collision, Entity& enemy)
{
    player.update();
    enemy.update();
    collision.update();
}

void drawLevel(Collisions& collision, std::vector<Entity>& entitys)
{
    input(entitys[0]);
    for (int i = 0; i < entitys.size(); i++) {
        entitys[i].update();
    }

    collision.update();
}

void input(Entity& player)
{
    Vector2 direction = { 0,0 };
    float jumpSpeed = -450;
    
        if (IsKeyDown(KEY_LEFT)) {
            //position.x -= horizontalSpeed * GetFrameTime();
            direction.x = -1;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            //position.x += horizontalSpeed * GetFrameTime();
            direction.x = 1;
        }
        if (IsKeyPressed(KEY_SPACE) and player.getOnground()) {
            //setOnground(false);
            Vector2 nPos = { player.getPosition().x, player.getPosition().y - 1 };
            player.setPos(nPos);
            player.setSpeed(jumpSpeed);
            player.setOnground(false);
            player.setOnPlataform(0);
        }

        player.setDirection(direction);
}
