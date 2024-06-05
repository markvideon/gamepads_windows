#include "gamepads_windows_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

using namespace flutter;
using namespace std;

namespace gamepads_windows {
// static
void GamepadsWindowsPlugin::RegisterWithRegistrar(
    PluginRegistrarWindows *registrar) {

  auto channel =
      make_unique<MethodChannel<EncodableValue>>(
          registrar->messenger(), "xyz.luan/gamepads",
          &StandardMethodCodec::GetInstance());

  auto plugin = make_unique<GamepadsWindowsPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, move(result));
      });

  registrar->AddPlugin(move(plugin));
}

GamepadsWindowsPlugin::GamepadsWindowsPlugin() {
}

GamepadsWindowsPlugin::~GamepadsWindowsPlugin() {}

void GamepadsWindowsPlugin::HandleMethodCall(
    const MethodCall<EncodableValue> &method_call,
    unique_ptr<MethodResult<EncodableValue>> result) {
  if (method_call.method_name().compare("listGamepads") == 0) {
      auto gamepads = devices.listGamepads();
      EncodableList output;

      for (const auto &item: gamepads) {
          EncodableMap padMap;

          auto idEntry = map<EncodableValue, EncodableValue>::value_type(
                  EncodableValue("id"),
                  EncodableValue(to_string(item.second.NonRoamableId()))
                  );

          auto nameEntry = map<EncodableValue, EncodableValue>::value_type(
                  EncodableValue("name"),
                  EncodableValue(to_string(item.second.DisplayName()))
                  );


          padMap.insert(idEntry);
          padMap.insert(nameEntry);
          output.push_back(padMap);
      }

    result->Success(EncodableValue(output));
  } else {
    result->NotImplemented();
  }
}

}  // namespace gamepads_windows
