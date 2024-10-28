% --- Plot 1: Voltage Percentage Rotary A ---
figure;
plot(Rotational_Travel, Voltage_Percentage_Rotary_A, 'ko-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Rotary Type A (PDB181-K420ko-103A2)');
xlim([0 100]);
ylim([0 100]);
legend('Voltage Percentage Rotary A', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

% --- Plot 2: Voltage Percentage Rotary B ---
figure;
plot(Rotational_Travel, Voltage_Percentage_Rotary_B, 'ko-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Rotary Type B (PDB181-K420ko-103B)');
xlim([0 100]);
ylim([0 100]);
legend('Voltage Percentage Rotary B', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

% --- Plot 3: Voltage Percentage Rotary C ---
figure;
plot(Rotational_Travel, Voltage_Percentage_Rotary_C, 'ko-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Rotary Type C (PDB181-K420ko-103C)');
xlim([0 100]);
ylim([0 100]);
legend('Voltage Percentage Rotary C', 'Location', 'NorthEast');
set(gca, 'FontSize', 12);

% --- Plot 4: Voltage Percentage Linear A ---
figure;
plot(Rotational_Travel, Voltage_Percentage_Linear_A, 'ko-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Linear Type A (PTA6043-2015DPA103)');
xlim([0 100]);
ylim([0 100]);
legend('Voltage Percentage Linear A', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

% --- Plot 5: Voltage Percentage Linear B ---
figure;
plot(Rotational_Travel, Voltage_Percentage_Linear_B, 'ko-', 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b', 'LineWidth', 1); % Black line, blue dots
grid on;
xlabel('Rotational Travel (%)');
ylabel('Voltage Gain (%)');
title('Linear Type B (PTA6043-2015DPB103)');
xlim([0 100]);
ylim([0 100]);
legend('Voltage Percentage Linear B', 'Location', 'NorthWest');
set(gca, 'FontSize', 12);

