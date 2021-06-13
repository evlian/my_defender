/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** header
*/

#ifndef my_defender
#define my_defender
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include "my.h"

#define W_WIDTH 1024
#define W_HEIGHT 576
#define FRAME_RATE 60
#define BITS_PER_PIXEL 24

#define DIR_DOWN 0
#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 3

// attack types
#define ATK_SLOW_DOWN 1
#define ATK_LASER 2
#define ATK_MORTAR 3
#define ATK_ARROW 4

// buttons states
#define BTN_IDLE 0
#define BTN_HOVER 1

#define NO_ARG -84

#define GAME_TITLE "Tower Defense"

// GAME STATES
#define ST_INTRO 0
#define ST_PAUSE 1
#define ST_INGAME 2
#define ST_GAMEOVER 3

typedef struct game_instance game_instance;
typedef struct tower tower;

typedef struct sound_buffers {
    sfSoundBuffer *hover;
    sfSoundBuffer *click;
    sfSoundBuffer *enemy_dies;
    sfSoundBuffer *intro_music;
    sfSoundBuffer *game_music;
    sfSoundBuffer *pause;
    sfSoundBuffer *tower_placed;
    sfSoundBuffer *archer;
    sfSoundBuffer *mortar;
} sound_buffers;

typedef struct sounds {
    sfSound *hover;
    sfSound *click;
    sfSound *enemy_dies;
    sfSound *intro_music;
    sfSound *game_music;
    sfSound *pause;
    sfSound *tower_placed;
    sfSound *archer;
    sfSound *mortar;
} sounds;

typedef struct textures {
    sfTexture *ui;
    sfTexture *enemies;
    sfTexture *coin;
    sfTexture *intro;
    sfTexture *game_over;
} textures;

typedef struct button {
    char *text;
    int state;
    sfVector2f position;
    sfVector2f size;
    void (*on_click)(game_instance *);
} button;

typedef struct buttons {
    button play;
    button instructions;
    button resume;
    button quit;
    button scores;
    button restart;
    button main_menu;
    button settings;
} buttons;

typedef struct sprites {
    sfSprite *enemy;
    sfSprite *tower;
    sfSprite *coin;
    sfSprite *intro;
    sfSprite *game_over;
    sfSprite *button;
    sfSprite *bullet;
} sprites;

typedef struct enemy {
    float health;
    float max_health;
    short path_index;
    float speed;
    float slow_attack;
    short direction;
    short type;
    sfVector2f position;
    sfIntRect texture_rect;
    sfClock *clock;
    struct enemy *next;
} enemy;

typedef struct bullet {
    float attack_time;
    sfVector2f position;
    sfIntRect texture_rect;
    tower *parent;
    enemy *target;
    int start;
    int end;
    struct bullet *next;
} bullet;

typedef struct tower {
    float attack;
    int radius;
    int attack_type;
    int price;
    char *name;
    sfClock *attack_clock;
    sfColor color;
    sfIntRect texture;
    sfVector2f position;
    bullet *bullet;
    struct tower *next;
} tower;

typedef struct tile {
    sfIntRect rect;
    short is_path;
    short is_selected;
    short is_tower_host;
} tile;

typedef struct tileset {
    sfTexture *texture;
    int size;
    int tile_size;
} tileset;

typedef struct tilemap {
    tile **layer1;
    tile **layer2;
    sfSprite *tile_sprite;
    int rows;
    int cols;
    sfVector2i last_selected;
    int *path;
} tilemap;

typedef struct shapes {
    sfRectangleShape *tower_bar;
    sfRectangleShape *pause_background;
    sfRectangleShape *hp_bar;
    sfRectangleShape *hp_bar_outline;
    sfRectangleShape *tower_highlighter;
    sfRectangleShape *info_panel;
    sfRectangleShape *scores_panel;
    sfRectangleShape *settings_panel;
    sfCircleShape *radius;
    sfCircleShape *winter;
    sfVertexArray *laser;
    sfVertex point_one;
    sfVertex point_two;
} shapes;

typedef struct game_instance{
    sfRenderWindow *window;
    tilemap tilemap;
    tileset tileset;
    sound_buffers sound_buffers;
    sounds sounds;
    sfFont *font;
    textures textures;
    tower *selected_tower;
    tower *tower_choices;
    sprites sprites;
    shapes shapes;
    buttons buttons;
    button **main_menu_buttons;
    button **pause_menu_buttons;
    sfText *text;
    enemy *enemies;
    enemy *enemy_types;
    tower *towers;
    char *instructions;
    sfEvent event;
    sfImage *icon;
    sfClock *spawn_clock;
    bullet *bullets;
    bullet *bullet_types;
    float enemy_health;
    int *scores;
    int enemy_wave;
    int amount_of_enemies;
    int highlighted_tower;
    int state;
    int show_instructions;
    int show_scores;
    int show_settings;
    int build_mode;
    int score;
    int money;
    int level;
} game_instance;

