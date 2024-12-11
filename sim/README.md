# PMSM Control Simulation

This repository contains simulations for controlling a Permanent Magnet Synchronous Motor (PMSM) using Field-Oriented Control (FOC). The simulations are implemented in three different control strategies:

1. **Traditional PI Control**
2. **Reinforcement Learning (RL) Based Control**
3. **Model Predictive Control (MPC)**

To explore each simulation, navigate to the respective directory.

---

## Reinforcement Learning (RL) Control

In the RL-based control, the reward function plays a crucial role in determining the performance. Below is the reward curve for the RL agent:

![Reward Image](./sim_data/agent/reward.png)

---

### Response Analysis

The figure below shows the motor's response under different reward coefficients. 

- **Red Line:** Reference Speed  
- **Green Line:** Reward coefficients \( Q_1, Q_2 = 10 \), \( R = 0.1 \)  
- **Yellow Line:** Reward coefficients \( Q_1, Q_2 = 50 \), \( R = 0.5 \)  
- **Blue Line:** Reward coefficients \( Q_1, Q_2 = 5 \), \( R = 0.1 \)  

![Response Image](./sim_data/agent/reward_var.png)

---

### Step Response Evaluation

To evaluate the step response of the simulated data, use the provided MATLAB Live Script:

**File:** `step_response.mlx`
