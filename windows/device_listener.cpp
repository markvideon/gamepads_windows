
#include "device_listener.h"

#include <winrt/windows.gaming.input.h>

using namespace std;
using namespace winrt::Windows::Gaming::Input;
using namespace Foundation;

void DeviceListener::onGamepadAdded(IInspectable const& _, Gamepad const& gamepad) {
    // ToDo:
}
void DeviceListener::onGamepadRemoved(IInspectable const& _, Gamepad const& gamepad) {
    // ToDo:
}

void DeviceListener::onRawGameControllerAdded(IInspectable const& _, RawGameController const& gamepad) {
    // ToDo:
}
void DeviceListener::onRawGameControllerRemoved(IInspectable const& _, RawGameController const& gamepad) {
    // ToDo:
}
