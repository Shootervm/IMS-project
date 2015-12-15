#include "data.h"

ExperimentData peak = {
        60 * 60 * 2, // simulationLength
        6.0, // kCustomerArrivalTime
        4.65, // kTrayStandProcessTime
        5.2, // kSoupTakeTime
        10.0, // kPizzaOrderTime
        6.0, // kPreparedFoodTakeTime
        16.0, // kUnpreparedFoodTakeTime
        7.3, // kWaterTakeTime
        5.5, // kETCTakeTime
        15.0, // kPaymentByCashTime
        6.5, // kPaymentByISICTime
        1080.0, // kEatingTime
        4.0 // kReturnTrayProcessTime
};
ExperimentData normal = {
        60 * 60 * 2, // simulationLength
        37.0, // kCustomerArrivalTime
        4.65, // kTrayStandProcessTime
        5.2, // kSoupTakeTime
        10.0, // kPizzaOrderTime
        6.0, // kPreparedFoodTakeTime
        16.0, // kUnpreparedFoodTakeTime
        7.3, // kWaterTakeTime
        5.5, // kETCTakeTime
        15.0, // kPaymentByCashTime
        6.5, // kPaymentByISICTime
        1080.0, // kEatingTime
        4.0 // kReturnTrayProcessTime
};
ExperimentData closing = {
        60 * 60 * 2, // simulationLength
        11.0, // kCustomerArrivalTime
        4.65, // kTrayStandProcessTime
        5.2, // kSoupTakeTime
        10.0, // kPizzaOrderTime
        6.0, // kPreparedFoodTakeTime
        16.0, // kUnpreparedFoodTakeTime
        7.3, // kWaterTakeTime
        5.5, // kETCTakeTime
        15.0, // kPaymentByCashTime
        6.5, // kPaymentByISICTime
        1080.0, // kEatingTime
        4.0 // kReturnTrayProcessTime
};
ExperimentData opening = {
        60 * 60 * 2, // simulationLength
        16.0, // kCustomerArrivalTime
        4.65, // kTrayStandProcessTime
        5.2, // kSoupTakeTime
        10.0, // kPizzaOrderTime
        6.0, // kPreparedFoodTakeTime
        16.0, // kUnpreparedFoodTakeTime
        7.3, // kWaterTakeTime
        5.5, // kETCTakeTime
        15.0, // kPaymentByCashTime
        6.5, // kPaymentByISICTime
        1080.0, // kEatingTime
        4.0 // kReturnTrayProcessTime
};

ExperimentData typical = {
        60 * 60 * 3, // simulationLength
        17.5, // kCustomerArrivalTime
        4.65, // kTrayStandProcessTime
        5.2, // kSoupTakeTime
        10.0, // kPizzaOrderTime
        6.0, // kPreparedFoodTakeTime
        16.0, // kUnpreparedFoodTakeTime
        7.3, // kWaterTakeTime
        5.5, // kETCTakeTime
        15.0, // kPaymentByCashTime
        6.5, // kPaymentByISICTime
        1080.0, // kEatingTime
        4.0 // kReturnTrayProcessTime
};

ExperimentChances chances = {
        .kCustomerWithSoup = 30.0,
        .kCustomerFoodPizza = 15.0,
        .kCustomerFoodPrepared = 30.0,
        .kCustomerWithWater = 65.0,
        .kCustomerWithETC = 40.0,
        .kPaymentByCash = 25.0
};

#ifdef E_PEAK
ExperimentData data = peak;
#elif E_OPENING
ExperimentData data = opening;
#elif E_NORMAL
ExperimentData data = normal;
#elif E_CLOSING
ExperimentData data = closing;
#elif E_TYPICAL
ExperimentData data = typical;
#else
ExperimentData data = typical;
#endif

ExperimentEnvironment environment;



