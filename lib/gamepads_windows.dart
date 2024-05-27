
import 'gamepads_windows_platform_interface.dart';

class GamepadsWindows {
  Future<String?> getPlatformVersion() {
    return GamepadsWindowsPlatform.instance.getPlatformVersion();
  }
}
