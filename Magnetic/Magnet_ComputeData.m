voltage_NNS = [];
voltage_SNS = [];
voltage_NS = [];
voltage_SS = [];

for i = 1:10
    rms_value = sqrt(mean(data{i}{1}.Values.Data.^2));
    voltage_NNS = [voltage_NNS, rms_value];
    voltage_SNS = [voltage_SNS, rms_value];
    voltage_NS = [voltage_NS, rms_value];
    voltage_SS = [voltage_SS, rms_value];
end

distance = linspace(0,35,10);