#include <iostream>
#include <simlib.h>
#include <memory>
#include <vector>

using namespace std;

// capacity
const unsigned int kCapacity = 120;
const unsigned int kQueueQuitLength = 25;
const unsigned int kQueueQuitChance = 15;

// facility times
const double kCustomerArrivalTime = 17;
const double kTrayStandProcessTime = 4.65;
const double kSoupTakeTime = 5.2;
const double kPizzaOrderTime = 10.0;
const double kPreparedFoodTakeTime = 6.0;
const double kUnpreparedFoodTakeTime = 16.0;
const double kWaterTakeTime = 7.3;
const double kETCTakeTime = 5.5;
const double kPaymentByCashTime = 15.0;
const double kPaymentByISICTime = 6.5;
const double kEatingTime = 18 * 60.0;
const double kReturnTrayProcessTime = 4.0;

// percentages
// soup
const double kCustomerWithSoup = 30.0;
// main food
const double kCustomerFoodPizza = 15.0;
const double kCustomerFoodPrepared = 30.0;
const double kCustomerFoodUnprepared = 55.0;
// water
const double kCustomerWithWater = 65.0;
// etc
const double kCustomerWithETC = 40.0;
// payment
const double kPaymentByCash = 25.0;


// queue for tray_stand
Queue enter_queue("Vstupna rada");
Facility tray_stand("Tackovac");

Queue soup_queue("Rada na polievku");
Facility soup_facility("Davanie polievky");

Store food_store("Vydaj jedla", 2); // davanie jedla

Queue water_queue("Rada na vydaj pitia");
Facility water_facility("Vydaj pitia");

Queue etc_queue("Rada na vydaj etc");
Facility etc_facility("Salaty, bagety, kolace");

Queue cashier_queue("Rada na platenie");
Facility cashier("Platenie");

Store table_places("Stolovanie", kCapacity);

Queue return_tray_queue("Rada na odlozenie tacok");
Facility return_tray("Pas na tacky");


class Customer : public Process {
public:
    Customer() {
        Activate();
    }

    void Behavior() {
        if (enter_queue.Length() > kQueueQuitLength) {
            unsigned int chance = (unsigned int) (100 * Random());
            if (chance <= kQueueQuitChance) {
                return; // quit
            }
        }

        HandleTrayStand();
    }

    inline void ProcessFacility(Facility &f, double w) {
        f.Seize(this);
        Wait(Exponential(w));
        f.Release(this);
    }

    inline void ActivateQueue(Queue &q) {
        if (q.Empty()) {
            return;
        }

        Customer *c = (Customer *) q.GetFirst();
        c->Activate();
    }

    void HandleTrayStand() {
        if (tray_stand.Busy()) {
            enter_queue.Insert(this);
            this->Passivate();
        }

        // generate bool from chance if customer wants a soup
        bool want_soup = 100 * Random() <= kCustomerWithSoup;

        //capacity of food Queues are limited, SoupQ is only 3 and MainFoodQ is 4
        if ((want_soup && soup_queue.size() < 4) || (!want_soup && food_store.Q->size() < 5)) {
            // get the tray
            ProcessFacility(tray_stand, kTrayStandProcessTime);

            ActivateQueue(enter_queue);

            // pass this customer to next stage
            HandleFood(want_soup);
        }
    }

    // Randomizes the customers to soup and main
    // food.
    void HandleFood(bool want_soup) {
        if (want_soup <= kCustomerWithSoup) {
            HandleSoup();
        } else {
            HandleMainFood();
        }
    }

    // Handles soup and continues to the main
    // food handler after that.
    // If the soup facility is busy, customer
    // will stand in the queue
    void HandleSoup() {
        if (soup_facility.Busy()) {
            soup_queue.Insert(this);
            this->Passivate();
        }

        ProcessFacility(soup_facility, kSoupTakeTime);

        // let someone else from queue in
        ActivateQueue(soup_queue);

        HandleMainFood();
    }

    // Randomizes the customers to prepared and
    // non prepared food
    void HandleMainFood() {
        double food_take = 100 * Random();
        if (food_take <= kCustomerFoodPrepared) {
            // handle prepared food
            Wait(kPreparedFoodTakeTime);
        } else {
            Enter(food_store);
            if (food_take <= kCustomerFoodPrepared + kCustomerFoodPizza) {
                Wait(kPizzaOrderTime);
            } else { // kCustomerFoodUnprepared
                Wait(kUnpreparedFoodTakeTime);
            }
            Leave(food_store);
        }

        HandleWater();
    }

    void HandleWater() {
        double water_take = Random() * 100;
        if (water_take <= kCustomerWithWater) {
            if (water_facility.Busy()) {
                water_queue.Insert(this);
                this->Passivate();
            }

            // process water take
            ProcessFacility(water_facility, kWaterTakeTime);
            // let somebody else use the water machine
            ActivateQueue(water_queue);
        }

        // next stage is ETC
        HandleETC();
    }

    void HandleETC() {
        double etc_take = Random() * 100;
        if (etc_take <= kCustomerWithETC) {
            if (etc_facility.Busy()) {
                etc_queue.Insert(this);
                this->Passivate();
            }

            ProcessFacility(etc_facility, kETCTakeTime);

            ActivateQueue(etc_queue);
        }

        // customer must pay at this moment
        HandlePayment();
    }

    void HandlePayment() {
        if (cashier.Busy()) {
            cashier_queue.Insert(this);
            this->Passivate();
        }

        double payment = Random() * 100;
        // will process payment by card or cash
        ProcessFacility(cashier, (payment <= kPaymentByCash) ? kPaymentByCashTime : kPaymentByISICTime);

        ActivateQueue(cashier_queue);

        HandleTable();
    }

    void HandleTable() {
        Enter(table_places, 1);
        Wait(kEatingTime);
        Leave(table_places, 1);

        HandleTrayReturn();
    }

    // customer must return the tray
    void HandleTrayReturn() {
        if (return_tray.Busy()) {
            return_tray_queue.Insert(this);
            this->Passivate();
        }

        // return the tray
        ProcessFacility(return_tray, kReturnTrayProcessTime);

        ActivateQueue(return_tray_queue);

        // let customer leave now
        HandleLeave();
    }

    void HandleLeave() {

    }
};

class Generator : public Event {
    vector<Customer *> customers;
public:
    Generator() {
        Activate();
    }

    void Behavior() {
        auto c = new Customer;
        customers.push_back(c);
        c->Activate();
        this->Activate(Time + Exponential(kCustomerArrivalTime));
    }
};


int main() {

    Init(0, 60 * 60 * 3);

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