#include "customer.h"

Queue enter_queue("Vstupna rada");
Facility tray_stand("Tackovac");

Queue soup_queue("Rada na polievku");
Facility soup_facility("Davanie polievky");

Store food_store("Vydaj jedla", 2);

Queue water_queue("Rada na vydaj pitia");
Facility water_facility("Vydaj pitia");

Queue etc_queue("Rada na vydaj etc");
Facility etc_facility("Salaty, bagety, kolace");

Queue cashier_queue("Rada na platenie");
Facility cashier("Platenie");

Store table_places("Stolovanie", environment.kCapacity);

Queue return_tray_queue("Rada na odlozenie tacok");
Facility return_tray("Pas na tacky");

Customer::Customer() {
    Activate();
}

void Customer::Behavior() {
    if (enter_queue.Length() > environment.kQueueQuitLength) {
        double chance = (100 * Random());
        if (chance <= environment.kQueueQuitChance) {
            environment.quited++;
            return; // quit
        }
    }

    HandleTrayStand();
}

void Customer::ProcessFacility(Facility &f, double w) {
    f.Seize(this);
    Wait(Exponential(w));
    f.Release(this);
}

void Customer::ActivateQueue(Queue &q) {
    if (q.Empty()) {
        return;
    }

    Customer *c = (Customer *) q.GetFirst();
    c->Activate();
}

void Customer::HandleTrayStand() {
    if (tray_stand.Busy()) {
        enter_queue.Insert(this);
        this->Passivate();
    }

    // generate bool from chance if customer wants a soup
    bool want_soup = 100 * Random() <= chances.kCustomerWithSoup;

    //capacity of food Queues are limited, SoupQ and MainFoodQ can together hold up to 8 people
    if (soup_queue.size() + food_store.Q->size() < 9) {
        // get the tray
        ProcessFacility(tray_stand, data.kTrayStandProcessTime);

        ActivateQueue(enter_queue);

        // pass this customer to next stage
        HandleFood(want_soup);
    }
}

void Customer::HandleFood(bool want_soup) {
    if (want_soup <= chances.kCustomerWithSoup) {
        HandleSoup();
    } else {
        HandleMainFood();
    }
}

void Customer::HandleSoup() {
    if (soup_facility.Busy()) {
        soup_queue.Insert(this);
        this->Passivate();
    }

    ProcessFacility(soup_facility, data.kSoupTakeTime);

    // let someone else from queue in
    ActivateQueue(soup_queue);

    HandleMainFood();
}

void Customer::HandleMainFood() {
    double food_take = 100 * Random();
    if (food_take <= chances.kCustomerFoodPrepared) {
        // handle prepared food
        Wait(data.kPreparedFoodTakeTime);
    } else {
        Enter(food_store);
        if (food_take <= chances.kCustomerFoodPrepared + chances.kCustomerFoodPizza) {
            Wait(data.kPizzaOrderTime);
        } else { // kCustomerFoodUnprepared
            Wait(data.kUnpreparedFoodTakeTime);
        }
        Leave(food_store);
    }

    HandleWater();
}

void Customer::HandleWater() {
    double water_take = Random() * 100;
    if (water_take <= chances.kCustomerWithWater) {
        if (water_facility.Busy()) {
            water_queue.Insert(this);
            this->Passivate();
        }

        // process water take
        ProcessFacility(water_facility, data.kWaterTakeTime);
        // let somebody else use the water machine
        ActivateQueue(water_queue);
    }

    // next stage is ETC
    HandleETC();
}

void Customer::HandleETC() {
    double etc_take = Random() * 100;
    if (etc_take <= chances.kCustomerWithETC) {
        if (etc_facility.Busy()) {
            etc_queue.Insert(this);
            this->Passivate();
        }

        ProcessFacility(etc_facility, data.kETCTakeTime);

        ActivateQueue(etc_queue);
    }

    // customer must pay at this moment
    HandlePayment();
}

void Customer::HandlePayment() {
    if (cashier.Busy()) {
        cashier_queue.Insert(this);
        this->Passivate();
    }

    double payment = Random() * 100;
    // will process payment by card or cash
    ProcessFacility(cashier, (payment <= chances.kPaymentByCash) ?
                             data.kPaymentByCashTime : data.kPaymentByISICTime);

    ActivateQueue(cashier_queue);

    HandleTable();
}

void Customer::HandleTable() {
    Enter(table_places, 1);
    Wait(data.kEatingTime);
    Leave(table_places, 1);

    HandleTrayReturn();
}

void Customer::HandleTrayReturn() {
    if (return_tray.Busy()) {
        return_tray_queue.Insert(this);
        this->Passivate();
    }

    // return the tray
    ProcessFacility(return_tray, data.kReturnTrayProcessTime);

    ActivateQueue(return_tray_queue);

    // let customer leave now
    HandleLeave();
}

void Customer::HandleLeave() {

}
