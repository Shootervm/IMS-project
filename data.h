#ifndef IMS_PROJECT_DATA_H
#define IMS_PROJECT_DATA_H

typedef struct {
    unsigned int kCapacity = 120,
            kFoodQueueCapacity = 9,
            kCashierQueueCapacity = 10,
            kQueueQuitLength = 25,
            kQueueQuitChance = 15,
            quited = 0; // displays how many customers have decided to quit the  waiting line
} ExperimentEnvironment;


typedef struct {
    double kCustomerWithSoup,
            kCustomerFoodPizza,
            kCustomerFoodPrepared,
            kCustomerWithWater,
            kCustomerWithETC,
            kPaymentByCash;
} ExperimentChances;

// This structure represents data used in experiments.
// From our perspective we have observed, that facility using durations
// do not have big differences between menza stages, that is reason why
// in further experiments we are adjusting only the simulationLength.
// But system is ready to use another duration values and only thing
// needed is edit the initializer for exact stages.
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
extern ExperimentData normal; // state when the lectures are running and small stable amount of customers is arriving
extern ExperimentData closing; // state when menza is about to close
extern ExperimentData opening; // state when menza has just opened
extern ExperimentData typical; // average day cycle of menza

// actual experiment data that are used
extern ExperimentData data; // always is assigned to one of the experiment representation data

extern ExperimentChances chances; // data used to represent chances and probability of decisions of visitors

extern ExperimentEnvironment environment; // experiment environment data, for example capacity

#endif //IMS_PROJECT_DATA_H



