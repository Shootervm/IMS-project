
#ifndef IMS_PROJECT_GENERATOR_H
#define IMS_PROJECT_GENERATOR_H

#include <vector>
#include <simlib.h>
#include "customer.h"

class Generator : public Event {
    std::vector<Customer *> customers;
    ExperimentData *data_;
public:
    Generator(ExperimentData *data);

    void Behavior();
};

#endif //IMS_PROJECT_GENERATOR_H
