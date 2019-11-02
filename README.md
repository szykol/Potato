# Potato
A simple http server 🥔

## How to build
This project uses CMake to build. Run build.sh to build Potato:

```
./build.sh
# Build with debug flag. This enables debugging symbols
./build.sh debug
```

## Run Potato
After sucessful build simply run the binary file:

```
build/potato
```

## Run tests
To run gtests:

```
build/test/Test
```
To run python EndToEnd tests:
```
python -m pip install pytest requests
py.test test/EndToEnd/EndToEndTest.py
```
