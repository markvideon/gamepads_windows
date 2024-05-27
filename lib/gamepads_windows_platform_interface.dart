import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'gamepads_windows_method_channel.dart';

abstract class GamepadsWindowsPlatform extends PlatformInterface {
  /// Constructs a GamepadsWindowsPlatform.
  GamepadsWindowsPlatform() : super(token: _token);

  static final Object _token = Object();

  static GamepadsWindowsPlatform _instance = MethodChannelGamepadsWindows();

  /// The default instance of [GamepadsWindowsPlatform] to use.
  ///
  /// Defaults to [MethodChannelGamepadsWindows].
  static GamepadsWindowsPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [GamepadsWindowsPlatform] when
  /// they register themselves.
  static set instance(GamepadsWindowsPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
