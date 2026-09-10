# Musesp: Portable Hi-Fi Digital Audio Player

**Musesp** is an open-source, ultra-portable Digital Audio Player (DAP) built on the ESP32-S3 microcontroller. It delivers high-resolution, uncompressed audio playback (FLAC/WAV) via an I2S DAC, featuring a 2.4" TFT graphical user interface and an isolated 3.0A power delivery system for low-noise audio performance.

---

## Technical Features

* **Lossless Audio Streaming:** Dual-core ESP32-S3 (240MHz, 8MB PSRAM) for continuous 24-bit/96kHz audio streaming.
* **Dedicated Hardware DAC:** PCM5102A DAC for clean IEM/headphone driving.
* **UI Navigation:** Hardware SPI ST7789 display paired with dynamic 5-button switch navigation (Play/Pause, Track Next/Prev, Volume +/-).
* **Onboard Storage:** Integrated MicroSD card slot utilization for fast FAT32/exFAT audio library parsing.

---
## Bill of Materials (BOM)

| Component | Description & Usecase | Qty | Unit Price (INR) | Total Price (INR) | Vendor Link |
| :--- | :--- | :---: | :---: | :---: | :--- |
| **ESP32-S3 DevKit (N16R8)** | Dual-core 240MHz MCU with integrated MicroSD slot, 8MB PSRAM & 16MB Flash. Handles audio buffering and display UI directly. | 1 | ₹839 | ₹839 | [Robu.in Link](https://robu.in/product/esp32-s3-devkit-esp32-s3-wroom-1-n16r8/) |
| **PCM5102A I2S DAC Module** | 32-bit / 384kHz Hi-Fi DAC with ~112dB SNR & integrated charge pump. Directly drives 16–32Ω IEMs via 3.5mm jack. | 1 | ₹450 | ₹450 | [Hubtronics Link](https://hubtronics.in/pcm5102-i2s-digital-audio-dac-decoder-module) |
| **2.4" SPI TFT Display (240x320)** | Full-color ST7789 SPI display for album art, track details, playback controls, and menu navigation. | 1 | ₹649 | ₹649 | [Robu.in Link](https://robu.in/product/2-4-inch-spi-interface-240x320-touch-screen-tft-display-module/) |
| **2 PIN WHITE TACT SWITCH C0402** | Switches for navigation and media controls (Play/Pause, Next, Prev, Vol+, Vol-). | 5 | ₹3 | ₹15 | [Robu.in Link](https://robu.in/product/2-pin-white-tact-switch-c0402/) |
| **NOVA 105050 3000mAh 3.7V LiPo Battery** | Single-cell 3.7V LiPo with onboard PCB protection. Delivers ~10–12 hours of continuous playback. | 1 | ₹469 | ₹469 | [Robu.in Link](https://robu.in/product/nova-105050-3000mah-3-7v-micro-lipo-battery-pack/) |
| **TP4056 1A Li-Ion Charger (Mini USB)** | Onboard 1A linear charging module with DW01 IC for over-charge, over-discharge, and short-circuit protection. | 1 | ₹38 | ₹38 | [Robu.in Link](https://robu.in/product/tp4056-1a-li-ion-lithium-battery-charging-module-with-current-protection-mini-usb/) |
| **SPDT Mini Slide Switch** | Physical hard toggle switch between battery positive rail and boost converter for total system shutdown. | 1 | ₹12 | ₹12 | [Robu.in Link](https://robu.in/product-tag/slide-switch/) |
| **Total Hardware Cost** | **Complete Portable Hi-Fi Player Hardware BOM** | 11 | — | **₹2472** | — |

---

## Enclosure & Physical Validation Roadmap

The enclosure will be 3D printed.
To ensure all components fit properly, and im using the right components, i will be designing and printing the case after completing a breadboard prototype.

---


## Milestones & Development Phases

- [x] Hardware architecture & power budget calculation
- [x] Pin mapping & CAD modeling phase
- [ ] Breadboard prototype & signal noise floor analysis
- [ ] Custom PCB layout / perfboard component mounting
- [ ] Enclosure print, mechanical assembly, and integration
- [ ] Final firmware release & public repository publication
