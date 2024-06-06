#include "device_listener.h"
#include "event_listener.h"
#include <atomic>
#include <iostream>
#include <thread>

using namespace std;
using namespace winrt::Windows::Gaming::Input;

const int MIN_MILLIS_BETWEEN_READS = 17;

namespace gamepads_windows {
    EventListener::EventListener() {
        shutdownSignal.store(false);

        readerThread = thread([this]() {
            while (!shutdownSignal.load()) {
                auto now = chrono::steady_clock::now();
                auto then =
                        now + chrono::milliseconds(MIN_MILLIS_BETWEEN_READS);
                // ToDo: poll each device
                this_thread::sleep_until(then);
            }
        });
    }

    EventListener::~EventListener() {
        shutdownSignal.store(true);
        readerThread.join();
    }
}