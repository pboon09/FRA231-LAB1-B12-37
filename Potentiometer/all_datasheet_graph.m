Rotational_Travel = linspace(0, 100, 11);
voltage_per_rotaryA_data = [0, 0, 1.25, 3.20, 6.11, 9.74, 16.49, 32.38, 60.53, 90.12, 100];
voltage_per_rotaryB_data = [0, 5.14, 16.36, 27.57, 38.79, 49.84, 61.37, 72.12, 83.81, 94.86, 100];
voltage_per_rotaryC_data = [100, 85.11, 62.38, 38.09, 21.63, 14.73, 9.87, 5.48, 2.19, 0.31, 0];
voltage_per_linearA_data = [0, 1.24, 2.34, 5.62, 10.45, 15.29, 22.46, 39.94, 63.96, 90, 100];
voltage_per_linearB_data = [0, 0.64, 3.32, 11.62, 30.27, 48.90, 63.94, 78.83, 94.49, 98.88, 100];

error_rotaryA = 0.20 * voltage_per_rotaryA_data;
error_rotaryB = 0.20 * voltage_per_rotaryB_data;
error_rotaryC = 0.20 * voltage_per_rotaryC_data;
error_linearA = 0.20 * voltage_per_linearA_data;
error_linearB = 0.20 * voltage_per_linearB_data;

% --- Plot 1: Rotary A ---
figure;
errorbar(Rotational_Travel, voltage_per_rotaryA_data, error_rotaryA, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_rotaryA_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Rotary Type A (PDB181-K420K-103A2) in Datasheet with Error Bar');
xlim([0 100]);
ylim([0 120]);
set(gca, 'FontSize', 12);

% --- Plot 2: Rotary B ---
figure;
errorbar(Rotational_Travel, voltage_per_rotaryB_data, error_rotaryB, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_rotaryB_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Rotary Type B (PDB181-K420K-103B) in Datasheet with Error Bar');
xlim([0 100]);
ylim([0 120]);
set(gca, 'FontSize', 12);

% --- Plot 3: Rotary C ---
figure;
errorbar(Rotational_Travel, voltage_per_rotaryC_data, error_rotaryC, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_rotaryC_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Rotary Type C (PDB181-K420K-103C) in Datasheet with Error Bar');
xlim([0 100]);
ylim([0 120]);
set(gca, 'FontSize', 12);

% --- Plot 4: Linear A ---
figure;
errorbar(Rotational_Travel, voltage_per_linearA_data, error_linearA, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_linearA_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Linear Type A (PTA6043-2015DPA103)');
xlim([0 100]);
ylim([0 120]);
set(gca, 'FontSize', 12);

% --- Plot 5: Linear B ---
figure;
errorbar(Rotational_Travel, voltage_per_linearB_data, error_linearB, 'r', 'LineWidth', 1); % Red error bars
hold on;
plot(Rotational_Travel, voltage_per_linearB_data, 'k-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
hold off;
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Linear Type B (PTA6043-2015DPB103)');
xlim([0 100]);
ylim([0 120]);
set(gca, 'FontSize', 12);
