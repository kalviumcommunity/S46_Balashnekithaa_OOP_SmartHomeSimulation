#include <iostream>
#include <iomanip>
using namespace std;

class SmartLight{
    private:
        string room;
        bool isOn;
        string color;
        int brightness;
    public:
        SmartLight(string room, bool state = false, string color = "White", int brightness = 1){
            this->room = room;
            this->isOn = state;
            this->color = color;
            this->brightness = brightness;
        }
        void turnOn(){
            this->isOn = true;
            cout << "The light in " << this->room << " is now ON" << endl;
        }
        void turnOff(){
            this->isOn = false;
            cout << "The light in " << this->room << " is now OFF." << endl;
        }
        void changeColor(const string& newColor){
            this->color = newColor;
            cout << "The light in " << this->room << " is set to " << this->color << "." << endl;
        }
        void adjustBrightness(const string& level){
            if(level == "off"){
                this->brightness = 0;
                cout << "The brightness in " << this->room << " is set to OFF." << endl;
            }else if(level == "low"){
                this->brightness = 1;
                cout << "The brightness in " << this->room << " is set to LOW." << endl;
            }else if(level == "medium"){
                this->brightness = 2;
                cout << "The brightness in " << this->room << " is set to MEDIUM." << endl;
            }else if(level == "high"){
                this->brightness = 3;
                cout << "The brightness in " << this->room << "is set to HIGH." << endl;
            }else{
                cout << "Invalid brightness level! Please enter 'off', 'low', 'medium', or 'high'." << endl;
            }
        }
        void displayStatus() const {
        cout << fixed << setprecision(1);
        cout << "Light in " << room << ": " 
             << (isOn ? "ON" : "OFF") 
             << ", Color: " << color 
             << ", Brightness: ";
        switch (brightness) {
            case 0: cout << "OFF"; break;
            case 1: cout << "LOW"; break;
            case 2: cout << "MEDIUM"; break;
            case 3: cout << "HIGH"; break;
            default: cout << "UNKNOWN"; break;
        }
        cout << endl;
        }
};

class Thermostat{
    private:
        string room;
        double temperature;
        bool isHeating;
        bool isCooling;
    public:
        Thermostat(string room, double temp = 20.0){
            this->room = room;
            this->temperature = temp;
            this->isHeating = false;
            this->isCooling = false;
        }
        void setTemperature(double temp) {
        this->temperature = temp;
        cout << "The temperature in " << this->room << " is set to " << this->temperature << "°C." << endl;
        }
        void turnHeatingOn() {
        this->isHeating = true;
        this->isCooling = false; 
        cout << "Heating in " << this->room << " is now ON." << endl;
        }
        void turnHeatingOff() {
        this->isHeating = false;
        cout << "Heating in " << this->room << " is now OFF." << endl;
    }
    void turnCoolingOn() {
        this->isCooling = true;
        this->isHeating = false; 
        cout << "Cooling in " << this->room << " is now ON." << endl;
    }
    void turnCoolingOff() {
        this->isCooling = false;
        cout << "Cooling in " << this->room << " is now OFF." << endl;
    }
    void displaySettings() const {
        cout << "Room: " << this->room << endl;
        cout << "Temperature: " << this->temperature << "°C" << endl;
        cout << "Heating: " << (this->isHeating ? "ON" : "OFF") << endl;
        cout << "Cooling: " << (this->isCooling ? "ON" : "OFF") << endl;
    }

};

class SecuritySystem {
private:
    bool isArmed;
    bool isMotionDetected;

public:
    SecuritySystem() {
        this->isArmed = false;
        this->isMotionDetected = false;
    }
    void armSystem() {
        this->isArmed = true;
        cout << "Security system is now ARMED." << endl;
    }
    void disarmSystem() {
        this->isArmed = false;
        cout << "Security system is now DISARMED." << endl;
    }
    void detectMotion() {
        this->isMotionDetected = true;
        cout << "Motion detected! Alerting the authorities." << endl;
    }
    void clearMotion() {
        this->isMotionDetected = false;
        cout << "Motion cleared." << endl;
    }
    void displayStatus() const {
        cout << "Security System: " << (this->isArmed ? "ARMED" : "DISARMED") << endl;
        cout << "Motion Detected: " << (this->isMotionDetected ? "YES" : "NO") << endl;
    }
};


int main(){
    // SmartLight livingRoomLight("Living Room");
    // livingRoomLight.turnOn();
    // livingRoomLight.changeColor("Blue");
    // livingRoomLight.adjustBrightness("medium");
    // livingRoomLight.displayStatus();

    SmartLight* livingRoomLight = new SmartLight("Living Room");
    livingRoomLight->turnOn();
    livingRoomLight->changeColor("Blue");
    livingRoomLight->adjustBrightness("medium");
    livingRoomLight->displayStatus();

    delete livingRoomLight;

    Thermostat* livingRoomThermostat = new Thermostat("Living Room", 22.0);
    livingRoomThermostat->displaySettings();
    livingRoomThermostat->setTemperature(24.0);
    livingRoomThermostat->turnHeatingOn();
    livingRoomThermostat->displaySettings();

    delete livingRoomThermostat;

    SecuritySystem* homeSecurity = new SecuritySystem();
    homeSecurity->displayStatus();
    homeSecurity->armSystem();
    homeSecurity->detectMotion();
    homeSecurity->displayStatus();
    homeSecurity->clearMotion();
    homeSecurity->disarmSystem();
    homeSecurity->displayStatus();

    delete homeSecurity;


    // SmartLight roomLights[3] = {
    //     SmartLight("Living Room"),
    //     SmartLight("Bedroom"),
    //     SmartLight("Kitchen")
    // };

    // for(int i=0; i<3; i++){
    //     roomLights[i].turnOn();
    //     roomLights[i].changeColor("Warm White");
    //     roomLights[i].adjustBrightness("medium");
    //     roomLights[i].displayStatus();
    // }

    // Thermostat livingRoomThermostat("Living Room", 22.0);
    // livingRoomThermostat.displaySettings();
    // livingRoomThermostat.setTemperature(24.0);
    // livingRoomThermostat.turnHeatingOn();
    // livingRoomThermostat.displaySettings();
    // SecuritySystem homeSecurity;
    // homeSecurity.displayStatus();
    // homeSecurity.armSystem();
    // homeSecurity.detectMotion();
    // homeSecurity.displayStatus();
    // homeSecurity.clearMotion();
    // homeSecurity.disarmSystem();
    // homeSecurity.displayStatus();
}