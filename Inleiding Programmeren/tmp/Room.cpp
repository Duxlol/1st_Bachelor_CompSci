#include "Room.h"
#include <algorithm>

void Room::render(sf::RenderWindow* window) const {
    Player* player = nullptr;
    std::vector<Entity*> others = {};
    for (Entity* entity : entities) {
        if (auto* floor = dynamic_cast<Floor*>(entity)) {floor->render(window);}
        else if (auto* p = dynamic_cast<Player*>(entity)) { player = p;}
        else { others.push_back(entity); }
    }
    for (Entity* e : others) { e->render(window); }
    if (player) { player->render(window);}
}

//Room::~Room() {
//    for (Entity* entity : entities) {
//        delete entity;  // Free each Entity object
//    }
//    entities.clear();  // Clear the vector
//}

void Room::update(sf::Event* event) {

    Player* player = nullptr;
    Position previousPlayerPos;

    // find player to store prev pos, so we can move back if theres a wall
    for (Entity* entity : entities) {
        if (Player* p = dynamic_cast<Player*>(entity)) {
            player = p;
            previousPlayerPos = player->getPosition();
            break;
        }
    }

    // update all entities
    for (Entity* entity : entities) {
        entity->update(event);
    }

    // if player is found, check interactions
    if (player) {
        std::vector<Entity*> deletedEntities;

        for (Entity* entity : entities) { // add entities to delete to deletedEntities vector
            if (entity != player && player->standsOn(*entity)) {
                Entity* deleteEntity = entity->interacts(player, previousPlayerPos);
                if (deleteEntity) {
                    Floor* floor = new Floor();
                    floor->setPosition(deleteEntity->getPosition());
                    floor->setSprite("../resources/floor.png");
                    addEntity(floor);
                    deletedEntities.push_back(deleteEntity);
                }
            }
        }

        // delete the entities in deletedEntities vector
        for (Entity* entity : deletedEntities) {
            std::vector<Entity*>::iterator it = std::find(entities.begin(), entities.end(), entity); // iterator over a vector from (https://www.geeksforgeeks.org/how-to-use-iterator-with-vector-in-cpp/)
            if (it != entities.end()) { // as long as the iterator isnt at the end of entities, keep erasing
                entities.erase(it);
                delete entity;
            }
        }
    }
}
std::vector<Entity*> Room::getEntities() const {
    return entities;
}

void Room::addEntity(Entity* entity) {
    entities.push_back(entity);
}
