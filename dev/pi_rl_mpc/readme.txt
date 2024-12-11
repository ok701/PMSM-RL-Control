THis is for simulation of pmsm with foc control using pi and replaced with reinforcement learning


run main.mlx 
Default parameters 
Teknic

if you want to change motor parameters, change
pmsm = mcb_SetPMSMMotorParameters('Teknic2310P');
pmsm.PositionOffset = 0.0755;


viscous friction accounted
static friction not accounted

for reinforcement learning go to traning directory.
gist_agent_baseline is previously trained agent for upper model.


mpc model is still in update.
object should be included in the future.