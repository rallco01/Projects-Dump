console.clear();

import * as THREE from "https://cdn.jsdelivr.net/npm/three@0.127.0/build/three.module.js";
import {OrbitControls} from "https://cdn.jsdelivr.net/npm/three@0.127.0/examples/jsm/controls/OrbitControls.js";

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)

const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);

camera.position.setZ(50);
camera.position.setY(50);

renderer.render(scene, camera);

let controls = new OrbitControls(camera, renderer.domElement);

let light = new THREE.PointLight();
scene.add(light, new THREE.AmbientLight(0xffffff, 0.5));

//scene.add(new THREE.GridHelper(10, 10));

let g = new THREE.SphereGeometry(1, 32, 16); // the same geometry for re-use
const color1 = new THREE.Color(0xf7665e);
const color2 = new THREE.Color(0xa2c1e0);

let spheres = [];
let spheresCount = 200;
for (let i = 0; i < spheresCount; i++) {
  let color = color1.lerp(color2, THREE.MathUtils.randFloat(0, 100)/100)
  addSphere(color);
}
let t = 0;

renderer.setAnimationLoop(_ => {
  //t += 0.001;
  spheres.forEach(s => {
    let ud = s.userData;
    let a = (ud.speed * t) + ud.phase;
    s.position.set(Math.cos(a), 0, -Math.sin(a))
      .multiplyScalar(ud.radius)
      .setY(Math.sin(a*(ud.phase/2)) * ud.orbitAngle);
  });
  renderer.render(scene, camera);
})

function addSphere(color) {
  let s = new THREE.Mesh(g, new THREE.MeshStandardMaterial({
    color: color,
    wireframe: false
  }));
  s.scale.setScalar(THREE.MathUtils.randFloat(0.1, 0.5)); // sise of a sphere
  s.userData = {
    posY: THREE.MathUtils.randFloat(-10, 10), // at what height
    radius: THREE.MathUtils.randFloat(0.5, window.innerWidth/32), // how far from Y-axis
    phase: Math.random() * Math.PI * 2, // where to start
    speed: (0.1 - Math.random() * 0.2) * Math.PI, // how fast to circulate
    orbitAngle: THREE.MathUtils.randFloat(-5, 5),
  };
  spheres.push(s);
  scene.add(s);
}



function scrollAnimate() {
  const t2 = document.body.getBoundingClientRect().top;

  t = t2 * -0.01
}

document.body.onscroll = scrollAnimate;

