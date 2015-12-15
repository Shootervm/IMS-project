// IMS project 2015 - 07 Menza
// authors: xmalin26 & xmasek15

#include <iostream>
#include <simlib.h>
#include "customer.h"
#include "generator.h"

using namespace std;


int main() {

    Init(0, data.simulationLength);

    Generator *gen = new Generator(&data);
    Run();

    enter_queue.Output();
    tray_stand.Output();
    soup_queue.Output();
    soup_facility.Output();
    food_store.Output();
    water_queue.Output();
    water_facility.Output();
    etc_queue.Output();
    etc_facility.Output();
    cashier_queue.Output();
    cashier.Output();
    table_places.Output();
    return_tray_queue.Output();
    return_tray.Output();

    delete gen;

    return 0;
}
