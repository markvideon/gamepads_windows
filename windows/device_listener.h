
#ifndef GAMEPADS_WINDOWS_DEVICE_LISTENER_H
#define GAMEPADS_WINDOWS_DEVICE_LISTENER_H

#include <winrt/windows.gaming.input.h>
#include <vector>

using namespace winrt::Windows;
using namespace Gaming::Input;
using namespace Foundation;

class DeviceListener {
public:
    void onGamepadAdded(IInspectable const&, Gamepad const&);
    void onGamepadRemoved(IInspectable const&, Gamepad const&);
    void onRawGameControllerAdded(IInspectable const&, RawGameController const&);
    void onRawGameControllerRemoved(IInspectable const&, RawGameController const&);
};

#endif //GAMEPADS_WINDOWS_DEVICE_LISTENER_H
