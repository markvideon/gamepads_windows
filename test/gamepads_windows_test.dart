import 'package:flutter_test/flutter_test.dart';
import 'package:gamepads_windows/gamepads_windows.dart';
import 'package:gamepads_windows/gamepads_windows_platform_interface.dart';
import 'package:gamepads_windows/gamepads_windows_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockGamepadsWindowsPlatform
    with MockPlatformInterfaceMixin
    implements GamepadsWindowsPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final GamepadsWindowsPlatform initialPlatform = GamepadsWindowsPlatform.instance;

  test('$MethodChannelGamepadsWindows is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelGamepadsWindows>());
  });

  test('getPlatformVersion', () async {
    GamepadsWindows gamepadsWindowsPlugin = GamepadsWindows();
    MockGamepadsWindowsPlatform fakePlatform = MockGamepadsWindowsPlatform();
    GamepadsWindowsPlatform.instance = fakePlatform;

    expect(await gamepadsWindowsPlugin.getPlatformVersion(), '42');
  });
}
