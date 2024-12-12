# PMSM-RL-Control

This repository integrates modern Reinforcement Learning (RL) algorithms, specifically the Twin Delayed Deep Deterministic Policy Gradient (TD3), with traditional motor control methods for PMSM control based on Field-Oriented Control (FOC). The control framework incorporates PI control, Voltage-by-Frequency (V/f) control, and Model Predictive Control (MPC), with RL replacing the current control component to provide an innovative alternative to conventional methods.

## Structure

The project is divided into two main parts:
- **Simulation**: Conducted using MATLAB 2023a.
- **Deployment**: Conducted using MATLAB 2024b.

## References

The project is based on MATLAB Motor Control Blockset tutorials. For more details, refer to:  
[MATLAB Motor Control Blockset](https://kr.mathworks.com/help/mcb/index.html?s_tid=CRUX_lftnav)

## Real System Hardware

The real system is implemented using the following hardware components:
- **Controller**: TI LAUNCHXL-F28379D
- **Driver**: TI BOOSTXL-DRV8305
- **Motor**: Teknic M-2310P
