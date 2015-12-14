//
// Created by shooter on 14.12.2015.
//

#ifndef IMS_PROJECT_DATA_H
#define IMS_PROJECT_DATA_H

#include "simulation.h"

ExperimentData opening = {
        60 * 60 * 3, // simulationLength
        17.0, // kCustomerArrivalTime
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
ExperimentData peak = {
        60 * 60 * 3, // simulationLength
        17.0, // kCustomerArrivalTime
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
ExperimentData stable = {
        60 * 60 * 3, // simulationLength
        17.0, // kCustomerArrivalTime
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
        60 * 60 * 3, // simulationLength
        17.0, // kCustomerArrivalTime
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
        17.0, // kCustomerArrivalTime
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

ExperimentData data = typical;
ExperimentEnvironment environment;

#endif //IMS_PROJECT_DATA_H
