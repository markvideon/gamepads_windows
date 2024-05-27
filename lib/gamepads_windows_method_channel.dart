import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'gamepads_windows_platform_interface.dart';

/// An implementation of [GamepadsWindowsPlatform] that uses method channels.
class MethodChannelGamepadsWindows extends GamepadsWindowsPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('gamepads_windows');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
