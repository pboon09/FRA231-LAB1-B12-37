signal_pairs = { {'qei_pos_x1', 'qei_vel_x1'}, {'qei_pos_x2', 'qei_vel_x2'}, {'qei_pos_x4', 'qei_vel_x4'}, ...
                 {'polling_pos_x1', 'polling_vel_x1'}, {'polling_pos_x2', 'polling_vel_x2'}, {'polling_pos_x4', 'polling_vel_x4'} };

encoder_types = {'amt', 'BOURNS'};
revolution = 5;

subplot_rows = 2;
subplot_cols = 3;

for enc_idx = 1:length(encoder_types)
    encoder = encoder_types{enc_idx};

    figure;

    for pair_idx = 1:length(signal_pairs)
        pos_signal_name = signal_pairs{pair_idx}{1};
        vel_signal_name = signal_pairs{pair_idx}{2};

        dataset_name = sprintf('%s_%drev', encoder, revolution);
        dataset = evalin('base', dataset_name);
        run_data = dataset{1};

        pos_element = run_data.getElement(pos_signal_name);
        vel_element = run_data.getElement(vel_signal_name);

        time_data = pos_element.Values.Time;
        pos_data = pos_element.Values.Data;
        vel_data = vel_element.Values.Data;

        subplot(subplot_rows, subplot_cols, pair_idx);

        plot(time_data, pos_data, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(time_data, vel_data, 'r-', 'LineWidth', 1.5);
        hold off;

        title(sprintf('%s 5rev %s', upper(encoder), strrep(pos_signal_name, '_', '\_')));

        if contains(pos_signal_name, 'polling')
            legend({'Position Data', 'Velocity Data'}, 'Location', 'northeast');
        else
            legend({'Position Data', 'Velocity Data'}, 'Location', 'northwest');
        end

        grid on;
        xlabel('Time (s)');
        ylabel('Position / Velocity');
        set(gca, 'FontSize', 12);
    end

    sgtitle(sprintf('%s 5th Revolution QEI and Polling X1, X2, X4', upper(encoder)));
end
