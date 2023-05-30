# Arduino Macro Board With Display
## _First project with Lil Pap_

This is a big project that integrates a couple of technologies and is going to improve my everyday life. Its a small display that sits in my desk and I connect it to my computer to show stats and control something over it.

What are we going to use in this project
- Arduino
  - Rotary Encoder
  - 0.96 OLED Display
- Python
  - Getting and sending the data to the Arduino
- 3D design 
  - designing and then printing the case for the board, encoder, display
- (Maybe) PCB design the whole hardware connections

## Features
So that board will be capable to control lots of stuff all over your pc. We are going to split up the stats/capabilities that is going to have

### Computer stats
This board is going to be able to show stats like
- CPU Usage
- GPU Usage
- CPU/GPU Temp
- ~~Fan Speed~~
- Memory Usage
- Disk Usage
- Network Speed
- Battery Level
- Computer Time

### API data
This board through the python can read some data from the web and then display them to the screen. There are more like fun, chill, but still usefull stats there (we may create an api with slang quotes right here)
- Weather stats
- Jokes api
- Chuck Norris Api
- Joke Api
- Our Slang Api

### Macros
Maybe a good idea is to change something in our computer like:
- The volume
- Brightness
- Third party apps like, photoshop brush size

### Other Functionalities
- Pomodoro Timer
