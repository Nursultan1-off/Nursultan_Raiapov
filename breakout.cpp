#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"
#include "raylib.h"



void move_ball();
bool is_ball_inside_level();

void load_fonts();
void unload_fonts();
void load_textures();
void unload_textures();
void load_sounds();
void unload_sounds();

void update()
{
    switch (game_state) {
    case menu_state:
        if (IsKeyPressed(KEY_ENTER))
            game_state = in_game_state;
        break;
    case in_game_state:
        if (IsKeyPressed(KEY_SPACE)) {
            game_state = paused_state;
        }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            move_paddle(-paddle_speed);
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            move_paddle(paddle_speed);
        }
        move_ball();
        if (!is_ball_inside_level()) {
            game_state = dead_end_state;
            init_victory_menu();
        } else if (current_level_blocks == 0) {
            load_level(1);
        }
        break;
    case paused_state:
        if (IsKeyPressed(KEY_SPACE)) {
            game_state = in_game_state;
        }
        break;
    case dead_end_state:
        if (IsKeyPressed(KEY_ENTER)) {
            load_level();
            game_state = in_game_state;
        }
        break;
    case victory_state:
        if (IsKeyPressed(KEY_ENTER)) {
            game_state = menu_state;
        }
        break;
    }
}

void draw()
{
    switch (game_state) {
    case menu_state:
        draw_menu();
        break;
    case in_game_state:
        draw_level();
        draw_paddle();
        draw_ball();
        draw_ui();
        break;
    case paused_state:
        draw_pause_menu();
        break;
    case dead_end_state:
        draw_dead_end_menu();
        break;
    case victory_state:
        draw_victory_menu();
        break;
    }
}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "Breakout");
    SetTargetFPS(60);

    load_fonts();
    load_textures();
    load_level();
    load_sounds();

    while (!WindowShouldClose()) {
        BeginDrawing();
        draw();
        update();
        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}
