#include "Functionalities.h"
#include "Sensor.h"
int main()
{
    ArrayContainer arr{};
    createObjects(arr);
    std::optional<std::size_t> res = CountingMatchingSensors(arr, SensorType::FUSED);
    if (res.has_value())
    {
        std::cout << res.value() << "\n";
    }
   
}