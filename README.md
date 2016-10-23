# V(anilla)cash

## A decentralized currency for the internet.


### Dependencies:

* boost 1.53.0
* db-6.1.29.NC
* openssl 1.0.1q

Windows also requires miniupnpc but can be disabled by the use of USE_UPNP=0.


### Building in Linux Ubuntu

https://github.com/john-connor/azure-quickstart-templates/blob/master/vcash-on-ubuntu/build_vcash.sh

Usage:
```
curl -s https://raw.githubusercontent.com/john-connor/azure-quickstart-templates/master/vcash-on-ubuntu/build_vcash.sh | bash /dev/stdin From_Source
```


### All other Linux distributions

https://github.com/john-connor/vcash-scripts/blob/master/build-linux.sh


## Compiling manually (Linux, Mac, Windows)

```
Extract boost to ./deps

cd ./deps/boost

run ./bootstrap.sh or ./bootstrap.bat

Copy bjam if needed.


### For Linux:

./bjam link=static toolset=gcc cxxflags=-std=gnu++0x --with-system release install

Extract db and openssl to ./deps/db and ./deps/openssl

Compile db and openssl

cd ./

./bjam toolset=gcc cxxflags=-std=gnu++0x release

cd test

./bjam toolset=gcc cxxflags=-std=gnu++0x release


### For MacOS X:

./bjam link=static --with-system toolset=clang cxxflags="-std=c++11 -stdlib=libc++" release install

Extract db and openssl to ./deps/platforms/osx

Compile db and openssl

cd ../../

cp ./deps.boost/bjam .

./bjam toolset=clang cxxflags="-std=c++11 -stdlib=libc++" linkflags="-stdlib=libc++" release

cd test

./bjam toolset=clang cxxflags="-std=c++11 -stdlib=libc++" linkflags="-stdlib=libc++" release


### For Windows (using Bash shell):

Edit ./deps/boost/boost/detail/impl/win_iocp_io_service.ipp and add the following line before `pragma once`:

`#include <algorithm> // for min/max`

bjam.exe link=static runtime-link=static --with-system toolset=msvc release install

Extract db, openssl and miniupnpc to ./deps/platforms/windows

Compile db, openssl and miniupnpc using Visual Studio.

cd ../../

cp ./deps/boost/bjam.exe .

./bjam.exe toolset=msvc link=static runtime-link=static release

cd test

../bjam.exe toolset=msvc link=static runtime-link=static release

Note: The test will fail because of missing <endian.h> which is a Linux-only file.
```

## Result:

After all this effort you end up with a few libraries. There is no GUI in this repository.
