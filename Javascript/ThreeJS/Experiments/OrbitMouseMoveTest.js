/*
document.addEventListener('mousemove', function(e){
    let scale = -0.01;
    orbit.rotateY( e.movementX * scale );
    orbit.rotateX( e.movementY * scale ); 
    orbit.rotation.z = 0; //this is important to keep the camera level..
})
    
//the camera rotation pivot
orbit = new THREE.Object3D();
orbit.rotation.order = "YXZ"; //this is important to keep level, so Z should be the last axis to rotate in order...
orbit.position.copy( mesh.position );
scene.add(orbit );

//offset the camera and add it to the pivot
//you could adapt the code so that you can 'zoom' by changing the z value in camera.position in a mousewheel event..
let cameraDistance = 1;
camera.position.z = cameraDistance;
orbit.add( camera );
*/

import './style.css';

import * as THREE from 'three';
import { MTLLoader } from 'three/addons/loaders/MTLLoader.js';
import { OBJLoader } from 'three/addons/loaders/OBJLoader.js';

import {OrbitControls} from "https://cdn.jsdelivr.net/npm/three@0.127.0/examples/jsm/controls/OrbitControls.js";
import { RGBA_ASTC_10x10_Format } from 'three';


console.clear()

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)
const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0xD3C7C1, 1);

camera.position.setZ(0);
camera.position.setY(-5);

renderer.render(scene, camera);

//let controls = new OrbitControls(camera, renderer.domElement);

const mtlLoader = new MTLLoader();

const objects = [];
for(let i = -5; i<=5; i++) {
    for(let j = -5; j <=5; j++) {
        mtlLoader.load( "ComputerPurple.mtl", function( materials ) {

            materials.preload();
            let objLoader = new OBJLoader();
            objLoader.setMaterials( materials );
            objLoader.load( 'Computer.obj', function ( object ) {

                objects.push(object);
                object.position.set(i*2.1, j*2.5, 0)

              scene.add(object);

            } );

        });
    }
}

const pointLight = new THREE.PointLight(0xffffff)
pointLight.position.set(30, 10, 10)

const ambientLight = new THREE.AmbientLight(0xffffff)

scene.add(pointLight, ambientLight);

document.addEventListener('mousemove', function(e){
    let sensitivity = -0.00025;
    orbit.rotateY( e.movementX * sensitivity );
    orbit.rotateX( e.movementY * sensitivity ); 
    orbit.rotation.z = 0; //this is important to keep the camera level..
})
    
//the camera rotation pivot
let orbit = new THREE.Object3D();
orbit.rotation.order = "YXZ"; //this is important to keep level, so Z should be the last axis to rotate in order...
orbit.position.set( camera.position );
scene.add(orbit );

//offset the camera and add it to the pivot
//you could adapt the code so that you can 'zoom' by changing the z value in camera.position in a mousewheel event..
let cameraDistance = 10;
camera.position.z = cameraDistance;
orbit.add( camera );

console.log(scene);

function animate() {
  requestAnimationFrame(animate);
  renderer.render(scene, camera);
}
animate();