volt = zeros(1, 9);    
kg_sc = zeros(1, 9);   
kg_b_sc = zeros(1, 9); 

for i = 1:8
    run_data = data{i};
    
    kg_b_sc_data = run_data.getElement(1).Values.Data; 
    volt_data = run_data.getElement(2).Values.Data;    
    kg_sc_data = run_data.getElement(3).Values.Data;   
    
    kg_b_sc(i) = mean(kg_b_sc_data);
    volt(i) = mean(volt_data);
    kg_sc(i) = mean(kg_sc_data);
end

kg_b_sc = [kg_b_sc(end), kg_b_sc(1:end-1)]; 
volt = [volt(end), volt(1:end-1)];          
kg_sc = [kg_sc(end), kg_sc(1:end-1)];       

real = [0.0, 3.69, 7.26, 7.75, 8.24, 8.69, 9.19, 9.69, 10.18];

% Plot kg_b_sc vs real
figure;
p1 = plot(real, kg_b_sc, 'b-', 'LineWidth', 1);  % Blue line
hold on;
p2 = plot(real, kg_b_sc, 'ko', 'MarkerSize', 6, 'MarkerFaceColor', 'k');  % Black dots
hold off;
legend(p2, 'Weight Before Signal Conditioning', 'Location', 'northwest');
xlabel('Weight measured by Digital Meter');
ylabel('Weight measured from Load Cell');
title('Digital Meter vs Weight Before Signal Conditioning');
grid on;

% Plot volt vs real
figure;
p3 = plot(real, volt, 'b-', 'LineWidth', 1);  % Blue line
hold on;
p4 = plot(real, volt, 'ko', 'MarkerSize', 6, 'MarkerFaceColor', 'k');  % Black dots
hold off;
legend(p4, 'Voltage', 'Location', 'northwest');
xlabel('Weight measured by Digital Meter');
ylabel('Voltage');
title('Digital Meter vs Voltage');
grid on;

% Plot kg_sc vs real
figure;
p5 = plot(real, kg_sc, 'b-', 'LineWidth', 1);  % Blue line
hold on;
p6 = plot(real, kg_sc, 'ko', 'MarkerSize', 6, 'MarkerFaceColor', 'k');  % Black dots
hold off;
legend(p6, 'Weight After Signal Conditioning', 'Location', 'northwest');
xlabel('Weight measured by Digital Meter');
ylabel('Weight measured from Load Cell');
title('Digital Meter vs Weight After Signal Conditioning');
grid on;

% Plot kg_sc and kg_b_sc vs real
figure;
p1 = plot(real, kg_sc, 'b-', 'LineWidth', 1);  % Blue line for kg_sc
hold on;
p2 = plot(real, kg_sc, 'ko', 'MarkerSize', 6, 'MarkerFaceColor', 'k');  % Black dots for kg_sc

p3 = plot(real, kg_b_sc, 'r-', 'LineWidth', 1);  % Red line for kg_b_sc
p4 = plot(real, kg_b_sc, 'mo', 'MarkerSize', 6, 'MarkerFaceColor', 'm');  % Magenta dots for kg_b_sc
hold off;

% Add legend for both lines and dots
legend([p2, p4], 'Weight After Signal Conditioning', 'Weight Before Signal Conditioning', 'Location', 'northwest');
xlabel('Weight measured by Digital Meter');
ylabel('Weight measured from Load Cell');
title('Real vs Weight (Before and After Signal Conditioning)');
grid on;
