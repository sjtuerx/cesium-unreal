# Cesium for Unreal Engine

## Prerequisites

* Visual Studio 2019
* CMake (add it to your path during install!)

## Getting Started

* Check out the repo with `git clone git@github.com:CesiumGS/cesium-unreal.git --recurse-submodules` so that you get the third party submodules.
* Build `cesium-native` by following the instructions in `Plugins\Cesium\extern\cesium-native\README.md`. Skip step 1 (cloning the repo) because it is already included as a git submodule in this repo under `Plugins\Cesium\extern\cesium-native`.
* Open cesiumunreal.uproject in the Unreal Editor.
* Say "yes" when prompted to rebuild `cesiumunreal` and `Cesium`.
* Generate Visual Studio project files manually by choosing `File -> [Refresh/Generate] Visual Studio Project` in the editor.
* Open the project in Visual Studio by going to `File -> Open Visual Studio`

## Tips

### Build errors on open

After loading the project in Unreal Editor and click "yes" to rebuild, something could go wrong preventing the project from building. And when that happens, it's hard to see what happened because the Editor closes before you can see the log. To work around this, right-click on the `cesiumunreal.uproject` file and click "Generate Visual Studio Project files". Then open the generated cesiumunreal.sln in Visual Studio and compile it there.

### Hot Reloading

Changes made to the game project (cesiumunreal), when compiled, will be hot-reloaded by the Unreal Editor. But this doesn't work for changes in the plugin (Cesium). To build and reload plugin changes without restarting the editor, go to Window -> Developer Tools -> Modules, search for Cesium, and click the "Recompile" button next to it.

### Coordinate Systems

There are a bunch of coordinate systems involved, and it can get confusing. The most important ones are:

* Unreal Engine: Left-handed, +X is forward, +Y is right, +Z is up
* [glTF](https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#coordinate-system-and-units): Right-handed, +X is left, +Y is up, +Z is forward
* Cesium: Right-handed, +X is forward, +Y is left, +Z is up
