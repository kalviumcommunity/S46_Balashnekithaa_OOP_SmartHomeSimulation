#include <iostream>
#include <iomanip>
using namespace std;

// Interface for switchable devices
class ISwitchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Interface for devices with adjustable settings
class IAdjustable {
public:
    virtual void adjustBrightness(const string& level) = 0;
    virtual void changeColor(const string& color) = 0;
};

// Interface for devices that can monitor or display their status
class IMonitorable {
public:
    virtual void displayStatus() const = 0;
};

// SmartLight class implementing specific interfaces
class SmartLight : public ISwitchable, public IAdjustable, public IMonitorable {
private:
    string room;
    bool isOn;
    string color;
    int brightness;

public:
    SmartLight(string room, bool state = false, string color = "White", int brightness = 1)
        : room(room), isOn(state), color(color), brightness(brightness) {}

    void turnOn() override {
        isOn = true;
        cout << "The light in " << room << " is now ON." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "The light in " << room << " is now OFF." << endl;
    }

    void adjustBrightness(const string& level) override {
        if (level == "low") brightness = 1;
        else if (level == "medium") brightness = 2;
        else if (level == "high") brightness = 3;
        else brightness = 0;  // Off
        cout << "Brightness in " << room << " set to " << level << "." << endl;
    }

    void changeColor(const string& newColor) override {
        color = newColor;
        cout << "Color in " << room << " set to " << color << "." << endl;
    }

    void displayStatus() const override {
        cout << "SmartLight in " << room << ": " 
             << (isOn ? "ON" : "OFF") 
             << ", Color: " << color 
             << ", Brightness: " << brightness << endl;
    }
};

// Thermostat class implementing specific interfaces
class Thermostat : public IMonitorable {
private:
    string room;
    double temperature;

public:
    Thermostat(string room, double temp = 20.0) : room(room), temperature(temp) {}

    void setTemperature(double temp) {
        temperature = temp;
        cout << "Temperature in " << room << " set to " << temperature << "°C." << endl;
    }

    void displayStatus() const override {
        cout << "Thermostat in " << room << " is set to " << temperature << "°C." << endl;
    }
};

// SecuritySystem class implementing specific interfaces
class SecuritySystem : public ISwitchable, public IMonitorable {
private:
    bool isArmed;

public:
    SecuritySystem() : isArmed(false) {}

    void turnOn() override {
        isArmed = true;
        cout << "Security System is ARMED." << endl;
    }

    void turnOff() override {
        isArmed = false;
        cout << "Security System is DISARMED." << endl;
    }

    void displayStatus() const override {
        cout << "Security System is " << (isArmed ? "ARMED" : "DISARMED") << "." << endl;
    }
};

int main() {
    // Demonstrating ISP
    SmartLight livingRoomLight("Living Room");
    Thermostat livingRoomThermostat("Living Room", 22.0);
    SecuritySystem homeSecurity;

    // Using SmartLight
    livingRoomLight.turnOn();
    livingRoomLight.changeColor("Blue");
    livingRoomLight.adjustBrightness("high");
    livingRoomLight.displayStatus();

    // Using Thermostat
    livingRoomThermostat.setTemperature(24.0);
    livingRoomThermostat.displayStatus();

    // Using SecuritySystem
    homeSecurity.turnOn();
    homeSecurity.displayStatus();
    homeSecurity.turnOff();

    return 0;
}
