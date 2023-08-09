#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Weapon
{
private:
    string name;
    int dmg;
    int range;

public:
    Weapon(const string& n, int d, int r) : name(n), dmg(d), range(r) {}

    const string& GetName() const
    {
        return name;
    }
    int GetDmg() const
    {
        return dmg;
    }
    int GetRange() const
    {
        return range;
    }

};

class Player
{
private:
    string name;
    int hp;
    string role;
    Weapon* weapon;

public:
    Player(const string& n, int h, const string& r) : name(n), hp(h), role(r) {}

    const string& GetName() const
    {
        return name;
    }
    int GetHp() const
    {
        return hp;
    }
    const string& GetRole() const
    {
        return role;
    }

    void addWeapon(const Weapon& w)
    {
        weapon = new Weapon(w.GetName(), w.GetDmg(), w.GetRange());
    }
    
    void PlayerInfo() const
    {
        cout << name << "(" << role << ")" << " HP:" << hp << endl;
        if (weapon)
        {
            cout << weapon->GetName() << " Dmg: " << weapon->GetDmg() << " Range: " << weapon->GetRange() << endl;
        }
        cout << endl;
    }
    ~Player()
    {
        delete weapon;
    }
};

class Team
{
private:
    string teamName;
    int MembersNum;
    vector<Player*> players;
public:
    Team(const string& name, int num) : teamName(name), MembersNum(num) {}

    void AddPlayer(Player* p)
    {
        players.push_back(p);
    }
    
    void RemovePlayer(Player* p)
    {
        for (auto it = players.begin(); it != players.end(); ++it)
        {
            if (*it == p)
            {
                players.erase(it);
                delete p;
                break;
            }
        }
    }

    void TeamInfo() const 
    {
        cout << teamName << MembersNum << " players:\n" << endl;
        for (const Player* player : players)
        {
            player->PlayerInfo();
        }
        cout << endl;
    }
    ~Team()
    {
        for (Player* p : players)
        {
            delete p;
        }
    }
};

int main()
{
    Weapon ak47("AK-47", 150, 100);
    Weapon AWP("AWP", 400, 200);

    Player player1("Vasya", 100, "Carry");
    player1.addWeapon(AWP);

    Player player2("Ivan", 150, "Tank");
    player2.addWeapon(ak47);

    Team team("Terorists ", 2);
    team.AddPlayer(&player1);
    team.AddPlayer(&player2);

    team.TeamInfo();

    return 0;
}