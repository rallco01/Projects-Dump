package com.example.recyclerview;


import androidx.recyclerview.widget.RecyclerView;

import java.util.Timer;
import java.util.TimerTask;

public class Counter {
    private String name;

    private int min;
    private int sec;

    private boolean complete;
    private boolean counting;

    Timer timer;
    TimerTask task;

    public Counter(){
        complete = false;
        counting = false;

        timer = new Timer();
        task = new TimerTask() {
            @Override
            public void run() {
                countDown();
            }
        };
    }
    public Counter(String name, int min, int sec){
        this.name = name;
        this.min = min;
        this.sec = sec;
        complete = false;
        counting = false;

        timer = new Timer();
        task = new TimerTask() {
            @Override
            public void run() {
                countDown();
            }
        };
    }

    public void setMin(int min) {
        this.min = min;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setSec(int sec) {
        this.sec = sec;
    }
    public int getMin(){
        return min;
    }
    public String getName(){
        return name;
    }
    public int getSec(){
        return sec;
    }
    public boolean isComplete() {
        return complete;
    }

    public void countDown(){
        if(!complete) {
            if (this.sec == 0) {
                if (this.min == 0) {
                    this.complete = true;
                } else {
                    this.min--;
                    this.sec = 59;
                }
            } else {
                this.sec--;
            }
        }
    }

    public void start(){
        if(!counting) {
            timer.scheduleAtFixedRate(task, 0, 1000);
            counting = true;
        }

    }

    public void clearTimer() {
        task.cancel();
        timer.purge();
    }

    @Override
    public String toString() {
        return String.format("%02d", min) + ":" + String.format("%02d", sec);
    }

}
