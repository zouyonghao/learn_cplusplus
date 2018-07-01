#include <iostream>
#include "stdio.h"
#include <vector>

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

int warriorsAttacks[5];

const int redWarriors[5] = {2, 3, 4, 1, 0};

const int blueWarriors[5] = {3, 0, 1, 2, 4};

class Warrior;

enum FLAG
{
    NONE,
    RED,
    BLUE
};

class City
{
  public:
    int n;
    Warrior *redWarrior;
    Warrior *blueWarrior;
    int elements;
    FLAG flag;
    City()
    {
        redWarrior = NULL;
        blueWarrior = NULL;
        flag = NONE;
    }
};

int N, R, K;
City **cities;

class Headquarter : public City
{
  private:
    int energy;
    bool stop;
    int tickNum;
    int currentPos;
    int warriorsCount[WARRIOR_KINDS];
    int count;
    const int *warriorsSort;
    string name;
    int takenWarriors;

  public:
    Headquarter(int m, const int *_warriorsSort, string _name) : name(_name)
    {
        this->energy = m;
        stop = false;
        tickNum = 0;
        currentPos = 0;
        for (int i = 0; i < WARRIOR_KINDS; i++)
        {
            this->warriorsCount[i] = 0;
        }
        count = 0;
        this->warriorsSort = _warriorsSort;
        takenWarriors = 0;
    }

    Warrior *tryBuildWarrior(int buildTime, int bornCity, int destination, int direction);

    bool stopped()
    {
        return stop;
    }

    bool taken()
    {
        return takenWarriors == 2;
    }

    const char *getName()
    {
        return name.c_str();
    }
};

Headquarter *redHeadquarter;
Headquarter *blueHeadquarter;

class Warrior
{
  protected:
    string name; // 名称
    int n;       // 编号
    int ph;      // 生命值
    int attack;  // 攻击力
    Headquarter *pHeadquarter;

  public:
    int direction;   // 方向
    int destination; // 终点
    int bornCity;    // 出生地
    int currentCity; // 当前城市
    int elements;
    bool shotToDeath;
    bool arrived;
    Headquarter *destinationHeadquater;
    Warrior(string _name, int _n, int _ph)
        : name(_name), n(_n), ph(_ph)
    {
        elements = 0;
        arrived = false;
        shotToDeath = false;
    }
    virtual bool isDead()
    {
        return !shotToDeath && ph <= 0;
    }
    // virtual int fight(Warrior & w) = 0;
    virtual void print() = 0;
    void born(int bornTime)
    {
        printf("%03d:00 %s %s %d born\n", bornTime, pHeadquarter->getName(), name.c_str(), n);
        print();
    }
    void setHeadquarter(Headquarter *pHq)
    {
        this->pHeadquarter = pHq;
    }
    Headquarter *getHeadquarter()
    {
        return this->pHeadquarter;
    }
    string getName()
    {
        return name;
    }
    virtual void moveForward(int tickNum)
    {
        currentCity += direction;
    }
    void printArrived(int tickNum)
    {

        if (currentCity == destination)
        {
            arrived = true;
            printf("%03d:10 %s %s %d reached %s headquarter with %d elements and force %d",
                   tickNum, this->pHeadquarter->getName(), name.c_str(), n, destinationHeadquater->getName(), elements, attack);
        }
        else
        {
            printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",
                   tickNum, this->pHeadquarter->getName(), name.c_str(), n, currentCity, elements, attack);
        }
    }
    void shot()
    {
    }

    void useBomb()
    {
    }

    void doAttack()
    {
    }

    void doReattack()
    {
    }

    virtual void afterAttack() {}
};

const string WEAPONS[3] = {"sword", "bomb", "arrow"};

class Weapon
{
  protected:
    string name;
    int n;

  public:
    Weapon(int _n) : n(_n)
    {
        name = WEAPONS[n];
    }
    Weapon(const Weapon &w)
    {
        name = w.name;
        n = w.n;
    }
    string getName()
    {
        return name;
    }
};

class Dragon : public Warrior
{
  private:
    Weapon weapon;
    double morale;

