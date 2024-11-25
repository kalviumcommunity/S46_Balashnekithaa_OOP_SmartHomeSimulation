#include <iostream>
#include <vector>
using namespace std;

// Base class for all smart devices
class SmartDevice {
protected:
    string room;

public:
    SmartDevice(const string& room) : room(room) {}

    virtual ~SmartDevice() {}

    virtual void performAction() const = 0; // Virtual function to define device action
    virtual void displayStatus() const = 0; // Virtual function to display status
};

// Derived class: SmartLight
class SmartLight : public SmartDevice {
private:
    bool isOn;
    string color;
    int brightness;

public:
    SmartLight(const string& room, bool isOn = false, string color = "White", int brightness = 1) 
        : SmartDevice(room), isOn(isOn), color(color), brightness(brightness) {}

    void turnOn() { 
        isOn = true; 
        cout << "Light in " << room << " is now ON.\n"; 
    }

    void turnOff() { 
        isOn = false; 
        cout << "Light in " << room << " is now OFF.\n"; 
    }

    void changeColor(const string& newColor) { 
        color = newColor; 
        cout << "Light in " << room << " changed to " << color << ".\n"; 
    }

    void adjustBrightness(int level) { 
        brightness = level; 
        cout << "Brightness in " << room << " set to " << brightness << ".\n"; 
    }

    void performAction() const override {
        cout << "Performing action: Adjusting light in " << room << ".\n";
    }

    void displayStatus() const override {
        cout << "Light in " << room << ": " << (isOn ? "ON" : "OFF") 
             << ", Color: " << color 
             << ", Brightness: " << brightness << endl;
    }
};

// Derived class: Thermostat
class Thermostat : public SmartDevice {
private:
    double temperature;

public:
    Thermostat(const string& room, double temp = 20.0) 
        : SmartDevice(room), temperature(temp) {}

    void setTemperature(double temp) { 
        temperature = temp; 
        cout << "Temperature in " << room << " set to " << temperature << "°C.\n"; 
    }

    void performAction() const override {
        cout << "Performing action: Adjusting thermostat in " << room << ".\n";
    }

    void displayStatus() const override {
        cout << "Thermostat in " << room << ": " << temperature << "°C.\n";
    }
};

// Derived class: SecuritySystem
class SecuritySystem : public SmartDevice {
private:
    bool isArmed;

public:
    SecuritySystem(const string& room = "Home") 
        : SmartDevice(room), isArmed(false) {}

    void armSystem() { 
        isArmed = true; 
        cout << "Security system is now ARMED.\n"; 
    }

    void disarmSystem() { 
        isArmed = false; 
        cout << "Security system is now DISARMED.\n"; 
    }

    void performAction() const override {
        cout << "Performing action: Securing the house.\n";
    }

    void displayStatus() const override {
        cout << "Security System: " << (isArmed ? "ARMED" : "DISARMED") << endl;
    }
};

// New derived class: Fan (example of extension without modifying base classes)
class Fan : public SmartDevice {
private:
    int speed;

public:
    Fan(const string& room, int speed = 1) : SmartDevice(room), speed(speed) {}

    void adjustSpeed(int newSpeed) { 
        speed = newSpeed; 
        cout << "Fan speed in " << room << " set to " << speed << ".\n"; 
    }

    void performAction() const override {
        cout << "Performing action: Adjusting fan speed in " << room << ".\n";
    }

    void displayStatus() const override {
        cout << "Fan in " << room << ": Speed - " << speed << endl;
    }
};

// Main function demonstrating OCP
int main() {
    SmartDevice* devices[4];
    devices[0] = new SmartLight("Living Room");
    devices[1] = new Thermostat("Bedroom");
    devices[2] = new SecuritySystem();
    devices[3] = new Fan("Kitchen");

    for(int i=0; i<4; i++){
        devices[i]->performAction();
        devices[i]->displayStatus();
        cout << "-----------------------\n";
    }

    for(int i=0; i<4; i++){
        delete devices[i];
    }

    return 0;
}
