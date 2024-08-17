#include "Sensor.h"

float Sensor::CalculateErrorDeviation()
{
    return 0.2 * m_reading;
}

// void Sensor::operation(float &other)
// {
// }
