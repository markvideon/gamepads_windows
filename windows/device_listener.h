
#ifndef GAMEPADS_WINDOWS_DEVICE_LISTENER_H
#define GAMEPADS_WINDOWS_DEVICE_LISTENER_H

#include <winrt/windows.gaming.input.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <vector>

using namespace winrt::Windows;
using namespace Gaming::Input;
using namespace Foundation;
using namespace std;

class DeviceListener
{
public:
    DeviceListener();
    ~DeviceListener();
    void listGamepads();
private:
    map<string, RawGameController> devices;

    void onRawGameControllerAdded(IInspectable const&, RawGameController const);
    void onRawGameControllerRemoved(IInspectable const&, RawGameController const);
};



#endif //GAMEPADS_WINDOWS_DEVICE_LISTENER_H
