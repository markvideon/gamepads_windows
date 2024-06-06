#ifndef GAMEPADS_WINDOWS_EVENT_LISTENER_H
#define GAMEPADS_WINDOWS_EVENT_LISTENER_H

#include <winrt/windows.gaming.input.h>
#include <atomic>
#include <functional>
#include <thread>

using namespace std;

namespace gamepads_windows {
    class EventListener {
    public:
        EventListener();
        ~EventListener();
    private:
        thread readerThread;
        atomic_bool shutdownSignal;
    };
}
#endif //GAMEPADS_WINDOWS_EVENT_LISTENER_H
