#include <simlib.h>
#include "customer.h"
#include "generator.h"

Generator::Generator() {
    Activate();
}

void Generator::Behavior() {
    auto c = new Customer();
    customers.push_back(c);
    c->Activate();
    this->Activate(Time + Exponential(data.kCustomerArrivalTime));
}