  public:
    Dragon(int n, int ph, int weaponn, double _morale)
        : Warrior("dragon", n, ph), weapon(weaponn), morale(_morale)
    {
        attack = warriorsAttacks[0];
    }
    void print()
    {
        printf("It has a %s,and it's morale is %.2f\n", weapon.getName().c_str(), morale);
    }
};

class Ninjia : public Warrior
{
  private:
    Weapon weapon1;
    Weapon weapon2;

  public:
    Ninjia(int n, int ph, int weaponId1, int weaponId2)
        : Warrior("ninjia", n, ph), weapon1(weaponId1), weapon2(weaponId2)
    {
        attack = warriorsAttacks[1];
    }
    void print()
    {
        printf("It has a %s and a %s\n", weapon1.getName().c_str(), weapon2.getName().c_str());
    }
};

class Iceman : public Warrior
{
  private:
    Weapon weapon;

  public:
    Iceman(int n, int ph, int weaponn)
        : Warrior("iceman", n, ph), weapon(weaponn)
    {
        attack = warriorsAttacks[2];
    }
    void print()
    {
        printf("It has a %s\n", weapon.getName().c_str());
    }
    virtual void moveForward(int tickNum)
    {
        if (currentCity != bornCity &&
            (bornCity - currentCity) % 2 == 0)
        {
            ph -= 9;
            if (ph <= 0)
            {
                ph = 1;
            }
            attack += 20;
        }
        Warrior::moveForward(tickNum);
    }
};

class Lion : public Warrior
{
  private:
    int loyalty;

  public:
    Lion(int n, int ph, int _loyalty)
        : Warrior("lion", n, ph), loyalty(_loyalty)
    {
        attack = warriorsAttacks[3];
    }
    void print()
    {
        printf("It's loyalty is %d\n", loyalty);
    }
    Lion *tryRunaway(int tickNum)
    {
        if (this->currentCity != destination && loyalty <= 0)
        {
            printf("%03d:05 %s lion %d ran away\n", tickNum, this->pHeadquarter->getName(), n);
            this->ph = 0;
        }
        return this;
    }
};

class Wolf : public Warrior
{
  public:
    Wolf(int n, int ph) : Warrior("wolf", n, ph)
    {
        attack = warriorsAttacks[4];
    }
    void print()
    {
    }
};

