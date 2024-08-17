#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Sensor.h"
#include <array>
#include<memory>
#include<algorithm>
#include<numeric>
#include<optional>
using PtrConatiner = std::shared_ptr<Sensor>;
using ArrayContainer = std::array<PtrConatiner,4>;


// create Objects
void createObjects(ArrayContainer &arr);

std::optional<std::size_t> CountingMatchingSensors(ArrayContainer &arr, SensorType type);

std::optional<bool> AreAllPricesBelowThreshold(ArrayContainer &arr);

std::optional<float> ReturnTotalInsuranceCost(ArrayContainer &arr);

float operator+(Sensor& other);

#endif // FUNCTIONALITIES_H
