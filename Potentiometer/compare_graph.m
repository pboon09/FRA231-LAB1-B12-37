% --- Compare Rotary A ---
figure;
errorbar(Rotational_Travel, voltage_per_rotaryA_data, error_rotaryA, 'r', 'LineWidth', 1);
hold on;
plot(Rotational_Travel, voltage_per_rotaryA_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1);
plot(Rotational_Travel_real, Voltage_Percentage_Rotary_A, 'go-', 'LineWidth', 1);
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Comparison: Rotary Type A');
xlim([0 100]);
ylim([0 120]);
legend('Error Bound', "Datasheet", 'Actual Measurement', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

% --- Compare Rotary B ---
figure;
errorbar(Rotational_Travel, voltage_per_rotaryB_data, error_rotaryB, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_rotaryB_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1);
plot(Rotational_Travel, Voltage_Percentage_Rotary_B, 'go-', 'LineWidth', 1); % Green dashed line
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Comparison: Rotary Type B');
xlim([0 100]);
ylim([0 120]);
legend('Error Bound', "Datasheet", 'Actual Measurement', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

% --- Compare Rotary C ---
figure;
errorbar(Rotational_Travel, voltage_per_rotaryC_data, error_rotaryC, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_rotaryC_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1);
plot(Rotational_Travel, Voltage_Percentage_Rotary_C, 'go-', 'LineWidth', 1); % Green dashed line
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Comparison: Rotary Type C');
xlim([0 100]);
ylim([0 120]);
legend('Error Bound', "Datasheet", 'Actual Measurement', 'Location', 'NorthEast');
set(gca, 'FontSize', 12);

% --- Compare Linear A ---
figure;
errorbar(Rotational_Travel, voltage_per_linearA_data, error_linearA, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_linearA_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1);
plot(Rotational_Travel, Voltage_Percentage_Linear_A, 'go-', 'LineWidth', 1); % Green dashed line
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Comparison: Linear Type A');
xlim([0 100]);
ylim([0 120]);
legend('Error Bound', "Datasheet", 'Actual Measurement', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

% --- Compare Linear B ---
figure;
errorbar(Rotational_Travel, voltage_per_linearB_data, error_linearB, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_linearB_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1);
plot(Rotational_Travel, Voltage_Percentage_Linear_B, 'go-', 'LineWidth', 1); % Green dashed line
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Comparison: Linear Type B');
xlim([0 100]);
ylim([0 120]);
legend('Error Bound', "Datasheet", 'Actual Measurement', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);
