//
// Created by Tim Apers on 29/10/2024.
//

#include "Entity.h"
#include <iostream>

void Entity::setSprite(const std::string& img_path) {
    if (!this->texture.loadFromFile(img_path)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    sf::Vector2u size = this->texture.getSize();
    float scaleX = 100.0f / size.x;
    float scaleY = 100.0f / size.y;
    this->sprite.setScale(scaleX, scaleY);
}
void Entity::render(sf::RenderWindow *window) {
    sprite.setPosition(position.x%700, position.y%700);
    window->draw(sprite);
}

Position Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const Position& pos) {
    position = pos;
}

void Entity::update(sf::Event* event) {
}

bool Entity::standsOn(const Entity& other) const {
    Position otherPos = other.getPosition();
    return position.x == otherPos.x && position.y == otherPos.y;
}



void Player::update(sf::Event* event) {
    Position currentPosition = getPosition();
    Position newPosition = currentPosition;
    switch (event->key.code) {
        case sf::Keyboard::Left:
                newPosition.x -= 100;
                break;
        case sf::Keyboard::Right:
                newPosition.x += 100;
                break;
        case sf::Keyboard::Up:
                newPosition.y -= 100;
                break;
        case sf::Keyboard::Down:
                newPosition.y += 100;
                break;
        default: break;
    }
    setPosition(newPosition); // update player position
}

Entity* Weapon::interacts(Player* player, const Position& previousPos)  {
    if (player->standsOn(*this)) { // if player is on weapon
        int currentAttackPower = player->getAttackPower(); // no attackpower in currentAttackPower as player has no weapon
        int weaponBonus = this->weaponPower; // attackPower of weapon in weaponBonus (10)
        player->setAttackPower(currentAttackPower+weaponBonus); // use setter to set new player attackpower
        return this;
    }
    return nullptr;
}

Entity * Enemy::interacts(Player *player, const Position &previousPos) {
    if (player->standsOn(*this)) { // if player on enemy
        if (player->getAttackPower()<1) { //if not enough attack power
            player->setPosition(previousPos); // put player back to previous position
            return nullptr; // enemy is like a wall
        } else {
            return this; // enough attack power, enemy gets defeated
        }
    }
}

int Player::getAttackPower() const {
    return attackpower;
}
void Player::setAttackPower(int newAttackPower) {
    attackpower = newAttackPower;
}

