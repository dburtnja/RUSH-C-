//
// Created by Denys Burtnjak on 6/24/18.
//

#include "Boss.hpp"
#include "constants.hpp"

void Boss::move(Player *player) {
    if (player->getX() < this->_coord_y)
        this->_coord_y--;
    if (player->getX() > this->_coord_y)
        this->_coord_y++;
}

Boss::Boss() {
    this->_boardView = "BOSS";
    this->_coord_x = WINDOW_W - 10;
    this->_coord_y = WINDOW_H / 2;
    _bullets = new Bullet[12];
}

Boss::Boss(Boss const &obj) {
    *this = obj;
}

Boss::~Boss() {
    delete[](_bullets);
}

void Boss::display(WINDOW *window) {
    mvwprintw(window, _coord_y, _coord_x, "%s", _boardView.c_str());
    mvwprintw(window, _coord_y + 1, _coord_x, "%s", "    ");
    mvwprintw(window, _coord_y - 1, _coord_x, "%s", "    ");
}

void Boss::setAndActivateBullets() {
    for (int i = 0; i < 12; i++) {
        _bullets[i].setActivation();
        _bullets[i].setCoords((_coord_y + i) - 6, _coord_x - 1);
    }
    system("afplay -t 2 ./sounds/Heavy-machine-gun-rapid-fire-sound-effect.mp3 &");
}

void	Boss::moveBulletsAndDisplay(WINDOW *window)
{
    int i = 0;

    while (i < 12)
    {
        _bullets[i].move("left");
        _bullets[i].display(window, "left");
        i++;
    }
}

Bullet *Boss::getBullets() {
    return this->_bullets;
}

void Boss::killPlayer(Player *player) {
    if (!_bullets->getActivation())
        return;
    for (int i = 0; i < 12; i++) {
        if (_bullets[i].getBulletY() == player->getY() && _bullets[i].getBulletX() == player->getX())
        {
            player->decrementHP();
        }
    }
}

Boss &Boss::operator=(Boss const &obj) {
    if (this == &obj)
        return *this;
    this->_coord_y = obj._coord_y;
    this->_coord_y = obj._coord_x;
    this->_prev_y = obj._prev_y;
    this->_prev_x = obj._prev_x;
    this->_bullets = obj._bullets;
    return *this;
}
