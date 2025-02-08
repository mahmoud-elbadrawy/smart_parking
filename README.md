# Smart Parking System

## Overview
The **Smart Parking System** is an embedded system that automates parking slot detection and gate control using microcontrollers, sensors, and a display. It consists of two microcontrollers:  
- **Master Controller**: Manages the parking lot display, controls the entry gate, and interacts with sensors.  
- **Slave Controller**: Detects parking slot occupancy and sends data to the master via UART.  

## Features
- **Parking Slot Detection**: Uses IR sensors to check if a parking space is occupied.  
- **Automated Gate Control**: Opens/closes the entry gate based on car presence.  
- **Real-time Display**: Shows parking availability on an LCD screen.  
- **Communication via UART**: The slave microcontroller sends slot data to the master.  

## Hardware Components
- **Microcontrollers (Master & Slave)**
- **IR Sensors** for detecting cars in parking slots
- **Servo Motor** for automated gate control
- **LED Indicators** to signal availability
- **LCD Display** for user information
- **UART Communication** for data transfer  

## System Architecture
1. **Slave Microcontroller**:
   - Reads IR sensor data for parking slots.
   - Sends occupancy data via UART to the master.

2. **Master Microcontroller**:
   - Receives data from the slave.
   - Updates the LCD display with parking availability.
   - Controls the servo motor for gate operation.

## Software Implementation
- **Programming Language**: C  
- **Microcontroller Peripherals Used**:
  - **UART** for communication
  - **Timer** for servo control
  - **GPIO** for sensors and LEDs
  - **LCD Library** for display control  

## Installation & Usage
1. **Flash the firmware** to both master and slave microcontrollers.  
2. **Connect the hardware** as per the system diagram.  
3. **Power on the system**:  
   - The LCD shows parking status.  
   - The gate opens when a car is detected at the entrance.  
   - The slave continuously updates the master with slot status.  

## Future Enhancements
- Add **IoT connectivity** for remote monitoring.  
- Implement a **mobile app interface** for real-time slot booking.  
- Integrate **RFID or license plate recognition** for automatic entry.  

## Author

**Mahmoud Elbadrawy**  
- Linkedin: www.linkedin.com/in/mahmoud-elbadrawy
- GitHub: mahmoud-elbadrawy
