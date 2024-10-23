#include <iostream>
#include <iomanip>
using namespace std;

class SmartDevice{
    protected:
        string room;
        bool isOn;
    public:
        SmartDevice(string room = "Unnamed Room", bool state = false){
            this->room = room;
            this->isOn = state;
        }
        virtual void turnOn(){
            if(!isOn){
                isOn = true;
                cout << "The device in " << room << " is now ON" << endl;
            }
        }
        virtual void turnOff(){
            if(isOn){
                isOn = false;
                cout << "The device in " << room << " is now OFF" << endl; 
            }
        }
        virtual void displayStatus() const = 0;
};

class SmartLight : public SmartDevice{
    private:
        string color;
        int brightness;

        static int totalLights;
        static int lightsOn;
    public:
        SmartLight(string room = "Unnamed Room", bool state = false, string color = "White", int brightness = 1) : SmartDevice(room, state), color(color), brightness(brightness) {
            totalLights++;
        }

    ~SmartLight(){
        totalLights--;
        cout << "Destructor called for smart light in " << room << endl;
    }
    void changeColor(const string& newColor) {
        this->color = newColor;
        cout << "The light in " << this->room << " is set to " << this->color << "." << endl;
    }

    void adjustBrightness(const string& level) {
        if (level == "off") {
            this->brightness = 0;
        } else if (level == "low") {
            this->brightness = 1;
        } else if (level == "medium") {
            this->brightness = 2;
        } else if (level == "high") {
            this->brightness = 3;
        } else {
            cout << "Invalid brightness level! Please enter 'off', 'low', 'medium', or 'high'." << endl;
        }
        cout << "The brightness in " << this->room << " is set to " << level << "." << endl;
    }

    void displayStatus() const override {
        cout << "SmartLight in " << room << ": " << (isOn ? "ON" : "OFF")
             << ", Color: " << color
             << ", Brightness: " << (brightness == 0 ? "OFF" : brightness == 1 ? "LOW" : brightness == 2 ? "MEDIUM" : "HIGH") 
             << endl;
    }

    static void resetLightCounters() {
        totalLights = 0;
        lightsOn = 0;
        cout << "Light counters and energy consumption have been reset." << endl;
    }

    static void displayStaticStatus() {
        cout << "Total Lights: " << totalLights << ", Lights On: " << lightsOn << endl;
    }
};

class DimmableLight : public SmartLight {
private:
    int dimmingLevel; 

public:
    DimmableLight(string room, bool state = false, string color = "White", int brightness = 1, int dimmingLevel = 5)
        : SmartLight(room, state, color, brightness), dimmingLevel(dimmingLevel) {}

    void adjustDimming(int level) {
        if (level >= 0 && level <= 10) {
            this->dimmingLevel = level;
            cout << "Dimming level for the light in " << room << " is set to " << dimmingLevel << "." << endl;
        } else {
            cout << "Invalid dimming level! Please enter a level between 0 and 10." << endl;
        }
    }

    void displayStatus() const override {
        SmartLight::displayStatus();
        cout << "Dimming Level: " << dimmingLevel << "/10" << endl;
    }
};

class Thermostat : public SmartDevice {
private:
    double temperature;
    bool isHeating;
    bool isCooling;

public:
    Thermostat(string room, double temp = 20.0) : SmartDevice(room, false), temperature(temp), isHeating(false), isCooling(false) {}

    void setTemperature(double temp) {
        temperature = temp;
        cout << "The temperature in " << this->room << " is set to " << this->temperature << "°C." << endl;
    }

    void turnHeatingOn() {
        this->isHeating = true;
        this->isCooling = false;
        cout << "Heating in " << this->room << " is now ON." << endl;
    }

    void turnCoolingOn() {
        this->isCooling = true;
        this->isHeating = false;
        cout << "Cooling in " << this->room << " is now ON." << endl;
    }

    void displayStatus() const override {
        cout << "Thermostat in " << room << ": " 
             << "Temperature: " << temperature << "°C, "
             << "Heating: " << (isHeating ? "ON" : "OFF") << ", "
             << "Cooling: " << (isCooling ? "ON" : "OFF") << endl;
    }
};

int SmartLight::totalLights = 0;
int SmartLight::lightsOn = 0;

int main(){

    SmartLight livingRoomLight("Living Room", true, "Blue", 2);
    livingRoomLight.displayStatus();

    // Single Inheritance
    DimmableLight bedroomLight("Bedroom", true, "Warm White", 3, 8);
    bedroomLight.adjustDimming(7);
    bedroomLight.displayStatus();

    // Multilevel Inheritance
    Thermostat livingRoomThermostat("Living Room", 22.0);
    livingRoomThermostat.turnHeatingOn();
    livingRoomThermostat.displayStatus();

    return 0;
}