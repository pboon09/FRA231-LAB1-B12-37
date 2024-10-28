Voltage_Percentage_Linear_A = [];
Voltage_Linear_A = [];
Voltage_Percentage_Linear_B = [];
Voltage_Linear_B = [];
Voltage_Percentage_Rotary_A = [];
Voltage_Rotary_A = [];
Voltage_Percentage_Rotary_B = [];
Voltage_Rotary_B = [];
Voltage_Percentage_Rotary_C = [];
Voltage_Rotary_C = [];

for i = 1:11
    rms_value = sqrt(mean(data{i}{1}.Values.Data.^2));
    percentage = (rms_value / 3.3) * 100;
    Voltage_Percentage_Linear_A = [Voltage_Percentage_Linear_A, percentage];
    Voltage_Linear_A = [Voltage_Linear_A, rms_value];
    Voltage_Percentage_Linear_B = [Voltage_Percentage_Linear_B, percentage];
    Voltage_Linear_B = [Voltage_Linear_B, rms_value];
    Voltage_Percentage_Rotary_A = [Voltage_Percentage_Rotary_A, percentage];
    Voltage_Rotary_A = [Voltage_Rotary_A, rms_value];
    Voltage_Percentage_Rotary_B = [Voltage_Percentage_Rotary_B, percentage];
    Voltage_Rotary_B = [Voltage_Rotary_B, rms_value];
    Voltage_Percentage_Rotary_C = [Voltage_Percentage_Rotary_C, percentage];
    Voltage_Rotary_C = [Voltage_Rotary_C, rms_value];
end

Rotational_Travel_real = linspace(0,100,11);