signal_names = { 'qei_pos_x1', 'qei_vel_x1', 'qei_pos_x2', 'qei_vel_x2', ...
                 'qei_pos_x4', 'qei_vel_x4', 'polling_pos_x1', 'polling_vel_x1', ...
                 'polling_pos_x2', 'polling_vel_x2', 'polling_pos_x4', 'polling_vel_x4' };

encoder_types = {'amt', 'BOURNS'};
revolutions = 1:5;

for enc_idx = 1:length(encoder_types)
    encoder = encoder_types{enc_idx};

    for rev = revolutions
        dataset_name = sprintf('%s_%drev', encoder, rev);
        dataset = evalin('base', dataset_name);

        for sig_idx = 1:length(signal_names)
            signal_name = signal_names{sig_idx};

            largest_values = zeros(1, 5);
            for run_idx = 1:5
                run_data = dataset{run_idx};
                signal_element = run_data.getElement(signal_name);
                signal_data = signal_element.Values.Data;
                largest_values(run_idx) = max(signal_data);
            end

            result_array_name = sprintf('%s_%drev_%s', encoder, rev, signal_name);
            assignin('base', result_array_name, largest_values);
        end
    end
end
