#scons platform=android target=release android_arch=armv7 android_stl=yes
scons platform=android target=release android_arch=arm64v8  android_stl=yes

scons platform=android target=release_debug android_arch=armv7 android_stl=yes
scons platform=android target=release_debug android_arch=arm64v8 android_stl=yes

scons platform=android target=release android_arch=x86 android_stl=yes
scons platform=android target=release android_arch=x86_64 android_stl=yes

scons platform=android target=release_debug android_arch=x86 android_stl=yes
scons platform=android target=release_debug android_arch=x86_64 android_stl=yes