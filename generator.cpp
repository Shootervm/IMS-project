#include <simlib.h>
#include "customer.h"
#include "generator.h"

Generator::Generator(ExperimentData *data) {
    Activate();
    data_ = data;
    std::cout << data_->kCustomerArrivalTime;
}

void Generator::Behavior() {
    auto c = new Customer();
    customers.push_back(c);
    c->Activate();
    this->Activate(Time + Exponential(data_->kCustomerArrivalTime));
}