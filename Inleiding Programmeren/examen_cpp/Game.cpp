#include "Game.h"
#include <fstream>
#include <iostream>
Game::Game(sf::RenderWindow* window) {
    this->window = window;
}

void Game::update() {
    setCurrentRoom();
    this->window->clear();
    if (currentRoom) { currentRoom->render(this->window); }
    this->window->display();
    while (window->isOpen()) {
        sf::Event event;

        // Wait for event to fire
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            } else if (event.type == sf::Event::KeyPressed) {
                currentRoom->update(&event);
                setCurrentRoom();
                this->window->clear();
                currentRoom->render(this->window);
                this->window->display();
            }
        }
    }

}

void Game::loadMap() {
    std::ifstream mapTxt("../resources/map.txt");
    if (currentRoom == nullptr) {
        currentRoom = new Room(); // maak een nieuwe kamer als er nog geen is
    }
    int y = 0;
    std::string line;

    while (std::getline(mapTxt, line)) { // loop to read lines from inginious friday week 8 ex7
        for (int x = 0; x < line.size(); x++) { //go over each x (row), line.size times (columns)
            char tile = line[x];
            int absoluteX = x * 100;
            int absoluteY = y * 100;

            // cases to check each character
            switch (tile) {

                //wall
                case '#': { //
                    Wall* wall = new Wall();
                    Position pos = {absoluteX, absoluteY};
                    wall->setPosition(pos);
                    wall->setSprite("../resources/wall.png");
                    currentRoom->addEntity(wall);
                    break;
                }

                // floor
                case '_': {
                    Floor* floor = new Floor();
                    Position pos = {absoluteX, absoluteY};
                    floor->setPosition(pos);
                    floor->setSprite("../resources/floor.png");
                    currentRoom->addEntity(floor);
                    break;
                }

                // player
                case '@': {
                    Player* player = new Player();
                    Position pos = {absoluteX, absoluteY};
                    player->setPosition(pos);
                    player->setSprite("../resources/player.png");
                    currentRoom->addEntity(player);

                    this->currentRoom = currentRoom;
                    break;
                }

                //enemy
                case '%': {
                    Enemy* enemy = new Enemy();
                    Position pos = {absoluteX, absoluteY};
                    enemy->setPosition(pos);
                    enemy->setSprite("../resources/enemy.png");
                    currentRoom->addEntity(enemy);
                    break;
                }

                // weapon
                case '!': {
                    Weapon* weapon = new Weapon();
                    Position pos = {absoluteX, absoluteY};
                    weapon->setPosition(pos);
                    weapon->setSprite("../resources/weapon.png");
                    currentRoom->addEntity(weapon);
                    break;
                }
                default: {
                    std::cout << "Invalid character.";
                    break;
                }

            }
        }
        y++;
    }
}
void Game::setCurrentRoom() {


}