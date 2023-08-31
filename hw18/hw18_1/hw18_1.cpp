#include <iostream>

using namespace std;

class Weapon 
{
protected:
    string name;
    float effectiveRange;
    int dmg;

public:
    Weapon(const string& name, float range, int damage)
        : name(name), effectiveRange(range), dmg(damage) {}
    
    const string& getName() const
    {
        return name;
    }

    int getDamage() const
    {
        return dmg;
    }
};


class MeleeWeapon : public Weapon 
{
public:
    MeleeWeapon(const string& name, float range, int damage)
        : Weapon(name, range, damage) {}
};


class RangedWeapon : public Weapon 
{
public:
    RangedWeapon(const string& name, float range, int damage)
        : Weapon(name, range, damage) {}
};


class Axe : public MeleeWeapon 
{
public:
    Axe() : MeleeWeapon("Axe", 3, 120) {}
};

class Knife : public MeleeWeapon 
{
public:
    Knife() : MeleeWeapon("Knife", 2, 110) {}
};

class BareHand : public MeleeWeapon 
{
public:
    BareHand() : MeleeWeapon("Bare Hand", 1, 10) {}
};

class Shotgun : public RangedWeapon 
{
public:
    Shotgun() : RangedWeapon("Shotgun", 50.0, 100) {}
};

class Pistol : public RangedWeapon 
{
public:
    Pistol() : RangedWeapon("Pistol", 20.0, 40) {}
};

class Rifle : public RangedWeapon 
{
public:
    Rifle() : RangedWeapon("Rifle", 100.0, 80) {}
};


class Player 
{
private:
    string name;
    int health;
    Weapon* weapon;

public:
    Player(const string& name, int health, Weapon* weapon)
        : name(name), health(health), weapon(weapon) {}

    void attack(Player& otherPlayer, int distance) 
    {
        int damage = weapon->getDamage();
        otherPlayer.health -= damage;
        cout << "Player " << name << " attacked Player " << otherPlayer.name
            << " with weapon " << weapon->getName() << " with damage " << damage
            << ", health left: " << otherPlayer.health << endl;
    }
};

int main() 
{
    Axe axe;
    Shotgun shotgun;

    Player player1("Ivan", 100, &axe);
    Player player2("Vasya", 150, &shotgun);

    player1.attack(player2, 30);

    return 0;
}