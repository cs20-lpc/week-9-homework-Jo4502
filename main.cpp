#include "QueueFactory.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    cout << "\nSimulation 1: Ticket Counter\n";

    Queue<int>* ticketLine = QueueFactory::GetQueue<int>(10); // max 10 customers
    const int SIM1_STEPS = 100;

    for (int i = 0; i < SIM1_STEPS; i++) {
        int num = rand() % 3 - 1; // generates -1, 0, 1
        if (num < 0) {
            if (!ticketLine->isEmpty()) {
                ticketLine->dequeue(); // one customer served
            }
        }
        else {
            try {
                ticketLine->enqueue(i);
            }
            catch (string& e) {
                // queue full ? customer turned away
            }
        }
    }

    cout << "Remaining in line: " << ticketLine->getLength() << endl;
    delete ticketLine;

    // -------------------------------------------------------------------------
    // Simulation 2: Bank Line (LinkedQueue, unlimited size)
    // -------------------------------------------------------------------------
    cout << "\nSimulation 2: Bank Line\n";

    Queue<int>* bankLine = QueueFactory::GetQueue<int>(); // linked list queue
    const int SIM2_STEPS = 100;

    for (int i = 0; i < SIM2_STEPS; i++) {
        int num = rand() % 4 - 1; // generates -1, 0, 1, 2
        if (num < 0) {
            if (!bankLine->isEmpty()) {
                bankLine->dequeue(); // one customer leaves
            }
        }
        else {
            bankLine->enqueue(i); // new customer arrives
        }
    }

    cout << "Remaining in line: " << bankLine->getLength() << endl;
    delete bankLine;

    return 0;
}
