function [fitresult1, gof1, fitresult2, gof2] = createCombinedFitNorth(distance, voltage_NNS, voltage_NS)
%CREATECOMBINEDFITNORTH(DISTANCE,voltage_NNS,voltage_NS)
%  Create two fits and plot them on the same graph.
%
%  Data for 'untitled fit 1' fit:
%      X Input: distance
%      Y Output 1: voltage_NNS (North No Shield)
%      Y Output 2: voltage_NS (North with Shield)
%  Output:
%      fitresult1 : a fit object representing the first fit (North No Shield).
%      fitresult2 : a fit object representing the second fit (North with Shield).
%      gof1 : structure with goodness-of-fit info for the first fit.
%      gof2 : structure with goodness-of-fit info for the second fit.
%
%  See also FIT, CFIT, SFIT.

%  Auto-generated by MATLAB on 08-Oct-2024 19:20:00

%% Prepare data for fitting
[xData1, yData1] = prepareCurveData(distance, voltage_NNS);
[xData2, yData2] = prepareCurveData(distance, voltage_NS);

% Set up fittype and options for both fits
ft = fittype('smoothingspline');

% Fit model to data
[fitresult1, gof1] = fit(xData1, yData1, ft);
[fitresult2, gof2] = fit(xData2, yData2, ft);

figure('Name', 'Comparison of North No Shield and North with Shield');
hold on;

h1_data = plot(xData1, yData1, 'b*'); 
h2_data = plot(xData2, yData2, 'r*');

h1_fit = plot(fitresult1, 'b-'); 
h2_fit = plot(fitresult2, 'r-'); 

legend([h1_data, h2_data, h1_fit, h2_fit], ...
    {'North No Shield', 'North with Shield', 'Line of Best Fit - North No Shield', 'Line of Best Fit - North with Shield'}, ...
    'Location', 'NorthWest', 'Interpreter', 'none');

xlabel('Distance (mm)', 'Interpreter', 'none');
ylabel('Voltage (V)', 'Interpreter', 'none');
title('Comparison of Voltage vs Distance for North No Shield and North with Shield');
grid on;
hold off;

end
