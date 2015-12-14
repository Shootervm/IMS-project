#include <iostream>
#include <vector>
#include "customer.h"

using namespace std;


class Generator : public Event {
    vector<Customer *> customers;
public:
    Generator() {
        Activate();
    }

    void Behavior() {
        auto c = new Customer();
        customers.push_back(c);
        c->Activate();
        this->Activate(Time + Exponential(data.kCustomerArrivalTime));
    }
};


int main() {

    Init(0, data.simulationLength);

    Generator *gen = new Generator();
    Run();

    printf("\n========================= Zobranie tacky  =========================\n");
    enter_queue.Output();
    tray_stand.Output();
    printf("\n========================= Chce polievku   =========================\n");
    soup_queue.Output();
    soup_facility.Output();
    printf("\n========================= Vyber hl. jedla =========================\n");
    food_store.Output();
    printf("\n========================= Naberie si vodu =========================\n");
    water_queue.Output();
    water_facility.Output();
    printf("\n========================= Zoberie si etc  =========================\n");
    etc_queue.Output();
    etc_facility.Output();
    printf("\n========================= Platenie        =========================\n");
    cashier_queue.Output();
    cashier.Output();
    printf("\n========================= Stolovovanie    =========================\n");
    table_places.Output();
    printf("\n========================= Vratenie tacky  =========================\n");
    return_tray_queue.Output();
    return_tray.Output();

    delete gen;

    return 0;
}
