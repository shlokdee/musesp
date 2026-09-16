---
title: "musesp"
author: "f20260342"
description: "An audiophile digital audio player made with esp 32"
created_at: "2026-09-10"
---

# 2026-09-14: Coded a bit more

**Total time spent: 1 hour 30 mins**

Added a bunch more logic to the code. 
First of all, i removed the delay thing, instead replaced it with millis. This will help when i write the music playing function, where i want to continuously play the music, delay wouldve caused gaps in between...

![image.png](https://cdn.hackclub.com/01a0a023-c50d-79bb-a7f2-d06c28e08b35/image.png)

Then I also added what pausing would do. It pauses the whole thing as well as changes the icon. I had an issue where it would constantly refresh the icon every few milliseconds, but i solved it by adding a pause changed variable, which switches the icon every button press.
![image.png](https://cdn.hackclub.com/01a0a024-6a3e-7634-9671-8bef7868d85e/image.png)
Then i added a debounce helper, as button pressing and the actions were unpredictable when i was testing it. a debounce helper basically notes only 1 button press down when you press it, or else the esp takes multiple presses per second if you keep holding it for more than a few ms... This also had caused the play button to just play for a few ms and then stop again, all in a single press. The debounce helper added a bit of margin to it.
![image.png](https://cdn.hackclub.com/01a0a024-07ec-7464-9963-002ee66b29fb/image.png)

# 2026-09-13: Simulated the switches and dummy tested the actions

**Total time spent: 1 hour**

![image.png](https://cdn.hackclub.com/01a09b66-8790-7b74-b781-ea1bb4897210/image.png)

Connected the switches in the simulator, and tested some code for the actions (fwd, bwd, pause, etc...) Still have to figure out the sd situation, thinking about writing some untested code that fetches from the sd card, populates a dictionary with the metadata... and then im trying to declare the dictionary as a variable in the code and write all the code based on that...
![image.png](https://cdn.hackclub.com/01a09b6e-97cb-761a-bfe3-89e875fdc015/image.png)
This is the loop i wrote that displays all the data (i still have to look at the image thing)
Also this delay thing wont work, as ill have to run other processes (like audio playback and list browsing) parallely. 

# 2026-09-13: Designed the case even better

**Total time spent: 1 hour**

I solved the fitting problem of the electronics components. I made a thick back plate, and then extrude cut the outlines of the boards... so that they sit into the surface... 
![image.png](https://cdn.hackclub.com/01a09a44-eddd-750c-877e-83f0c453b9c3/image.png)
I will later add some clips to fasten the boards in place. But right now, the bards have somewhere to sit. Ive also given a but of snuggle room for the boards, as they can be different size from the ones i found step files of...

![Screenshot_From_2026-09-13_15-07-13.png](https://cdn.hackclub.com/01a09a46-ccd1-7621-806c-c66b5205325d/Screenshot_From_2026-09-13_15-07-13.png)

I also aligned and added holes for the charging port and 3.5 mm jack... I will probably add some finishing touches like a fillet and stuff, to make it less sharp. but its a later thing

![Screenshot_From_2026-09-13_15-13-20.png](https://cdn.hackclub.com/01a09a46-ac2d-7637-8e48-22ec97ebfbd5/Screenshot_From_2026-09-13_15-13-20.png)

Also adjusted the height so that it is really thin, as well as the clearances are met...
But, this is going to be adjusted later to make space for the battery... 
![Screenshot_From_2026-09-13_15-41-57.png](https://cdn.hackclub.com/01a09a48-45c0-7981-9149-11a4e3f64a75/Screenshot_From_2026-09-13_15-41-57.png)


![Screenshot_From_2026-09-13_15-44-01.png](https://cdn.hackclub.com/01a09a4a-3d06-70eb-85a6-a886c7cdff86/Screenshot_From_2026-09-13_15-44-01.png)
Im almost done with the design. i will continue with adding buttons later on, and also adding screws for the back plate to fit to the front plate...

The whole body is prolly too thick too, ill reduce the thickness for sure...

# 2026-09-13: Started designing the case

**Total time spent: 1 hour**

I first tried to use fusion 360, but my laptop is slow as hell, so i switched to onshape...

I first downloaded a bunch of step files for the big 3, esp, lcd and the audio driver.
![PCM5102_simple.jpeg](https://cdn.hackclub.com/01a099b0-e4c8-7b52-8b2c-dad63723d6bf/PCM5102_simple.jpeg)
![2.4_TFT.JPG](https://cdn.hackclub.com/01a099b1-2a4f-7ccd-874b-72ee1c640f54/2.4_TFT.JPG)
I also designed a face plate and added holes for buttons to pop up
![image.png](https://cdn.hackclub.com/01a099b2-2b87-726c-80a1-a37723b0a432/image.png)
Arranging them in the space was kinda tricky. firstly, the parts within the component had to be grouped, or else they werent moving together in the assembly. secondly, i couldnt remove the header pins of the display board, so the modules are kinda through the header pins, but ill fix it in real life...
![Screenshot_From_2026-09-13_12-59-55.png](https://cdn.hackclub.com/01a099b2-b424-7251-adfe-7093cf5cb884/Screenshot_From_2026-09-13_12-59-55.png)

Now i have to figure out the mounting thing, i can use bolts for the display and face plate, but something needs to be figured out for the esp and dac. 
Also battery needs to be included, along with carving the 3.5 mm jack and the charging port...

# 2026-09-12: Eureka moment with local wokwi

**Total time spent: 2 hours**

I forgot to Lapse this, but ive got a bunch of screenshots

### I got to know that i can use wokwi locally on vs code!!! 
this heavily reduces the compiling time....
but it took me a while to set up the whole thing...
* I had to install platformio first
* then create a project selecting the right board
* compile the code first, which generates firmware files
* then create a wokwi.toml file that i have to add the firmware file locations
* then copy paste the diagram.json from the online simulator
* then finally run the whole thing...
![Screenshot_From_2026-09-12_21-14-15.png](https://cdn.hackclub.com/01a09675-9ba8-7640-bd85-4d73a7a16485/Screenshot_From_2026-09-12_21-14-15.png)

### Also remade the connections
Got to know that the board has some default spi pins, and the built in sd card is connected to those only...
![image.png](https://cdn.hackclub.com/01a09676-8bde-7d19-a12f-ee463e15a56e/image.png)
So i revised the connections, and connected the display too to the same spi pins..![Screenshot_From_2026-09-12_21-27-31.png](https://cdn.hackclub.com/01a09676-fe55-700e-a590-34e07179ce9f/Screenshot_From_2026-09-12_21-27-31.png)


### Tried making the sd card work with vs code
Uploading files to sd card on online version was a premium feature, i thought it would be different here, but i couldnt figure out a way to do it...
I tried a bunch of different methods, like writing data first and then reading it back (this wouldve been just a temporary solution if worked...), making a folder called sd or sdcard and pray that wokwi would recognise it, etc... I didnt find anything on the docs either...

![Screenshot_From_2026-09-12_21-55-27.png](https://cdn.hackclub.com/01a09679-004f-7503-bf76-3d5aecd7d32f/Screenshot_From_2026-09-12_21-55-27.png)

the sd was initialising, but file reading was not working....

# 2026-09-12: Designed the UI

**Total time spent: 1 hour**

I found this UI builder called lopaka
![image.png](https://cdn.hackclub.com/01a094d5-4151-7157-a947-2bf26dcd296b/image.png)
I used it to design a very basic UI, which was static. and then i can manipulate different stuff using the code... I built it so that its the only screen ill need to design. the songs will be listed in the right grid, and the now playing and buttons are there too....

Then i simulated it in wokwi, altering the lopaka code, and built a moving seeking bar. Ill still have to add some logic to move it according to the song length though.
![image.png](https://cdn.hackclub.com/01a094e5-57fa-72c1-8b79-d3052392b0a6/image.png)

# 2026-09-12: Simulated a very small part of the firmware

**Total time spent: 1.5 hours**

I thought Firmware design would be a piece of cake, ill just stitch together code from various sources and ill be done in a few hours...
but 1.5 hours in, im just done with displaying a small image from the sd to the display :cry:
So here is what i did today: 
### Test the display
![Screenshot_From_2026-09-12_10-42-16.png](https://cdn.hackclub.com/01a0943c-a0e8-7712-a0a6-fbf375809976/Screenshot_From_2026-09-12_10-42-16.png)

I connected the display with the s3 according to the circuit i made yesterday, and started running example code from the libraries. Now the problem was that most of this code was written for Arduino. where the spi lanes area already decided. I didnt know if something like that was there for esp 32 as well. so i spent the fiarst 30 mins in figuring out that i have to declare the spi lanes myself. So i basically perfected the initialisation part, replaced the example code's display initialization with mine, and then run the example. 

I ran a few tests like text display, line display, image display, etc (i forgor to take a ss of this image display without sd card)..

### Test the sd card
Again i ran into problems with spi, and after a whole lot of figuring out, i got to know that you have to keep the same spi lanes for all spi devices. so i did that, and it started working. 
![Screenshot_From_2026-09-12_11-34-40.png](https://cdn.hackclub.com/01a09443-0955-753b-bcd8-ac5d02335547/Screenshot_From_2026-09-12_11-34-40.png)

wokwi wont let me upload anything to the sd card, as uploading was a premium feature, so i instead replaced the wokwi's example code where they demonstrated displaying an image from the sd to display via arduino, with my code and circuitry. and it worked. 
![Screenshot_From_2026-09-12_11-35-43.png](https://cdn.hackclub.com/01a09443-7d22-7358-a5ef-cf232bb14f47/Screenshot_From_2026-09-12_11-35-43.png)


I also uploaded the test codes and connections on github.


## Next steps: 
* Update the kicad with new connections
* Write firmware to read files from the sd card and put the album cover onto the display.
* Update the firmware to browse files from the sd card from the display
* Update the firmware to show the whole ui (now playing, control buttons, seeker, etc.)
* Design a case


# 2026-09-11: Figured out the Display and ESP connections using a simulator

**Total time spent: 1 hr**

I used Cirkit Designer IDE to connect, code and simulate the working of the Display with the esp 32 s3 board.

![image.png](https://cdn.hackclub.com/01a08f66-378a-7393-a37b-d6e9b465106b/image.png)

After this, i will start looking into the firmware for the display driving. 

# 2026-09-10: Added a readme and finished up with other small components

**Total time spent: 1 hour**

Made a readme, with project milestones, working plans. I believe moving ahead from here will require some breadboard prototyping, as im having really a hard time judging if things will work the way i want to. So ive decided to submit the project for review, if approved, get the components, try them together, and then move ahead with other stuff like software and enclosure. 
I also completed the bom for the first phase, with battery and charger. it comes out to around 26 usd. 
![image.png](https://cdn.hackclub.com/01a08b91-86dc-703b-8d6b-991a9878c890/image.png)

# 2026-09-10: Figured out the connections for the main 3 modules

**Total time spent: 1 hour**

I looked around on the internet, read the seller specifications and laid out the basic connections for the 3 modules. The s3 variant of esp32 gave me a hard time. This is subject to change, as most of the reiterations on the hardware side is going to happen only after i receive the components. After that, i can actually test out the stuff and make changes. The schematic i made is kinda speculative, as most of the connections were for esp 32 and not s3. 
![image.png](https://cdn.hackclub.com/01a08b19-79aa-7c0e-a833-280361addf81/image.png)

Next steps: Figure out the additional components, like battery management, buttons, etc. and build the case.

# 2026-09-10: Searched about various components required to build the project

**Total time spent: 2 hours**

I spent some time today researching the core hardware architecture for my portable Hi-Fi audio player, and preparing the basic BOM (essential components right now, others will be added later). The goal is to build an iPod-style player capable of driving sensitive In-Ear Monitors (IEMs) with zero noise or hiss, playing lossless files (WAV/FLAC), and maintaining a fully modular design so components can be swapped out easily.

### Key Decisions & Hardware Reasoning

- **Microcontroller: ESP32-S3 (with PSRAM)**
    
    - _Why:_ Standard microcontrollers like an Arduino Uno dont have the processing power or hardware peripherals for real-time audio decoding. The ESP32 offers native I2S bus support, dual-core processing, and built-in Wi-Fi/Bluetooth. Using an ESP32-S3 with external PSRAM gives the large RAM buffer needed to stream 16-bit/24-bit FLAC files off an SD card without playback stutter as well as render the album art properly. Also the one i put in the BOM has a SD card slot as well.
        ![image.png](https://cdn.hackclub.com/01a08a93-85d9-71b8-b139-df0bbe797347/image.png)

- **DAC Module: TI PCM5102A (Over UDA1334A or MAX98357A)**
    
    - _Why:_ IEMs are extremely sensitive to background hiss. The other dac modules i looked at were either too high powered, or too low quality
        ![image.png](https://cdn.hackclub.com/01a08a94-0f35-7803-9936-1180950c5b09/image.png)

- **Display: ST7789 2.0"/2.4" SPI TFT LCD (240x320)**
    
    - _Why:_ Other OLEDs (like the SSD1306) are too small to render track lists and album art nicely. This is perfectly sized, works over SPI.
      ![image.png](https://cdn.hackclub.com/01a08a94-9a1b-7b12-ab50-fcbbdc186974/image.png)


### What's Next?

Now that the hardware strategy is locked in, Im going to start looking at connections and start building the basic 3d structure of the player. Im also going to add other components like battery, charging circuit, etc to the BOM

