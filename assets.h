#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

#include "sprite.h"

#include "sprite.h"
extern Font menu_font;

extern Texture2D wall_texture;
extern Texture2D void_texture;
extern Texture2D paddle_texture;
extern Texture2D block_texture;

extern sprite ball_sprite;
extern Sound win_sound;
extern Sound lose_sound;

void load_fonts();
void unload_fonts();

void load_textures();
void unload_textures();

void load_sounds();
void unload_sounds();

#endif // ASSETS_H
