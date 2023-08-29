#include <iostream>
#include <string>

using namespace std;

class PlayerClass 
{
public:
    virtual ~PlayerClass() {}

    virtual int modifyDamage(int damage) const = 0;
    virtual int Healing(int heal) const = 0;
};

class Tank : public PlayerClass 
{
public:
    int modifyDamage(int damage) const override 
    {
        return damage;
    }
    int Healing(int heal) const override
    {
        return heal * 0;
    }
};

class Support : public PlayerClass 
{
public:
    int modifyDamage(int damage) const override 
    {
        return damage * 0.8;
    }
    int Healing(int heal) const override
    {
        return heal;
    }
};

class DmgDealer : public PlayerClass 
{
public:
    int modifyDamage(int damage) const override 
    {
        return damage * 1.2;
    }
    int Healing(int heal) const override
    {
        return heal * 0;
    }
};

class Player {
private:
    string name;
    int health;
    PlayerClass* playerClass;

public:
    Player(const string& name, int health, PlayerClass* playerClass)
        : name(name), health(health), playerClass(playerClass) {}

    void attack(Player& otherPlayer, int damage) 
    {
        int modifiedDamage = playerClass->modifyDamage(damage);
        otherPlayer.health -= modifiedDamage;
        cout << "Player " << name << " attacked Player " << otherPlayer.name
            << " with damage " << modifiedDamage << ", health left: "
            << otherPlayer.health << endl;
    }

    void heal(Player& otherPlayer, int heal)
    {
        int heals = playerClass->Healing(heal);
        otherPlayer.health += heals;
        cout << "Player " << name << " healed Player " << otherPlayer.name
            << " with damage " << heals << ", health left: "
            << otherPlayer.health << endl;
    }
};

int main() 
{
    DmgDealer DmgDealer;
    Tank tank;
    Support support;

    Player player1("Ivan", 120, &DmgDealer);
    Player player2("Vasya", 200, &tank);
    Player player3("Lera", 150, &support);
    Player player4("Fedya", 150, &tank);
    Player player5("Bohdan", 150, &support);
    
    //Також виконання третього завдання
    player1.attack(player2, 30);
    player3.heal(player2, 20);
    player3.attack(player1, 50);
    player5.heal(player1, 40);
    player4.attack(player5, 100);

    return 0;
}