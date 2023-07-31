#include <iostream>

class Creature {
public:
    Creature(int health = 100);
    virtual void Greet() const = 0;     //pure virtual function. One pure virtual class makes the whole class abstract.
    virtual void DisplayHealth() const;

protected:
    int m_Health;
};

Creature::Creature(int health):
    m_Health(health)
{}

void Creature::DisplayHealth() const {
    std::cout << "Health: " << m_Health << "\n";
}

class Orc : public Creature {
public:
    Orc(int health = 120);
    virtual void Greet() const;
};

Orc::Orc(int health):
    Creature(health)
{}

void Orc::Greet() const {
    std::cout << "The orc grunts hello.\n";
}

int main()
{
    Creature* pCreature = new Orc();
    pCreature->DisplayHealth();
    pCreature->Greet();

    delete pCreature;
    pCreature = 0;
    system("pause");
}