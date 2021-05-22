/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** utils
*/

#include <SFML/Graphics.h>

sfVector3f generate_color(unsigned int value)
{
    if (value == 0)
        return ((sfVector3f) {0.5, 0.5, 0.5});
    value %= 6;
    switch (value) {
        case 1:
            return ((sfVector3f) {1.0, 0.0, 0.0});
        case 2:
            return ((sfVector3f) {0.0, 1.0, 0.0});
        case 3:
            return ((sfVector3f) {0.0, 0.0, 1.0});
        case 4:
            return ((sfVector3f) {1.0, 0.0, 1.0});
        case 5:
            return ((sfVector3f) {1.0, 1.0, 0.0});
        case 6:
            return ((sfVector3f) {0.0, 1.0, 1.0});
        default:
            return ((sfVector3f) {0.8, 0.8, 0.8});
    }
}
