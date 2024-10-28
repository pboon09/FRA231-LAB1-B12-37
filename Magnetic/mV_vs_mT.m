mmvNNS = [];
mmvNS = [];
mmvSNS = [];
mmvSS = [];
for i = 1:10
    mmvNNS = [mmvNNS, voltage_NNS(i)/1e-3];
    mmvNS = [mmvNS, voltage_NS(i)/1e-3];
    mmvSNS = [mmvSNS, voltage_SNS(i)/1e-3];
    mmvSS = [mmvSS, voltage_SS(i)/1e-3];
end

tesla_NNS = [];
tesla_NS = [];
tesla_SNS = [];
tesla_SS = [];
for i = 1:10
    tesla_NNS = [tesla_NNS, (mmvNNS(i)-1650)/30];
    tesla_NS = [tesla_NS (mmvNS(i)-1650)/30];
    tesla_SNS = [tesla_SNS, (mmvSNS(i)-1650)/30];
    tesla_SS = [tesla_SS, (mmvSS(i)-1650)/30];
end
plot(tesla_NNS, mmvNNS, 'b-o', ...
     tesla_NS, mmvNS, 'r-*', ...
     tesla_SNS, (mmvSNS), 'b-o', ...
     tesla_SS, (mmvSS), 'r-*');
xlabel('milli-Tesla (mT)', 'Interpreter', 'none');
ylabel('milli-Volt (mV)', 'Interpreter', 'none');
title('Comparison of milli-Volt vs milli-Tesla for North and South With Shield and North and South No Shield');
legend('North and South No Shield', 'North and South With Shield', 'Location', 'NorthWest');
grid on;

