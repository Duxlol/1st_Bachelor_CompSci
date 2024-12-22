#include "Game.h"
#include <fstream>
#include <iostream>
#include <algorithm>
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

void Game::loadMap(const std::string& filepath) {
    std::ifstream mapTxt(filepath);

    // error handling
    if (!mapTxt.is_open()) { // is_open from https://www.geeksforgeeks.org/std-ifstream-isopen-in-cpp/
        std::cerr << "can't open the map txt" << std::endl;
    }

    int maxWidth = 0;
    int totalHeight = 0;
    std::vector<std::string> mapLines;
    const int ROOM_SIDE = 7;  // 7x7 grid in a room


    std::string line;
    while (std::getline(mapTxt, line)) {
        maxWidth = std::max(maxWidth, static_cast<int>(line.length()));
        totalHeight++;
        mapLines.push_back(line); // put lines in maplines to add all entities in the 2nd loop
    }

    roomsWidth = (maxWidth + ROOM_SIDE - 1) / ROOM_SIDE;
    roomsHeight = (totalHeight + ROOM_SIDE - 1) / ROOM_SIDE;

    // make all rooms
    for (int y = 0; y < roomsHeight; y++) {
        for (int x = 0; x < roomsWidth; x++) {
            Room* room = new Room();
            rooms.push_back(room);      // add room to vector of rooms

        }
    }

    for (int y = 0; y < mapLines.size(); y++) { // loop to read lines from inginious friday week 8 ex7
        const std::string& line = mapLines[y];
        for (int x = 0; x < line.size(); x++) { //go over each x (row), line.size times (columns)
            char tile = line[x]; // 1 tile = 1 x
            Position pos = {x * 100, y * 100}; // scaling

            // calc in which room entity has to be
            int roomX = x / ROOM_SIDE;
            int roomY = y / ROOM_SIDE;
            Room* room = rooms[roomY * roomsWidth + roomX]; // chatgpt helped me find this formula

            // cases to check each character
            switch (tile) {

                //wall
                case '#': { //
                    Wall* wall = new Wall();
                    wall->setPosition(pos);
                    wall->setSprite("../resources/wall.png");
                    room->addEntity(wall);
                    break;
                }

                // floor
                case '_': {
                    Floor* floor = new Floor();
                    floor->setPosition(pos);
                    floor->setSprite("../resources/floor.png");
                    room->addEntity(floor);
                    break;
                }

                // player
                case '@': {
                    Player* player = new Player();
                    player->setPosition(pos);
                    player->setSprite("../resources/player.png");
                    room->addEntity(player);
                    this->currentRoom = room;

                    // make floor of starting position
                    Floor* floor = new Floor();
                    floor->setPosition(pos);
                    floor->setSprite("../resources/floor.png");
                    room->addEntity(floor);
                    break;
                }

                //enemy
                case '%': {
                    Enemy* enemy = new Enemy();
                    enemy->setPosition(pos);
                    enemy->setSprite("../resources/enemy.png");
                    room->addEntity(enemy);
                    break;
                }

                // weapon
                case '!': {
                    Weapon* weapon = new Weapon();
                    weapon->setPosition(pos);
                    weapon->setSprite("../resources/weapon.png");
                    room->addEntity(weapon);
                    break;
                }
                default: {
                    std::cout << "Invalid character.";
                    break;
                }

            }
        }
    }
}
void Game::setCurrentRoom() {
    // find player in current room
    Player* player = nullptr;
    if (currentRoom) {
        for (Entity* entity : currentRoom->getEntities()) {
            if (Player* p = dynamic_cast<Player*>(entity)) {
                player = p;
                break;
            }
        }
    }
    if (!player) return; // theres no player

    Position playerPos = player->getPosition(); // players position
    // calc in which room player is
    int roomX = playerPos.x / 700;
    int roomY = playerPos.y / 700;
    int index = roomY * roomsWidth + roomX; // chatgpt helped me find this formula, like mentioned in loadMap(), it calcs the index of the room

    // failsafe check if the index for the room actually exists or not
    if (roomX >= 0 && roomX < roomsWidth && roomY >= 0 && roomY < roomsHeight && index < rooms.size()) {
        Room* newRoom = rooms[index];

        // only change if going thru a hallway
        if (newRoom != currentRoom) {
            // move player to newroom n remove player from current romo
            if (currentRoom) {
                std::vector<Entity *>& currentEntities = currentRoom->getEntities();
                auto it = std::find(currentEntities.begin(), currentEntities.end(), player); // vector iterator from (https://www.geeksforgeeks.org/how-to-use-iterator-with-vector-in-cpp/)
                if (it != currentEntities.end()) {
                    currentEntities.erase(it);
                }
            }
            newRoom->addEntity(player); // player to newroom
            currentRoom = newRoom; // currentroom is the room we now moved to
        }
    }
}