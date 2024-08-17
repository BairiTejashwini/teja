#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include "SensorType.h"
class Sensor
{
private:
    std::string m_sensor_id{""};
    float m_reading{0.0};
    enum SensorType sType
    {
        SensorType::EMPLACED
    };
    

public:
    Sensor(std::string sensorId, float reading, SensorType stype) : m_sensor_id{sensorId}, m_reading{reading}, sType{stype} {};
    ~Sensor() = default;
    Sensor() = default;
    Sensor(const Sensor &other) = default;
    Sensor &operator=(const Sensor &other) = default;
    Sensor(Sensor &&other) = default;
    Sensor &operator=(Sensor &&other) = default;

    float CalculateErrorDeviation();

    float operator+(float other)
    {
        return m_reading + other;
    }

    enum SensorType getSType() const { return sType; }
    void setSType(const enum SensorType &sType_) { sType = sType_; }

    float reading() const { return m_reading; }
    void setReading(float reading) { m_reading = reading; }
};

#endif // SENSOR_H
