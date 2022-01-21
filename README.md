# osimhash
A deduplication lib built **O**ver [**SIMHASH**](https://github.com/yanyiwu/simhash) lib, this provides:
* Simplified but necessary apis.
* An extra api supports user pre-define key-words, which means this supports simhash for multi-languages.
* Detailed benchmarkings.
* A python binding.


## How to Use
### Integrate into Your CPP Project
It's a header lib, just include `include` path.

### Build Bindings
#### Python 
##### Build From Source
Using python3.7 as example, run
```sh
mkdir build && cd build
cmake ../ -DOSIMHASH_PY_BIND=ON -DPYTHON_EXECUTABLE="/usr/bin/python3.7"
make -j12
```
The python moduls is located under `build/bindings/python/pyosimhash.cpython-37m-x86_64-linux-gnu.so`.
##### With `pip install`
```sh
python -m pip install ${OSIMHASH_PATH}
# or
python -m pip install https://github.com/innerNULL/osimhash.git
# or 
python -m pip install https://github.com/innerNULL/osimhash/archive/refs/heads/main.zip
```

### Run Examples
#### Python
* Build Python binding first
* Run
```sh
cd build && python3 -m venv osimhash_example
source ./osimhash_example/bin/activate
pip install -r ../examples/python/requirements.txt
deactivate
```

### Run Benchmarks
#### CPP
Run
```sh
mkdir build && cd build
cmake ../
make -j12
./benchmarks/cpp/benchmarking
```

#### Python
* Build Python binding first
* Run
```sh
cd build && python3 -m venv osimhash_benchmark
source ./osimhash_benchmark/bin/activate
pip install -r ../benchmarks/python/requirements.txt
python ../benchmarks/python/benchmarking.py
deactivate
```

### Benchmarks
See [benchmark](https://github.com/innerNULL/osimhash/blob/main/doc/benchmark.md)
