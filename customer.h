
#ifndef IMS_PROJECT_CUSTOMER_H
#define IMS_PROJECT_CUSTOMER_H

#include <iostream>
#include <vector>
#include <simlib.h>
#include "data.h"

extern Queue enter_queue;
extern Facility tray_stand;
extern Queue soup_queue;
extern Facility soup_facility;
extern Store food_store;
extern Queue water_queue;
extern Facility water_facility;
extern Queue etc_queue;
extern Facility etc_facility;
extern Queue cashier_queue;
extern Facility cashier;
extern Store table_places;
extern Queue return_tray_queue;
extern Facility return_tray;


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
