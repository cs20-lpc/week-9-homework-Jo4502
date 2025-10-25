#include "QueueFactory.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    cout << "\nSimulation 1: Ticket Counter\n";

    Queue<int>* ticketLine = QueueFactory::GetQueue<int>(10); 
    const int SIM1_STEPS = 100;

    for (int i = 0; i < SIM1_STEPS; i++) {
        int num = rand() % 3 - 1; 
        if (num < 0) {
            if (!ticketLine->isEmpty()) {
                ticketLine->dequeue(); 
            }
        }
        else {
            try {
                ticketLine->enqueue(i);
            }
            catch (string& e) {
                
            }
        }
    }

    cout << "Remaining in line: " << ticketLine->getLength() << endl;
    delete ticketLine;

   
    cout << "\nSimulation 2: Bank Line\n";

    Queue<int>* bankLine = QueueFactory::GetQueue<int>(); 
    const int SIM2_STEPS = 100;

    for (int i = 0; i < SIM2_STEPS; i++) {
        int num = rand() % 4 - 1; 
        if (num < 0) {
            if (!bankLine->isEmpty()) {
                bankLine->dequeue(); 
            }
        }
        else {
            bankLine->enqueue(i); 
        }
    }

    cout << "Remaining in line: " << bankLine->getLength() << endl;
    delete bankLine;

    return 0;
}
