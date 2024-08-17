#include "Functionalities.h"

void createObjects(ArrayContainer &arr)
{
    arr[0] = std::make_shared<Sensor>("101", 30.0, SensorType::EMPLACED);
    arr[1] = std::make_shared<Sensor>("102", 40.0, SensorType::INDEPENDENT);
    arr[2] = std::make_shared<Sensor>("103", 50.0, SensorType::EMPLACED);
    arr[3] = std::make_shared<Sensor>("103", 50.0, SensorType::EMPLACED);

}

// Function returns Count of sensor Objects, for given sensorType parameter

std::optional<std::size_t> CountingMatchingSensors(ArrayContainer &arr, SensorType type)
{
    if (arr.empty())
    {
        return std::nullopt;
    }
    bool flag = false;
    int count{0};
    for (PtrConatiner i : arr)
    {
        if (i->getSType() == type)
        {
            flag = true;
            count++;
        }
    }
    if (!flag)
    {
        return std::nullopt;
    }
    else
        return count;
}

// function to return bool for the condition where all instance m_value < 90.0f;

std::optional<bool> AreAllPricesBelowThreshold(ArrayContainer &arr)
{
    if (arr.empty())
    {
        return std::nullopt;
    }
    bool res = std::all_of(
        arr.begin(),
        arr.end(),
        [](PtrConatiner p)
        {
            return p->reading() < 90.0f;
        });
    return res;
}

std::optional<float> ReturnTotalInsuranceCost(ArrayContainer &arr)
{

    if (arr.empty())
    {
        return std::nullopt;
    }
    float total = std::accumulate(
        arr.begin(),
        arr.end(),
        0.0f,
        [](float total, PtrConatiner p)
        {
            return total + p->CalculateErrorDeviation();
        });
    return total;
}

// float operator+(Sensor &other, ArrayContainer arr)
// {
//     for (PtrConatiner p : arr)
//     {
//         return p->reading() + other.reading();
//     }
// }


