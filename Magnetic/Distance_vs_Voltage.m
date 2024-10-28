figure;
plot(distance-35, voltage_NNS, 'b-o', ...
     distance-35, voltage_NS, 'r-*', ...
     distance, flip(voltage_SNS), 'b-o', ...
     distance, flip(voltage_SS), 'r-*');
xlabel('Distance (mm)', 'Interpreter', 'none');
ylabel('Voltage (V)', 'Interpreter', 'none');
title('Comparison of Voltage vs Distance for North and South With Shield and North and South No Shield');
legend('North and South No Shield', 'North and South With Shield', 'Location', 'NorthWest');
grid on;
xticklabels({'0', '5' ,'15', '25', '35', '25', '15', '5', '0'});

