import { Application } from '@splinetool/runtime';

const canvas = document.getElementById('bg');

canvas.width  = window.innerWidth;
canvas.height = window.innerHeight;

const app = new Application(canvas);
app.load('https://prod.spline.design/whyPw1rh3MqtS-Su/scene.splinecode');
