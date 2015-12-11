#include <iostream>
#include <simlib.h>

using namespace std;

Facility Cashier("Cashier");
Store Fooder("Fooder", 2);
Facility Soaper("Soaper");

const double kCustomerArrivalTime = 1e3 / 150;

class Customer : public Process {

    void Behavior() { }
};

class CustomerGenerator : public Event {
public:
    void Behavior() {
        (new Customer)->Activate();
        Activate(Time + Exponential(kCustomerArrivalTime));
    }
};

int main() {

    Init(0, 1000);

    (new CustomerGenerator)->Activate();
    Run();


    return 0;
}