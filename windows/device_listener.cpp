#include "DeviceListener.h"
#include <winrt/windows.gaming.input.h>
#include <iostream>

using namespace std;
using namespace winrt::Windows::Gaming::Input;
using namespace Foundation;

DeviceListener::DeviceListener() {
    devices = {};
    RawGameController::RawGameControllerAdded({ this , &DeviceListener::onRawGameControllerAdded });
    RawGameController::RawGameControllerRemoved({ this, &DeviceListener::onRawGameControllerRemoved });
}

DeviceListener::~DeviceListener() {
    devices.clear();
}

void DeviceListener::listGamepads() {
    for (auto entries : devices) {
        cout << to_string(entries.second.DisplayName()) << endl;
    }
}

void DeviceListener::onRawGameControllerAdded(IInspectable const& _, RawGameController const gamepad) {
    string id = to_string(gamepad.NonRoamableId());
    auto mapEntry = map<string, RawGameController>::value_type(id, gamepad);
    devices.insert(mapEntry);
}
void DeviceListener::onRawGameControllerRemoved(IInspectable const& _, RawGameController const gamepad) {
    string id = to_string(gamepad.NonRoamableId());
    devices.erase(id);
}
