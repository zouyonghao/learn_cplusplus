#include <iostream>
#include "stdio.h"

using namespace std;
// dragon
// ninja
// iceman
// lion
// worf
// red: 2 3 4 1 0
// blue: 3 0 1 2 4
const int WARRIOR_KINDS = 5;
const char *warriors[WARRIOR_KINDS] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int warriorsEnergy[5];
int warriorsCount[5];

const int redWarriors[5] = {2, 3, 4, 1, 0};

const int blueWarriors[5] = {3, 0, 1, 2, 4};

class Warrior {
protected:
    string name;
    int n;
    int ph;
    int attack;
public:
    Warrior(string _name, int _n, int _ph)
        :name(_name), n(_n), ph(_ph) { }
    virtual void print() {

    }
};

const string WEAPONS[3] = {"sword", "bomb", "arrow"};

class Weapon {
protected:
    string name;
    int n;
public:
    Weapon(int _n):n(_n) {
        name = WEAPONS[n];
    }
    string getName() {
        return name;
    }
};

class Dragon:public Warrior {
private:
    Weapon weapon;
    double morale;
public:
    Dragon(int n, int ph, int weaponn, double _morale)
        :Warrior("dragon", n, ph), weapon(weaponn), morale(_morale) {

    }
    void print() {
        printf("It has a %s,and it's morale is %.2f\n", weapon.getName().c_str(), morale);
    }
};

class Ninjia:public Warrior {
private:
    Weapon weapon1;
    Weapon weapon2;
public:
    Ninjia(int n, int ph, int weaponId1, int weaponId2)
        :Warrior("ninjia", n, ph), weapon1(weaponId1), weapon2(weaponId2) {
    }
    void print() {
        printf("It has a %s and a %s\n", weapon1.getName().c_str(), weapon2.getName().c_str());
    }
};

class Iceman:public Warrior {
private:
    Weapon weapon;
public:
    Iceman(int n, int ph, int weaponn)
        :Warrior("iceman", n, ph), weapon(weaponn) {
    }
    void print() {
        printf("It has a %s\n", weapon.getName().c_str());
    }
};

class Lion:public Warrior {
private:
    int loyalty;
public:
    Lion(int n, int ph, int _loyalty)
        :Warrior("lion", n, ph), loyalty(_loyalty) {
    }
    void print() {
        printf("It's loyalty is %d\n", loyalty);
    }
};

class Wolf:public Warrior {
public:
    Wolf(int n, int ph):Warrior("wolf", n, ph) { }
    void print() {

    }
};

Warrior * getWarrior(int warriorKind, int n, int energy) {
    Warrior * w;
    switch(warriorKind) {
        // dragon
        case 0:
            w = new Dragon(
                        n, 
                        warriorsEnergy[0], 
                        n % 3, 
                        (double) energy / (double) (warriorsEnergy[0]));
            break;
        case 1:
            w = new Ninjia(n, warriorsEnergy[1], n % 3, (n + 1) % 3);
            break;
        case 2:
            w = new Iceman(n, warriorsEnergy[2], n % 3);
            break;
        case 3:
            w = new Lion(n, warriorsEnergy[3], energy);
            break;
        case 4:
            w = new Wolf(n, warriorsEnergy[4]);
            break;
    }
    return w;
}

class RedHeadquarter {
private:
    int energy;
    bool stop;
    int tickNum;
    int currentPos;
    int redWarriorsCount[WARRIOR_KINDS];
    int count;
public:
    RedHeadquarter(int m) {
        this->energy = m;
        stop = false;
        tickNum = 0;
        currentPos = 0;
        for (int i = 0; i < WARRIOR_KINDS; i++) {
            redWarriorsCount[i] = 0;
        }
        count = 0;
    }

    void tick() {
        if (stop) {
            return;
        }
        bool printed = false;
        for (int i = 0; i < WARRIOR_KINDS; i++) {
            int pos = currentPos % WARRIOR_KINDS;
            int currentEnergy = warriorsEnergy[redWarriors[pos]];
            if (this->energy >= currentEnergy) {
                this->energy -= currentEnergy;
                this->redWarriorsCount[pos]++;
                warriorsCount[redWarriors[pos]]++;
                count++;
                this->print(pos);
                currentPos++;
                printed = true;
                break;
            }
            currentPos++;
        }
        if (!printed) {
            stop = true;
            printf("%03d red headquarter stops making warriors\n", tickNum);
        }
        tickNum++;
    }

    void print(int pos) {
        //000 red iceman 1 born with strength 5,1 iceman in red headquarter
        printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n",
               tickNum, warriors[redWarriors[pos]], count, warriorsEnergy[redWarriors[pos]],
               this->redWarriorsCount[pos], warriors[redWarriors[pos]]);
        Warrior * w = getWarrior(redWarriors[pos], count, energy);
        w->print();
    }


    bool stopped() {
        return stop;
    }
};


class BlueHeadquarter {
private:
    int energy;
    bool stop;
    int tickNum;
    int currentPos;
    int blueWarriorsCount[WARRIOR_KINDS
];
    int count;
public:
    BlueHeadquarter(int m) {
        this->energy = m;
        stop = false;
        tickNum = 0;
        currentPos = 0;
        for (int i = 0; i < WARRIOR_KINDS
    ; i++) {
            blueWarriorsCount[i] = 0;
        }
        count = 0;
    }

    void tick() {
        if (stop) {
            return;
        }
        bool printed = false;
        for (int i = 0; i < WARRIOR_KINDS; i++) {
            int pos = currentPos % WARRIOR_KINDS;
            int currentEnergy = warriorsEnergy[blueWarriors[pos]];
            if (this->energy >= currentEnergy) {
                this->energy -= currentEnergy;
                this->blueWarriorsCount[pos]++;
                warriorsCount[blueWarriors[pos]]++;
                count++;
                this->print(pos);
                currentPos++;
                printed = true;
                break;
            }
            currentPos++;
        }
        if (!printed) {
            stop = true;
            printf("%03d blue headquarter stops making warriors\n", tickNum);
        }
        tickNum++;
    }

    void print(int pos) {
        //000 red iceman 1 born with strength 5,1 iceman in red headquarter
        printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n",
               tickNum, warriors[blueWarriors[pos]], count, warriorsEnergy[blueWarriors[pos]],
               this->blueWarriorsCount[pos], warriors[blueWarriors[pos]]);
        Warrior * w = getWarrior(blueWarriors[pos], count, energy);
        w->print();
    }


    bool stopped() {
        return stop;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        printf("Case:%d\n", j + 1);
        int energy;
        scanf("%d", &energy);
        for (int i = 0; i < WARRIOR_KINDS; i++) {
            scanf("%d", &warriorsEnergy[i]);
            warriorsCount[i] = 0;
        }
        RedHeadquarter redHeadquarter(energy);
        BlueHeadquarter blueHeadquarter(energy);
        while (!redHeadquarter.stopped() || !blueHeadquarter.stopped()) {
            redHeadquarter.tick();
            blueHeadquarter.tick();
        }
    }
    return 0;
}
