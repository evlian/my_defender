/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_ui
*/
#include "../../include/defender.h"

void init_button_functions(game_instance *game)
{

}

void init_menus(game_instance *game)
{
    game->main_menu_buttons = (button **) malloc(sizeof(button *) * 5);
    game->pause_menu_buttons = (button **) malloc(sizeof(button *) * 7);
    game->main_menu_buttons[0] = &game->buttons.play;
    game->main_menu_buttons[1] = &game->buttons.instructions;
    game->main_menu_buttons[2] = &game->buttons.scores;
    game->main_menu_buttons[3] = &game->buttons.quit;
    game->main_menu_buttons[4] = NULL;
    game->pause_menu_buttons[0] = &game->buttons.resume;
    game->pause_menu_buttons[1] = &game->buttons.restart;
    game->pause_menu_buttons[2] = &game->buttons.main_menu;
    game->pause_menu_buttons[3] = &game->buttons.scores;
    game->pause_menu_buttons[4] = &game->buttons.instructions;
    game->pause_menu_buttons[5] = &game->buttons.quit;
    game->pause_menu_buttons[6] = NULL;
}

void init_buttons(game_instance *game)
{
    game->buttons.play.text = "PLAY";
    game->buttons.resume.text = "RESUME";
    game->buttons.instructions.text = "INSTRUCTIONS";
    game->buttons.quit.text = "QUIT";
    game->buttons.scores.text = "SCOREBOARD";
    game->buttons.restart.text = "RESTART";
    game->buttons.main_menu.text = "MAIN MENU";
    game->buttons.play.on_click = &play_button;
    game->buttons.quit.on_click = &dispose;
    game->buttons.resume.on_click = &resume_button;
    game->buttons.restart.on_click = &restart_button;
    game->buttons.main_menu.on_click = &main_menu_button;
    game->buttons.instructions.on_click = &toggle_instructions;
    game->buttons.scores.on_click = &toggle_scoreboard;
}

void init_ui(game_instance *game)
{
    game->textures.ui = sfTexture_createFromFile("./res/buttons.png", NULL);
    game->sprites.button = sfSprite_create();
    sfSprite_setTexture(game->sprites.button, game->textures.ui, sfTrue);
    init_buttons(game);
    init_menus(game);
}