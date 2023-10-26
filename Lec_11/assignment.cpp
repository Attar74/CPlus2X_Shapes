#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Organism {
protected:
    bool canWalk;
    bool canFly;
    bool canSwim;
    bool canBeEaten;
public:
    Organism() {
        canWalk = false;
        canFly = false;
        canSwim = false;
        canBeEaten = false;
    }
    virtual const char* getName() = 0;
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

    bool getcanBeEaten()
    {
        return canBeEaten;
    };
};

class Animal : public Organism {

public:
    Animal() {
        canWalk = true;
        canFly = false;
        canSwim = false;
    }
};

class Lion : public Animal {

public:
    Lion() {
        canWalk = true;
        canFly = false;
        canSwim = false;
        canBeEaten = false;
    }

    virtual const char *getName() {
        return "Lion";
    }
};

class Rabbit : public Animal {

public:
    Rabbit() {
        canWalk = true;
        canFly = false;
        canSwim = false;
        canBeEaten = true;
    }

    virtual const char *getName() {
        return "Rabbit";
    }
};

class Fish : public Organism {

public:
    Fish() {
        canWalk = false;
        canFly = false;
        canSwim = true;
    }
};

class TilapiaFish : public Fish {

public:
    TilapiaFish() {
        canWalk = false;
        canFly = false;
        canSwim = true;
        canBeEaten = true;
    }

    virtual const char *getName() {
        return "TilapiaFish";
    }
};

class Shark : public Fish {

public:
    Shark() {
        canWalk = false;
        canFly = false;
        canSwim = true;
        canBeEaten = false;
    }

    virtual const char *getName() {
        return "Shark";
    }
};

class AppStart {
private:
    Organism* Organisms[4] = { new Lion, new Rabbit, new TilapiaFish, new Shark };

    void printOrganisms()
    {
        cout << endl;
        for (short i = 0; i < 4; i++)
        {
            cout << Organisms[i]->getName() << endl;
        }
        cout << "\n Keep an animal inside your head and answer next questions \n";
        cout << endl;
    }

    void getQuestions () {
        ifstream questions("input.txt");
        ofstream out("output.txt");
        while(!questions.eof()) {
            string activeQ;
            char answer;
            getline(questions, activeQ);
            int pos = activeQ.find(">");
            cout << activeQ.substr(pos + 1) << endl;
            cin >> answer;
            out << activeQ.substr(0, pos) << ":" << answer << endl;
        }
    }
    void getTheRightAnimal() {
            ifstream answers("output.txt");
            while(!answers.eof()) {
                string activeAnswers;
                getline(answers, activeAnswers);
                int pos = activeAnswers.find(":");
                cout << activeAnswers.substr(pos + 1) << endl;
                cout << activeAnswers.substr(0, pos) << endl;
                if (activeAnswers.substr(pos + 1) == "Y") {
                    if (activeAnswers.substr(0, pos) == "walking") {
                        filterAnimals(activeAnswers.substr(0, pos));
                    }
                    if (activeAnswers.substr(0, pos) == "flying") {
                        filterAnimals(activeAnswers.substr(0, pos));
                    }
                    if (activeAnswers.substr(0, pos) == "swimming") {
                        filterAnimals(activeAnswers.substr(0, pos));
                    }
                    if (activeAnswers.substr(0, pos) == "toBeEaten") {
                        filterAnimals(activeAnswers.substr(0, pos));
                    }
                }
            }
    }
    void filterAnimals(string attribute) {

        for(short i =0; i < 4; i++) {
            if(attribute == "walking") {

            }
        }
    }
public:
    void start() {
        printOrganisms();
        getQuestions();
        getTheRightAnimal();
    }
};

int main()
{
    AppStart appClone = AppStart();

    appClone.start();

    return 0;
}