Warrior *getWarrior(int warriorKind, int n, int energy, Headquarter *phq)
{
    Warrior *w;
    switch (warriorKind)
    {
    // dragon
    case 0:
        w = new Dragon(
            n,
            warriorsEnergy[0],
            n % 3,
            (double)energy / (double)(warriorsEnergy[0]));
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
    w->setHeadquarter(phq);
    return w;
}

Warrior *Headquarter::tryBuildWarrior(int buildTime, int bornCity, int destination, int direction)
{
    for (int i = 0; i < WARRIOR_KINDS; i++)
    {
        int pos = currentPos % WARRIOR_KINDS;
        int currentEnergy = warriorsEnergy[warriorsSort[pos]];
        if (this->energy >= currentEnergy)
        {
            this->energy -= currentEnergy;
            this->warriorsCount[pos]++;
            warriorsCount[warriorsSort[pos]]++;
            count++;

            Warrior *w = getWarrior(warriorsSort[pos], count, energy, this);
            w->born(buildTime);
            w->bornCity = bornCity;
            w->currentCity = bornCity;
            w->destination = destination;
            w->direction = direction;
            currentPos++;
            return w;
        }
        currentPos++;
    }
    return NULL;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        printf("Case:%d\n", j + 1);
        int M, T;
        cin >> M >> N >> R >> K >> T;
        for (int i = 0; i < WARRIOR_KINDS; i++)
        {
            scanf("%d", &warriorsEnergy[i]);
            warriorsCount[i] = 0;
        }
        for (int i = 0; i < WARRIOR_KINDS; i++)
        {
            scanf("%d", &warriorsAttacks[i]);
        }
        cities = new City *[N + 2];
        redHeadquarter = new Headquarter(M, redWarriors, "red");
        blueHeadquarter = new Headquarter(M, blueWarriors, "blue");
        cities[0] = redHeadquarter;
        cities[0]->n = 0;
        cities[N + 1] = blueHeadquarter;
        cities[N + 1]->n = N + 1;
        for (int i = 1; i <= N; i++)
        {
            City *pc = new City;
            pc->n = i;
            cities[i] = pc;
        }
        int tickNum = 0;
        vector<Lion *> lions;
        vector<Warrior *> warriors;
        while (!redHeadquarter->taken() && !blueHeadquarter->taken())
        {
            // 000:00 build warrior
            Warrior *redW = redHeadquarter->tryBuildWarrior(tickNum, 0, N + 1, 1);
            if (redW != NULL)
            {
                warriors.push_back(redW);
                redW->destinationHeadquater = blueHeadquarter;
            }
            Warrior *blueW = blueHeadquarter->tryBuildWarrior(tickNum, N + 1, 0, -1);
            if (blueW != NULL)
            {
                warriors.push_back(blueW);
                blueW->destinationHeadquater = redHeadquarter;
            }
            // 000:05 blue lion 1 ran away
            if (redW && redW->getName() == "lion")
            {
                lions.push_back((Lion *)redW);
            }
            if (blueW && blueW->getName() == "lion")
            {
                lions.push_back((Lion *)blueW);
            }
            for (int i = 0; i < lions.size(); i++)
            {
                if (!lions[i]->isDead())
                {
                    lions[i]->tryRunaway(tickNum);
                }
            }

            // 000:10 move forward
            if (redW)
            {
                redW->moveForward(tickNum);
            }
            if (blueW)
            {
                blueW->moveForward(tickNum);
            }

            for (int i = 1; i <= N; i++)
            {
                cities[i]->redWarrior->moveForward(tickNum);
                cities[i]->blueWarrior->moveForward(tickNum);
            }
            for (int i = 0; i < warriors.size(); i++)
            {
                if (warriors[i]->getHeadquarter()->getName() == "red")
                {
                    cities[warriors[i]->currentCity]->redWarrior = warriors[i];
                }
                else
                {
                    cities[warriors[i]->currentCity]->blueWarrior = warriors[i];
                }
            }
            for (int i = 0; i <= N + 1; i++)
            {
                Warrior *_tmpW = cities[i]->redWarrior;
                if (_tmpW)
                    _tmpW->printArrived(tickNum);
                _tmpW = cities[i]->blueWarrior;
                if (_tmpW)
                    _tmpW->printArrived(tickNum);
            }

            // 000:20 add elements
            for (int i = 1; i <= N; i++)
            {
                cities[i]->elements += 10;
            }

            // 000:30 take elements

            // 000:35 shot
            for (int i = 1; i < N; i++)
            {
                cities[i]->redWarrior->shot();
                cities[i]->blueWarrior->shot();
            }

            // 000:38 use bomb
            for (int i = 1; i <= N; i++)
            {
                cities[i]->redWarrior->useBomb();
                cities[i]->blueWarrior->useBomb();
            }

            // 000:40 attack
            for (int i = 1; i <= N; i++)
            {
                Warrior *currentRedWarrior = cities[i]->redWarrior;
                Warrior *currentBlueWarrior = cities[i]->blueWarrior;
                if (cities[i]->flag == RED ||
                    cities[i]->flag == NONE && cities[i]->n % 2 == 1)
                {
                    if (currentRedWarrior && currentBlueWarrior)
                    {
                        cities[i]->redWarrior->doAttack();
                        cities[i]->blueWarrior->doReattack();
                        cities[i]->redWarrior->afterAttack();
                        cities[i]->blueWarrior->afterAttack();
                    }
                }
                else if (cities[i]->flag == BLUE ||
                         cities[i]->flag == NONE && cities[i]->n % 2 == 1)
                {
                    if (currentRedWarrior && currentBlueWarrior)
                    {
                        cities[i]->blueWarrior->doAttack();
                        cities[i]->redWarrior->doReattack();
                        cities[i]->blueWarrior->afterAttack();
                        cities[i]->redWarrior->afterAttack();
                    }
                }
            }

            // raise flag.
        }
    }
    return 0;
}
