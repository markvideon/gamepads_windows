#include "gamepads_windows_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

namespace gamepads_windows {

// static
void GamepadsWindowsPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {

  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "xyz.luan/gamepads",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<GamepadsWindowsPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

GamepadsWindowsPlugin::GamepadsWindowsPlugin() {
}

GamepadsWindowsPlugin::~GamepadsWindowsPlugin() {}

void GamepadsWindowsPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("listGamepads") == 0) {
      auto gamepads = devices.listGamepads();
      flutter::EncodableList output;

      for (const auto &item: gamepads) {
          flutter::EncodableMap padMap;

          auto idEntry = map<flutter::EncodableValue, flutter::EncodableValue>::value_type(
                  flutter::EncodableValue("id"),
                  flutter::EncodableValue(to_string(item.second.NonRoamableId()))
                  );

          auto nameEntry = map<flutter::EncodableValue, flutter::EncodableValue>::value_type(
                  flutter::EncodableValue("name"),
                  flutter::EncodableValue(to_string(item.second.DisplayName()))
                  );


          padMap.insert(idEntry);
          padMap.insert(nameEntry);
          output.push_back(padMap);
      }

    result->Success(flutter::EncodableValue(output));
  } else {
    result->NotImplemented();
  }
}

}  // namespace gamepads_windows
