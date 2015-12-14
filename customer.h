
#ifndef IMS_PROJECT_CUSTOMER_H
#define IMS_PROJECT_CUSTOMER_H

#include <iostream>
#include <vector>
#include "data.h"

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

Store table_places("Stolovanie", environment.kCapacity);

Queue return_tray_queue("Rada na odlozenie tacok");
Facility return_tray("Pas na tacky");

class Customer : public Process {
public:
    Customer();

    void Behavior();

    inline void ProcessFacility(Facility &f, double w);

    inline void ActivateQueue(Queue &q);

    void HandleTrayStand();

    // Randomizes the customers to soup and main
    // food.
    void HandleFood(bool want_soup);

    // Handles soup and continues to the main
    // food handler after that.
    // If the soup facility is busy, customer
    // will stand in the queue
    void HandleSoup();

    // Randomizes the customers to prepared and
    // non prepared food
    void HandleMainFood();

    void HandleWater();

    void HandleETC();

    void HandlePayment();

    void HandleTable();

    // customer must return the tray
    void HandleTrayReturn();

    void HandleLeave();
};

#endif //IMS_PROJECT_CUSTOMER_H
