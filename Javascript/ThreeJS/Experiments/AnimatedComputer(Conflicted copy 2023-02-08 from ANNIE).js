import './style.css';

import * as THREE from 'three';
import {OrbitControls} from "https://cdn.jsdelivr.net/npm/three@0.127.0/examples/jsm/controls/OrbitControls.js";

let cameraRotation = 0;
let cameraDistance = 35;

let endAngle = 90
const animSpeed = 0.1

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)
const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0xD3C7C1, 1);

camera.position.setZ(cameraDistance);
camera.position.setX(0.1);
camera.rotateZ(cameraRotation);

// Scene Lighting
const pointLight1 = new THREE.PointLight(0xffffff)
pointLight1.position.set(30, 40, 10)

const pointLight2 = new THREE.PointLight(0xffffff)
pointLight2.position.set(-30, -40, -10)

const ambientLight = new THREE.AmbientLight(0xffffff, 0.2)

scene.add(pointLight1);
scene.add(pointLight2);
scene.add(ambientLight);

renderer.render(scene, camera);

let controls = new OrbitControls(camera, renderer.domElement);

function createSegmentGeom(radius, angleStart, angleEnd, color) {
    var extrOpt = {
    curveSegments: 32,
    steps: 1,
    amount: 0.1,
    bevelEnabled: false,
  };

  var Shape = new THREE.Shape();
  Shape.moveTo(0, 0);
  Shape.absarc(0, 0, radius, angleStart, angleEnd, false);
  Shape.lineTo(0, 0);

  var SegmentGeom = new THREE.ExtrudeGeometry( Shape, extrOpt );
  SegmentGeom.rotateX(-Math.PI / 2);
  var SegmentMat = new THREE.MeshLambertMaterial({
    color: color
  });
  var Segment = new THREE.Mesh(SegmentGeom, SegmentMat);
    return SegmentGeom;
}

const color = new THREE.Color(0xa2c1e0);

let time = 0;

let cylinGeom = createSegmentGeom(5, 0, Math.sin(0), color);
let cylin = new THREE.Mesh(cylinGeom, new THREE.MeshStandardMaterial({
    color: color,
    wireframe: false
}));

scene.add(cylin);

function animate() {
    requestAnimationFrame(animate);

    scene.remove(cylin)

    time += 0.1;
    let a = (animSpeed)*time;

    endAngle += animSpeed;
    cylinGeom = createSegmentGeom(5, Math.sin(a)-2, -Math.sin(a)+2, color);
    cylin = new THREE.Mesh(cylinGeom, new THREE.MeshStandardMaterial({
        color: color,
        wireframe: false
    }));

    //cylin.rotation.set(30, 30, 0)

    scene.add(cylin);
  
    renderer.render(scene, camera);
  }
  
  animate();