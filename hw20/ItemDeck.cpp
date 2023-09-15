#include "ItemDeck.h"
#include "Item.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>

ItemDeck::ItemDeck()
{
	std::ifstream file("ItemDeckBase.txt");
	if (!file.is_open()) 
	{
		std::cerr << "Failed to open items_database.txt" << std::endl;
		return;
	}
    std::string line;
    int linesCount = 0;

    std::vector<std::string> allWeapons;
    while (std::getline(file, line)) 
    {
        allWeapons.push_back(line);
    }

    int max = allWeapons.size() / 2;
    srand(time(NULL));
    int random;
    random = rand() % max + 1;
    int minusWeapon = allWeapons.size() - random;
    for (int i = 0; i < minusWeapon; i++)
    {
        int rnd = rand() % (allWeapons.size() - 1);
        allWeapons.erase(allWeapons.begin() + rnd);
    }
    for (int i = 0; i < allWeapons.size(); i++)
    {
        std::string delimiter_char = ";";
        size_t pos = 0;
        std::string token;
        std::vector<std::string> tokens;
        while ((pos = allWeapons[i].find(delimiter_char)) != std::string::npos)
        {
            token = allWeapons[i].substr(0, pos);
            tokens.push_back(token);
            allWeapons[i].erase(0, pos + delimiter_char.length());
        }
        tokens.push_back(allWeapons[i]);
        int params = stoi(tokens[2]);
        if (tokens[0] == "UndeadWeapon")
        {
            m_itemsDataBase.push_back(new UndeadWeapon(&token[1], params));
        }
        else if (tokens[0] == "ZombieWeapon")
        {
            m_itemsDataBase.push_back(new ZombieWeapon(&token[1], params));
        }
        else if (tokens[0] == "GodWeapon")
        {
            m_itemsDataBase.push_back(new GodWeapon(&token[1], params));
        }
        else if (tokens[0] == "Weapon")
        {
            m_itemsDataBase.push_back(new Weapon(&token[1], params));
        }
        else
        {
            std::cerr << "Invalid line format: " << allWeapons[i] << std::endl;
        }
    }
    file.close();
}

ItemDeck::~ItemDeck()
{
    for (Item* item : m_itemsDataBase)
    {
        delete item;
    }
}

std::vector<Item*> ItemDeck::generateItems() const
{
	
    return m_itemsDataBase;
}
