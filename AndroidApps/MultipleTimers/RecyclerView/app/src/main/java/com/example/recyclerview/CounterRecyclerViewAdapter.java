package com.example.recyclerview;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.core.app.NotificationCompat;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class CounterRecyclerViewAdapter extends RecyclerView.Adapter<CounterRecyclerViewAdapter.CounterViewHolder> {

    ArrayList<Counter> counters;

    public CounterRecyclerViewAdapter(ArrayList<Counter> counters) {
        this.counters = counters;
    }

    @NonNull
    @Override
    public CounterViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.counter_row_item, parent, false);
        CounterViewHolder counterViewHolder = new CounterViewHolder(view);

        return counterViewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull CounterViewHolder holder, int position) {
        Counter counter = counters.get(position);
        holder.nameText.setText(counter.getName());
        holder.countDownText.setText(counter.toString());

        holder.startButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                counter.start();
            }
        });

        holder.deleteButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                counter.clearTimer();
                counters.remove(counter);
                notifyDataSetChanged();
            }
        });
    }

    @Override
    public int getItemCount() {
        return this.counters.size();
    }

    public ArrayList<Counter> checkCompletedTimers() {

        ArrayList<Counter> completed = new ArrayList();

        for (Counter counter:counters) {
            if(counter.isComplete()){
                completed.add(counter);
            }
        }

        for(Counter counter:completed){
            counters.remove(counter);
        }

        return completed;
    }

    public static class CounterViewHolder extends RecyclerView.ViewHolder{
        TextView nameText;
        TextView countDownText;
        Button startButton;
        Button deleteButton;

        public CounterViewHolder (@NonNull View itemView) {
            super(itemView);
            nameText = itemView.findViewById(R.id.nameText);
            countDownText = itemView.findViewById(R.id.countDownText);
            startButton = itemView.findViewById(R.id.startButton);
            deleteButton = itemView.findViewById(R.id.deleteButton);
        }
    }
}
