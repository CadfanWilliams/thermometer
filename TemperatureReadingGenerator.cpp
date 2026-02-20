#include <string>
#include <thread>
#include <ctime>
#include <iostream>

class TemperatureReadingGenerator
{
public:
    int interval = 1000;
    double lastTemperature = 24.0;
    void startGenerator()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            std::string payload = generatePayload();
            std::cout << payload << std::endl;
        }
    }

    std::string generatePayload()
    {
        double newTemperature = generateNewTemperature();
        std::string payload = "{\"temperature\": " + std::to_string(newTemperature) + "}";
        lastTemperature = newTemperature;
        return payload;
    }

    double generateNewTemperature()
    {
        srand(time(0));
        double change = (rand() % 200 - 100) / 100.0; // random change between -1.0 and 1.0
        return lastTemperature + change;
    }
};
