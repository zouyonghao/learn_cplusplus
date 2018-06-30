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
const int WORRIER_KINDS = 5;
const char *worriers[WORRIER_KINDS] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int worriersEnergy[5];
int worriersCount[5];

const int redWorriers[5] = {2, 3, 4, 1, 0};

const int blueWorriers[5] = {3, 0, 1, 2, 4};

class RedHeadquarter {
private:
    int energy;
    bool stop;
    int tickNum;
    int currentPos;
    int redWorriersCount[WORRIER_KINDS];
    int count;
public:
    RedHeadquarter(int m) {
        this->energy = m;
        stop = false;
        tickNum = 0;
        currentPos = 0;
        for (int i = 0; i < WORRIER_KINDS; i++) {
            redWorriersCount[i] = 0;
        }
        count = 0;
    }

    void tick() {
        if (stop) {
            return;
        }
        bool printed = false;
        for (int i = 0; i < WORRIER_KINDS; i++) {
            int pos = currentPos % WORRIER_KINDS;
            int currentEnergy = worriersEnergy[redWorriers[pos]];
            if (this->energy >= currentEnergy) {
                this->energy -= currentEnergy;
                this->redWorriersCount[pos]++;
                worriersCount[redWorriers[pos]]++;
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
               tickNum, worriers[redWorriers[pos]], count, worriersEnergy[redWorriers[pos]],
               this->redWorriersCount[pos], worriers[redWorriers[pos]]);
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
    int blueWorriersCount[WORRIER_KINDS];
    int count;
public:
    BlueHeadquarter(int m) {
        this->energy = m;
        stop = false;
        tickNum = 0;
        currentPos = 0;
        for (int i = 0; i < WORRIER_KINDS; i++) {
            blueWorriersCount[i] = 0;
        }
        count = 0;
    }

    void tick() {
        if (stop) {
            return;
        }
        bool printed = false;
        for (int i = 0; i < WORRIER_KINDS; i++) {
            int pos = currentPos % WORRIER_KINDS;
            int currentEnergy = worriersEnergy[blueWorriers[pos]];
            if (this->energy >= currentEnergy) {
                this->energy -= currentEnergy;
                this->blueWorriersCount[pos]++;
                worriersCount[blueWorriers[pos]]++;
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
               tickNum, worriers[blueWorriers[pos]], count, worriersEnergy[blueWorriers[pos]],
               this->blueWorriersCount[pos], worriers[blueWorriers[pos]]);
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
        for (int i = 0; i < WORRIER_KINDS; i++) {
            scanf("%d", &worriersEnergy[i]);
            worriersCount[i] = 0;
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
