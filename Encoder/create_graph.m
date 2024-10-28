pos_signals = { 'qei_pos_x1', 'qei_pos_x2', 'qei_pos_x4', ...
                'polling_pos_x1', 'polling_pos_x2', 'polling_pos_x4' };

encoder_types = {'amt', 'BOURNS'};
revolutions = 1:5;

means_qei_amt = zeros(3, 5);
means_polling_amt = zeros(3, 5);
means_qei_bourns = zeros(3, 5);
means_polling_bourns = zeros(3, 5);

for enc_idx = 1:length(encoder_types)
    encoder = encoder_types{enc_idx};

    for sig_idx = 1:6
        signal_name = pos_signals{sig_idx};

        for rev = revolutions
            array_name = sprintf('%s_%drev_%s', encoder, rev, signal_name);
            data_array = evalin('base', array_name);
            array_mean = mean(data_array);

            if strcmp(encoder, 'amt') && contains(signal_name, 'qei')
                means_qei_amt(sig_idx, rev) = array_mean;
            elseif strcmp(encoder, 'amt') && contains(signal_name, 'polling')
                means_polling_amt(sig_idx-3, rev) = array_mean;
            elseif strcmp(encoder, 'BOURNS') && contains(signal_name, 'qei')
                means_qei_bourns(sig_idx, rev) = array_mean;
            elseif strcmp(encoder, 'BOURNS') && contains(signal_name, 'polling')
                means_polling_bourns(sig_idx-3, rev) = array_mean;
            end
        end
    end
end

x_axis = 1:5;
text_font_size = 12;

figure;
for i = 1:3
    subplot(2, 3, i);
    plot(x_axis, means_qei_amt(i,:), 'bo', 'MarkerSize', 10, 'MarkerFaceColor', 'b');

    if i == 3
        title('AMT QEI pos\_X4');
    else
        title(['AMT QEI pos\_X', num2str(i)]);
    end
    xlabel('Revolution');
    ylabel('Mean Position');
    grid on;
    xlim([min(x_axis)-1, max(x_axis)+1]);
    ylim([min(means_qei_amt(i,:))-5, max(means_qei_amt(i,:))+5]);

    for j = 1:length(x_axis)
        text(x_axis(j), means_qei_amt(i,j), sprintf('%.2f', means_qei_amt(i,j)), ...
             'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'center', ...
             'FontSize', text_font_size);
    end
end

for i = 1:3
    subplot(2, 3, i+3);
    plot(x_axis, means_polling_amt(i,:), 'bo', 'MarkerSize', 10, 'MarkerFaceColor', 'b');

    if i == 3
        title('AMT Polling pos\_X4');
    else
        title(['AMT Polling pos\_X', num2str(i)]);
    end
    xlabel('Revolution');
    ylabel('Mean Position');
    grid on;
    xlim([min(x_axis)-1, max(x_axis)+1]);
    ylim([min(means_polling_amt(i,:))-5, max(means_polling_amt(i,:))+5]);

    for j = 1:length(x_axis)
        text(x_axis(j), means_polling_amt(i,j), sprintf('%.2f', means_polling_amt(i,j)), ...
             'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'center', ...
             'FontSize', text_font_size);
    end
end

figure;
for i = 1:3
    subplot(2, 3, i);
    plot(x_axis, means_qei_bourns(i,:), 'bo', 'MarkerSize', 10, 'MarkerFaceColor', 'b');

    if i == 3
        title('BOURNS QEI pos\_X4');
    else
        title(['BOURNS QEI pos\_X', num2str(i)]);
    end
    xlabel('Revolution');
    ylabel('Mean Position');
    grid on;
    xlim([min(x_axis)-1, max(x_axis)+1]);
    ylim([min(means_qei_bourns(i,:))-5, max(means_qei_bourns(i,:))+5]);

    for j = 1:length(x_axis)
        text(x_axis(j), means_qei_bourns(i,j), sprintf('%.2f', means_qei_bourns(i,j)), ...
             'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'center', ...
             'FontSize', text_font_size);
    end
end

for i = 1:3
    subplot(2, 3, i+3);
    plot(x_axis, means_polling_bourns(i,:), 'bo', 'MarkerSize', 10, 'MarkerFaceColor', 'b');

    if i == 3
        title('BOURNS Polling pos\_X4');
    else
        title(['BOURNS Polling pos\_X', num2str(i)]);
    end
    xlabel('Revolution');
    ylabel('Mean Position');
    grid on;
    xlim([min(x_axis)-1, max(x_axis)+1]);
    ylim([min(means_polling_bourns(i,:))-5, max(means_polling_bourns(i,:))+5]);

    for j = 1:length(x_axis)
        text(x_axis(j), means_polling_bourns(i,j), sprintf('%.2f', means_polling_bourns(i,j)), ...
             'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'center', ...
             'FontSize', text_font_size);
    end
end
