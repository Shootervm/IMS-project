
#ifndef IMS_PROJECT_SIMULATION_H
#define IMS_PROJECT_SIMULATION_H

#include <simlib.h>

typedef struct {
    unsigned int kCapacity = 120,
            kQueueQuitLength = 25,
            kQueueQuitChance = 15,
            quited = 0;
} ExperimentEnvironment;


typedef struct {
    double kCustomerWithSoup,
            kCustomerFoodPizza,
            kCustomerFoodPrepared,
            kCustomerWithWater,
            kCustomerWithETC,
            kPaymentByCash;
} ExperimentChances;


typedef struct {
    unsigned int simulationLength;
    double kCustomerArrivalTime,
            kTrayStandProcessTime,
            kSoupTakeTime,
            kPizzaOrderTime,
            kPreparedFoodTakeTime,
            kUnpreparedFoodTakeTime,
            kWaterTakeTime,
            kETCTakeTime,
            kPaymentByCashTime,
            kPaymentByISICTime,
            kEatingTime,
            kReturnTrayProcessTime;
} ExperimentData;


#endif //IMS_PROJECT_SIMULATION_H



