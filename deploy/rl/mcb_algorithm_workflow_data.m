%% Initialize bus signals and global data structures used in MCB workflow example

% Copyright 2020 The MathWorks, Inc.

% Simulink signal share share data between system model and referenced model. 
IaOffset = Simulink.Signal;
IaOffset.DataType = 'uint16';
IaOffset.Dimensions = 1;
IaOffset.Complexity = 'real';
IaOffset.InitialValue = num2str(inverter.CtSensAOffset);

IbOffset = Simulink.Signal;
IbOffset.DataType = 'uint16';
IbOffset.Dimensions = 1;
IbOffset.Complexity = 'real';
IbOffset.InitialValue = num2str(inverter.CtSensBOffset);

EnClosedLoop = Simulink.Signal;
EnClosedLoop.DataType = 'boolean';
EnClosedLoop.Dimensions = 1;
EnClosedLoop.Complexity = 'real';
EnClosedLoop.InitialValue = '0';

% Create structure to send commands from top model to referenced model
clear CommandsStruct
CommandsStruct.SpeedRef = cast(0,dataType);
CommandsStruct.Enable      = boolean(0);

tmp_BusName = Simulink.Bus.createObject(CommandsStruct);
tmp_Bus = evalin('base',tmp_BusName.busName);
evalin('base',['clear ' tmp_BusName.busName]);
assignin('base','CommandsStruct',tmp_Bus);
clear tmp_BusName tmp_Bus

% Create parameter structure
PI_params_tmp = PI_params;
PI_params_tmp.Kp_i = cast(PI_params.Kp_i, dataType);
PI_params_tmp.Ki_i = cast(PI_params.Ki_i, dataType);
PI_params_tmp.Kp_speed = cast(PI_params.Kp_speed, dataType);
PI_params_tmp.Ki_speed = cast(PI_params.Ki_speed, dataType);
PI_params = PI_params_tmp;

tmp_P = Simulink.Parameter;
tmp_P.Value=PI_params;
tmp_P.RTWInfo.StorageClass='ExportedGlobal';
PI_params = tmp_P;
clear tmp_P