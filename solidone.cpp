#include <iostream>
#include <iomanip>
using namespace std;

class SmartLight {
private:
    string room;
    bool isOn;
    string color;
    int brightness;

public:
    
    SmartLight(string room, bool isOn = false, string color = "White", int brightness = 1) 
        : room(room), isOn(isOn), color(color), brightness(brightness) {}

    
    void turnOn() { 
        isOn = true; 
        cout << "Light in " << room << " is now ON.\n"; 
    }

    void turnOff() { 
        isOn = false; 
        cout << "Light in " << room << " is now OFF.\n"; 
    }

    void changeColor(string newColor) { 
        color = newColor; 
        cout << "Light in " << room << " changed to " << color << ".\n"; 
    }

    void adjustBrightness(int level) { 
        brightness = level; 
        cout << "Brightness in " << room << " set to " << brightness << ".\n"; 
    }

    void displayStatus() const {
        cout << "Light in " << room << ": " << (isOn ? "ON" : "OFF") 
             << ", Color: " << color 
             << ", Brightness: " << brightness << endl;
    }
};

class Thermostat {
private:
    string room;
    double temperature;

public:
    Thermostat(string room, double temp = 20.0) 
        : room(room), temperature(temp) {}

    void setTemperature(double temp) { 
        temperature = temp; 
        cout << "Temperature in " << room << " set to " << temperature << "°C.\n"; 
    }

    void displaySettings() const {
        cout << "Thermostat in " << room << ": " << temperature << "°C.\n";
    }
};

class SecuritySystem {
private:
    bool isArmed;

public:
    SecuritySystem() : isArmed(false) {}

    void armSystem() { 
        isArmed = true; 
        cout << "Security system is now ARMED.\n"; 
    }

    void disarmSystem() { 
        isArmed = false; 
        cout << "Security system is now DISARMED.\n"; 
    }

    void displayStatus() const {
        cout << "Security System: " << (isArmed ? "ARMED" : "DISARMED") << endl;
    }
};

int main() {
    SmartLight livingRoomLight("Living Room");
    livingRoomLight.turnOn();
    livingRoomLight.changeColor("Blue");
    livingRoomLight.adjustBrightness(2);
    livingRoomLight.displayStatus();

    Thermostat livingRoomThermostat("Living Room");
    livingRoomThermostat.setTemperature(24.0);
    livingRoomThermostat.displaySettings();

    SecuritySystem homeSecurity;
    homeSecurity.armSystem();
    homeSecurity.displayStatus();

    return 0;
}
