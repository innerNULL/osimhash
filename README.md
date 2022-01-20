# osimhash
A lib which is **O**ver [**SIMHASH**](https://github.com/yanyiwu/simhash) lib, this provides:
* Simplified but necessary apis.
* An extra api supports user pre-define key-words, which means this supports simhash for multi-languages.
* Detailed benchmarkings.
* A python binding.


## How to Use
### Integrate into Your CPP Project
It's a header lib, just include `include` path.

### Build CPP Benchmarks
Run
```sh
mkdir build && cd build
cmake ../
make -j12
./benchmarks/cpp/benchmarking
```

### Build Python Module From Source
Using python3.7 as example, run
```sh
mkdir build && cd build
cmake ../ -DPYBIND=ON -DPYTHON_EXECUTABLE="/usr/bin/python3.7"
make -j12
```
The python moduls is located under `build/bindings/python/pyosimhash.cpython-37m-x86_64-linux-gnu.so`.


### Benchmarks
See [benchmark](https://github.com/innerNULL/osimhash/blob/main/doc/benchmark.md)
