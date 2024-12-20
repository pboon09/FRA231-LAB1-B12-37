function [fitresult, gof] = createFit(distance, voltage_NNS)
%CREATEFIT(DISTANCE,voltage_NNS)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input: distance
%      Y Output: voltage_NNS
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  See also FIT, CFIT, SFIT.

%  Auto-generated by MATLAB on 08-Oct-2024 19:12:07


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( distance, voltage_NNS );

% Set up fittype and options.
ft = fittype( 'smoothingspline' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'Line of Best Fit' );
h = plot( fitresult, xData, yData );
legend( h, 'Voltage of North No Sheild vs Distance', 'Line of Best Fit', 'Location', 'NorthWest', 'Interpreter', 'none' );
% Label axes
xlabel( 'Distance (mm.)', 'Interpreter', 'none' );
ylabel( 'Voltage (V)', 'Interpreter', 'none' );
title('North No Sheild');
grid on


