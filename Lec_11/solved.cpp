//
// Created by attar74_ on 10/12/23.
//

#include <iostream>
#include <fstream>
using namespace std;

class Animal
{

protected:
    bool canWalk;
    bool canFly;
    bool canSwim;
    bool isEdible;

public:
    Animal()
    {
        canWalk = false;
        canFly = false;
        canSwim = false;
        isEdible = false;
    }

    virtual const char *getName() = 0;

    bool getCanWalk()
    {
        return canWalk;
    };

    bool getCanFly()
    {
        return canFly;
    };

    bool getCanSwim()
    {
        return canSwim;
    };

    bool getIsEdible()
    {
        return isEdible;
    };
};

class Mammal : public Animal
{

public:
    Mammal()
    {
        canWalk = true;
        canFly = false;
        canSwim = false;
    }
};

class Lion : public Mammal
{
public:
    Lion()
    {
        isEdible = false;
    }

    virtual const char *getName()
    {
        return "Lion";
    }
};

class Sheep : public Mammal
{
public:
    Sheep()
    {
        isEdible = true;
    }

    const char *getName()
    {
        return "Sheep";
    }
};

class Fish : public Animal
{

public:
    Fish()
    {
        canWalk = false;
        canFly = false;
        canSwim = true;
    }
};

class Shrimp : public Fish
{

public:
    Shrimp()
    {
        isEdible = true;
    }

    virtual const char *getName()
    {
        return "Shrimp";
    }
};

class Shark : public Fish
{

public:
    Shark()
    {
        isEdible = false;
    }

    virtual const char *getName()
    {
        return "Shark";
    }
};

class Bird : public Fish
{
public:
    Bird()
    {
        canWalk = true;
    }
};

class Duck : public Bird
{

public:
    Duck()
    {
        canFly = false;
        canSwim = true;
        isEdible = true;
    }

    virtual const char *getName()
    {
        return "Duck";
    }
};

class Eagle : public Bird
{

public:
    Eagle()
    {
        canFly = true;
        canSwim = false;
        isEdible = false;
    }

    virtual const char *getName()
    {
        return "Eagle";
    }
};

class Game
{
private:
    short numOfAnimals = 6;
    Animal *animals[6] = {new Lion, new Sheep, new Shrimp, new Shark, new Duck, new Eagle};

    void printAnimals()
    {
        cout << endl;
        for (short i = 0; i < numOfAnimals; i++)
        {
            cout << "-> " << animals[i]->getName() << endl;
        }
        cout << endl;
    }

    string getQuestion(string attribute)
    {
        string question = "";
        string line;
        ifstream questions("input.txt");
        if (!questions.is_open())
        {
            throw runtime_error("Error: Questions file not found");
        }
        while (!questions.eof())
        {
            getline(questions, line);
            if (line.rfind(attribute, 0) == 0)
            {
                int colonIndex = line.find(":");
                question = line.substr(colonIndex + 1);
            }
        }
        questions.close();
        return question;
    }

    bool scanAnimalAbility(string attribute)
    {
        char answer;
        do
        {
            string question = getQuestion(attribute);
            cout << "\n"
                 << question << "\n(0) No.\n(1) Yes.\n\nAnswer? ";
            cin >> answer;
        } while (answer != '0' && answer != '1');
        return bool(answer);
    }

    bool canTheAnimal(Animal *animal, string attribute)
    {
        if (attribute == "walk")
        {
            return animal->getCanWalk();
        }
        else if (attribute == "fly")
        {
            return animal->getCanFly();
        }
        else if (attribute == "swim")
        {
            return animal->getCanSwim();
        }
        else if (attribute == "edible")
        {
            return animal->getIsEdible();
        }
        return false;
    }

    void filterAnimals(string attribute, bool animalAbility)
    {

        for (short i = 0; i < numOfAnimals; i++)
        {
            if (animals[i] && canTheAnimal(animals[i], attribute) != animalAbility)
            {
                animals[i] = 0;
            }
        }
    }

    bool filterBy(string attribute)
    {
        bool canTheAnimal = scanAnimalAbility(attribute);
        filterAnimals(attribute, canTheAnimal);
        return canTheAnimal;
    }

    void printChoosenAnimal()
    {
        cout << endl;
        short i = 0;
        while (!animals[i])
        {
            i++;
        }
        cout << "You choose: " << animals[i]->getName() << endl;
    }

public:
    void start()
    {
        cout << "Please choose an animal and keep it in your mind:" << endl;
        printAnimals();

        bool canTheAnimalWalk = filterBy("walk");
        if (canTheAnimalWalk)
        {
            bool canTheAnimalFly = filterBy("fly");
            if (!canTheAnimalFly)
            {
                bool canTheAnimalSwim = filterBy("swim");
                if (!canTheAnimalSwim)
                {
                    filterBy("edible");
                }
            }
        }
        else
        {
            filterBy("edible");
        }

        printChoosenAnimal();
    }
};

int main()
{
    Game game = Game();
    try
    {
        game.start();
    }
    catch (exception &e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}