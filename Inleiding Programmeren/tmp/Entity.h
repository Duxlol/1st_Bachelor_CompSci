//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Player;

struct Position {
    int x;
    int y;
};

class Entity {
public:
    virtual void update(sf::Event* event);

    virtual Entity* interacts(Player* player, const Position& previousPos) {
        return nullptr;
    }

    // Onderstaande functies niet aanpassen!
    void setSprite(const std::string &img_path);
    void render(sf::RenderWindow *painter);
    virtual ~Entity() {};
    // position getter and setter
    Position getPosition() const;
    void setPosition(const Position& pos);

    //stands on
    bool standsOn(const Entity& other) const;

private:
    Position position;
    sf::Sprite sprite;
    sf::Texture texture;
};


class Player : public Entity {
public:
    void update(sf::Event* event) override;

    //getter and setter attackpower
    int getAttackPower() const;
    void setAttackPower(int newAttackPower);

private:
    int attackpower;
};

class Wall : public Entity {
public:
    Entity* interacts(Player* player, const Position& previousPos) override {
        player->setPosition(previousPos); // move back when hitting wall
        return nullptr;
    }
};
class Weapon : public Entity {
public:
    Entity* interacts(Player* player, const Position& previousPos) override;
private:
    int weaponPower = 1;
};

class Enemy : public Entity {
    Entity* interacts(Player* player, const Position& previousPos) override;
};

class Floor : public Entity {};


#endif //ENTITY_H
