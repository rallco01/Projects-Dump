package com.example.recyclerview;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.AlertDialog;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.media.AudioAttributes;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    ArrayList<Counter> counters = new ArrayList();

    RecyclerView recyclerView;
    LinearLayoutManager layoutManager;

    CounterRecyclerViewAdapter adapter;

    private Thread thread;
    int notificationId;

    private Button newTimerButton, confirmButton, cancelButton;
    private EditText nameEditText, minuteEditText, secondEditText;

    private AlertDialog.Builder dialogBuilder;
    private AlertDialog dialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setHasFixedSize(true);

        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        adapter = new CounterRecyclerViewAdapter(counters);
        recyclerView.setAdapter(adapter);

        createNotificationChannel();

        thread = new Thread() {
            @Override
            public void run() {
                try {
                    while (!thread.isInterrupted()) {
                        Thread.sleep(1000);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                // update TextView here!
                                adapter.notifyDataSetChanged();
                                ArrayList<Counter> completed = adapter.checkCompletedTimers();
                                if(!completed.isEmpty()){
                                    notifyCompleted(completed);
                                }

                            }
                        });
                    }
                } catch (InterruptedException e) {
                }
            }
        };
        thread.start();

        newTimerButton = findViewById(R.id.newTimerButton);
        newTimerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                createNewTimerDialog();
            }
        });
    }

    public void notifyCompleted(ArrayList<Counter> completed){
        String completedString = "";
        for (Counter counter:completed) {
            completedString += counter.getName() + "   ";
        }
        NotificationCompat.Builder builder = new NotificationCompat.Builder(this, "Multiple Timers")
                .setSmallIcon(R.drawable.notification_icon)
                .setContentTitle("Timer/s finished! The following timer/s have finished")
                .setContentText(completedString)
                .setPriority(NotificationCompat.PRIORITY_HIGH);
                //.setSound(Uri.parse("android.resource://" + this.getPackageName() + "/" + R.raw.notification_tone));

        Notification notification = builder.build();
        //notification.sound = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);

        NotificationManagerCompat notificationManager = NotificationManagerCompat.from(this);
        notificationManager.notify(++notificationId, notification);
        //notificationManager.notify(++notificationId, builder.build());
    }

    private void createNotificationChannel() {
        // Create the NotificationChannel, but only on API 26+ because
        // the NotificationChannel class is new and not in the support library
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            CharSequence name = "Multiple Timers";
            String description = "Multiple Timers";
            int importance = NotificationManager.IMPORTANCE_DEFAULT;
            NotificationChannel channel = new NotificationChannel("Multiple Timers", name, importance);
            channel.setDescription(description);
            channel.setSound(Uri.parse("android.resource://" + this.getPackageName() + "/" + R.raw.notification_tone), new AudioAttributes.Builder().setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION).setUsage(AudioAttributes.USAGE_ALARM).build());
            // Register the channel with the system; you can't change the importance
            // or other notification behaviors after this
            NotificationManager notificationManager = getSystemService(NotificationManager.class);
            notificationManager.createNotificationChannel(channel);
        }
    }

    public void createNewTimerDialog() {
        dialogBuilder = new AlertDialog.Builder(this);
        final View timerPopupView = getLayoutInflater().inflate(R.layout.new_timer_popup, null);

        nameEditText = timerPopupView.findViewById(R.id.TimerNameEditText);
        minuteEditText = timerPopupView.findViewById(R.id.TimerMinuteEditText);
        secondEditText = timerPopupView.findViewById(R.id.TimerSecondEditText);

        confirmButton = timerPopupView.findViewById(R.id.confirmButton);
        cancelButton = timerPopupView.findViewById(R.id.cancelButton);

        dialogBuilder.setView(timerPopupView);
        dialog = dialogBuilder.create();
        dialog.show();

        confirmButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //TODO: input checking
                String name = nameEditText.getText().toString();
                String minutes = minuteEditText.getText().toString();
                String seconds = secondEditText.getText().toString();

                Counter counter = new Counter(name, Integer.parseInt(minutes), Integer.parseInt(seconds));
                counters.add(counter);

                adapter.notifyDataSetChanged();
                dialog.dismiss();
            }
        });
        cancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                dialog.dismiss();
            }
        });
    }
}