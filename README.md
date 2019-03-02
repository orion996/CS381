# CS381 Game Engine Architecture Spring2019

## cse.unr.edu/~sushil/class/381

## installing OGRE
```
sudo -i apt install mercurial build-essential libc6-dev libpthread-stubs0-dev libpthread-workqueue-dev nvidia-cg-toolkit zlib1g-dev zlibc libfreeimage3 libfreeimage-dev libpoco-dev libtbb-dev libgl1 libopenimageio-dev xaw3dg-dev libxaw7-dev libtinyxml-dev freeglut3-dev libglew1.5dev libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev libboost-dev libxrandr-dev libcppunit-dev doxygen libzzip-dev libxft-dev libois-dev

hg clone https://bitbucket.org/sinbad/ogre
cd ogre
hg pull && hg update v1-9-0
curl https://gitweb.gentoo.org/repo/gentoo.git/plain/dev-games/ogre/files/ogre-1.9.0-gcc52.patch | patch -p1
mkdir build
cd build
cmake ../
make -j4
make install
```

## installing Eclipse
```

```