//functions
sfVideoMode new_video_mode(int width, int height, int bits_per_pixel);
void init(game_instance *game);
void dispose(game_instance *game);
void display(game_instance *game);
int **init_2d_array(int rows, int cols);
int **csv_to_array(char *file_path);
void manage_events(game_instance *game);
sfIntRect new_int_rect(int width, int height, int left, int top);
sfIntRect get_tile(int tile_size, int tile_number, int width);
void init_tilemap(game_instance *game);
void display_tilemap(game_instance *game);
sfVector2f new_vector_2f(float x, float y);
sfColor new_color(int r, int g, int b, int a);
void set_vector_2i(sfVector2i *vector, int y, int x);
void display_enemies(game_instance *game);
sfVector2i new_vector_2i(int x, int y);
void add_enemy(game_instance *game);
void init_enemies(game_instance *game);
void remove_dead_enemies(game_instance *game);
void handle_logic(game_instance *game);
void move_enemies(game_instance *game);
void init_path(game_instance *game);
void manage_pause_event(game_instance *game);
void display_menu(game_instance *game);
void animate_enemy(enemy *enemy);
void init_towers(game_instance *game);
void display_towers(game_instance *game);
void add_tower(game_instance *game, sfVector2f position);
void attack_enemies(game_instance *game);
void init_money(game_instance *game);
void display_money(game_instance *game);
void init_text(game_instance *game);
void display_text(game_instance *game, char const *string);
void display_level(game_instance *game);
void display_number(game_instance *game, int number);
void init_score(game_instance *game);
void display_tower_radius(game_instance *game);
tower add_tower_choice(game_instance *game, sfIntRect t, int atk, int r, int atk_tp, int price, char *name, sfColor color);
void set_vector_2f(sfVector2f *vector, float y, float x);
void manage_menu_events(game_instance *game);
void manage_game_over_events(game_instance *game);
void manage_in_game_events(game_instance *game);
void manage_intro_events(game_instance *game);
void init_intro(game_instance *game);
void init_game_over(game_instance *game);
void display_intro(game_instance *game);
void init_ui(game_instance *game);
void display_button(game_instance *game, button *button);
sfIntRect vector_to_rect(sfVector2f pos, int w, int h);
void play_button(game_instance *game);
void quit_button(game_instance *game);
char *read_file(char *file_path);
void init_instructions(game_instance *game);
void display_instructions(game_instance *game);
void init_sounds(game_instance *game);
void play_sounds(game_instance *game);
void init_bullets(game_instance *game);
int in_circle(sfVector2f center, int radius, sfVector2f target);
void shoot_bullet(game_instance *game, tower *tower, enemy *target);
void display_bullets(game_instance *game);
void move_bullets(game_instance *game);
void hit_target(game_instance *game);
int is_game_over(game_instance *game, sfVector2f pos);
void display_game_over(game_instance *game);
int is_hovering(game_instance *game, button **b);
void manage_button_hover(game_instance *game, sfVector2i mouse, button **b);
void manage_button_click(game_instance *game, button **b);
void manage_pause_events(game_instance *game);
void main_menu_button(game_instance *game);
void restart_button(game_instance *game);
void play_music(game_instance *game);
void resume_button(game_instance *game);
void display_instructions(game_instance *game);
void toggle_instructions(game_instance *game);
void toggle_scoreboard(game_instance *game);
void spawn_enemies(game_instance *game);
void free_enemies(game_instance *game);
void free_towers(game_instance *game);
void free_bullets(game_instance *game);
void reset_game(game_instance *game);
void set_settings(game_instance *game);
void destroy_sounds(game_instance *game);
void free_lists(game_instance *game);
void destroy_textures(game_instance *game);
void destroy_sprites(game_instance *game);
void load_scores(game_instance *game);
int get_rows_len(char *string);
int get_cols_len(char *string);
void save_score(game_instance *game);
int sort(int *list, int size, int ascending);
void init_scoreboard(game_instance *game);
void display_scoreboard(game_instance *game);
int array_len(int *arr);
void animate_panel(game_instance *game, sfRectangleShape *r);
#endif /* !my_defender */
