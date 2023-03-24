import './style.css';

import * as THREE from 'three';
import { MTLLoader } from 'three/addons/loaders/MTLLoader.js';
import { OBJLoader } from 'three/addons/loaders/OBJLoader.js';

import {OrbitControls} from "https://cdn.jsdelivr.net/npm/three@0.127.0/examples/jsm/controls/OrbitControls.js";


console.clear()

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)
const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0xD3C7C1, 1);

camera.position.setZ(5);
camera.position.setY(5);

renderer.render(scene, camera);

let controls = new OrbitControls(camera, renderer.domElement);

const mtlLoader = new MTLLoader();

mtlLoader.load( "Computer.mtl", function( materials ) {

    materials.preload();
    let objLoader = new OBJLoader();
    objLoader.setMaterials( materials );
    objLoader.load( 'Computer.obj', function ( object ) {
      
        object.position.set(0, 0, 0)

      scene.add(object);

    } );

});

const pointLight = new THREE.PointLight(0xffffff)
pointLight.position.set(30, 10, 10)

const ambientLight = new THREE.AmbientLight(0xffffff)

scene.add(pointLight, ambientLight);

function animate() {
    requestAnimationFrame(animate);
    renderer.render(scene, camera);
  }

  animate();