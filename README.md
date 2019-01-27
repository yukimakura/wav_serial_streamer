# wav_serial_streamer
## How to build
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## How to use

example1
```
$ ./wav_serial_streamer hogehoge.wav /dev/ttyUSB0
```
example2
```
$ ./wav_serial_streamer hogehoge.wav # Default device is /dev/ttyUSB0
```

## <font color="Red">Please use wav file whose quantization bit is 8 bits and frequency is 11550Hz !!</font>