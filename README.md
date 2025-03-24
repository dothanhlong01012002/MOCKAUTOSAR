## Table of Contents
1. [Overview](#Overview)
2. [Features](#features)
3. [Software Components](#SoftwareComponents)
4. [ECU Allocation](#ECUAllocation)
   
## Overview

The In-Vehicle Air Conditioning System is designed to monitor and manage the vehicle's air conditioning process efficiently. This system leverages temperature and engine speed sensors to ensure optimal cabin comfort while maintaining engine performance. Key functions include continuous temperature monitoring, engine speed monitoring to control air conditioning activation, and compressor activation to regulate cooling.
![image](https://github.com/user-attachments/assets/770892af-64d4-4511-8f1a-49c816499729)

## Features

![image](https://github.com/user-attachments/assets/83fa82b9-917e-45b7-9160-1d622b1bff0d)
1. **Temperature Monitoring:** Continuously reads engine temperature from sensors to ensure the air conditioning system operates within safe temperature limits.
2. **Engine Speed Monitoring:** Continuously reads engine speed, which helps in controlling the activation of the air conditioning system based on the vehicle's performance.
3. **Compressor Activation:** Sends signals to activate the compressor to begin the cooling process when required.
4. **Cooling Fan Activation:** Sends signals to turn on the cooling fan when the engine or air conditioning system reaches a certain temperature threshold.
5. **Fault Diagnosis:** Detects sensor and actuator faults, logs error codes, and triggers alerts for the necessary maintenance or troubleshooting.

## Software Components

1. **EngineSpeedSWC:** Reads and processes data from the engine speed sensor to provide critical input for controlling the air conditioning system.

2. **TemperatureSensorSWC:** Reads and processes data from temperature sensors to monitor the engine and cabin temperature, allowing for precise control of the air conditioning system.

3. **CoolingControlSWC:** Manages the entire temperature control system. Decides whether to turn the air conditioning system on or off based on sensor inputs and predefined thresholds.

4. **CompressorControlSWC:** Controls the refrigeration compressor of the air conditioning system, ensuring efficient cooling when activated.

5. **FanControlSWC:** Controls the air conditioner fan, adjusting its speed based on temperature requirements and ensuring optimal air circulation.

6. **NVMBlock:** Manages data storage and retrieval in non-volatile memory, ensuring the system's settings and configurations are preserved during power cycles.

7. **Parameter WC:** Simulates data from the user or external environment, providing a flexible interface for testing and modifying system parameters.

## ECU Allocation

![image](https://github.com/user-attachments/assets/353bc21c-2079-49f1-8730-3ad8aa813b01)
1. **ECU_01:**
  - Hosts **TemperatureSensorSWC**
    (Runnables: `ReadTemperature_Runnable`)
  - Hosts **EngineSpeedSWC**
    (Runnables: `ReadSpeed_Runnable`)
  - Hosts **IOHwAbTemperatureSensor**
    (Runnables: `ReadVoltage_Runnable`)
  - Hosts **IOHwAbEngineSpeedSensor**
    (Runnables: `ReadPulse_Runnable`)
2. **ECU_02:**
  - Hosts **CoolingControlSWC**
    (Runnables: `CoolingControl_Runnable`)
  - Hosts **FanControlSWC**
    (Runnables: `FanControl_Runnable`)
  - Hosts **CompressorControlSWC**
    (Runnables: `CompressorControl_Runnable`)
  - Hosts **IOHwAbFan**
    (Runnables: `AdjustFan_Runnable`)
  - Hosts **NVBlockSWC**
    (Runnables: `HandleNVM_Runnable`)
  - Hosts **IOHwAbCompressor**
    (Runnables: `AdjustCompressor_Runnable`)
