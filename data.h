
#ifndef IMS_PROJECT_DATA_H
#define IMS_PROJECT_DATA_H

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

// Experiment data that represent four states in cycle
extern ExperimentData peak;  // state when menza is most crowded
extern ExperimentData stable; // state when stable amount of customers is arriving
extern ExperimentData closing; // state when menza is about to close
extern ExperimentData normal; // state when the lectures are running and only few people are arriving to menza
extern ExperimentData typical; // average day cycle of menza

// actual experiment data that are used
extern ExperimentData data; // always is assigned to one of the experiment representation data

extern ExperimentChances chances; // data used to represent chances and probability of decisions of visitors

extern ExperimentEnvironment environment; // experiment environment data, for example capacity

#endif //IMS_PROJECT_DATA_H



