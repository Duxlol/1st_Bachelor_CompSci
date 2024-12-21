//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room {
public:
    // Deze functie niet aanpassen! //
    void render(sf::RenderWindow* window) const;
    /////////////

    void update(sf::Event* event);

    std::vector<Entity*> getEntities() const; // getter entities in room
    std::vector<Entity*>& getEntities() { return entities; } // getter entities which is non const for setCurrentRoom
    void addEntity(Entity* entity); // adder for entities


private:
    std::vector<Entity*> entities;
};



#endif //ROOM_H
